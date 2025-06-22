// Services/SaveBlobParser.cs
//
// Dragon Quest Monsters 3 save-blob parser / patcher
// ──────────────────────────────────────────────────────────────────
// • Works on the UTF-8 dump obtained after AES-decrypt + raw-Deflate
// • No full deserialisation: every editable field is located once,
//   its byte range recorded, then patched in-place when saving.
//
// Covered fields
//   – Season / Weather + timers
//   – Player (name, play-time, gold, etc.)
//   – Whole monster dictionary
//       _name, _kind, _level, _size, _exp
//       6 base stats (HP MP ATK DEF AGI WIS)
//       unspent skill points
//       up to 3 skills  (id + allocated points)
//   – Inventory item stacks
//
// All "big objects" (monster blocks, skills array) are cut with a brace
// counter → no fragile balancing-regex.
//
// ──────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;
using DQM3SaveEditor.Models;
using System.Diagnostics;

namespace DQM3SaveEditor.Services;

internal static class SaveBlobParser
{
    /*───────────────────────────────────────────────────────────────
     *  Flat, unique environment fields
     *──────────────────────────────────────────────────────────────*/
    private static readonly Regex SeasonRx  = new(
        @"_season\s*:\s*""?([^,\r\n}""\s]+)""?", RegexOptions.Singleline);
    private static readonly Regex WeatherRx = new(
        @"_weather\s*:\s*""?([^,\r\n}""\s]+)""?", RegexOptions.Singleline);
    private static readonly Regex SeasonTimerRx = new(
        @"seasonTimer\s*:\s*([\d.+\-Ee]+)(?=[,\r\n}])", RegexOptions.Singleline);
    private static readonly Regex WeatherTimerRx = new(
        @"weatherTimer\s*:\s*([\d.+\-Ee]+)(?=[,\r\n}])", RegexOptions.Singleline);

    /*───────────────────────────────────────────────────────────────
     *  Player
     *──────────────────────────────────────────────────────────────*/
    private static readonly Regex PlayerNameRx      = new(@"_playerName\s*:\s*""?([^,\r\n}""\s]+)""?", RegexOptions.Singleline);
    private static readonly Regex PlayTimeSecRx     = new(@"_playTimeSec\s*:\s*([\d.+\-Ee]+)",          RegexOptions.Singleline);
    private static readonly Regex GoldInPossessionRx= new(@"_goldInPossession\s*:\s*\{value:(\d+)",     RegexOptions.Singleline);
    private static readonly Regex GoldInBankRx      = new(@"_goldInBank\s*:\s*\{value:(\d+)",           RegexOptions.Singleline);
    private static readonly Regex TotalEarnedGoldRx = new(@"_totalEarnedGold\s*:\s*(\d+)",              RegexOptions.Singleline);
    private static readonly Regex CafePointRx       = new(@"_cafePoint\s*:\s*\{value:(\d+)",            RegexOptions.Singleline);

    /*───────────────────────────────────────────────────────────────
     *  Monster – small fields
     *──────────────────────────────────────────────────────────────*/
    private static readonly Regex M_NameRx    = new(@"_name\s*:\s*""?([^,""\r\n}]+)""?",      RegexOptions.Singleline);
    private static readonly Regex M_KindRx    = new(@"_kind\s*:\s*\{value:([^,}]+)",          RegexOptions.Singleline);
    private static readonly Regex M_LevelRx   = new(@"_level\s*:\s*\{value:(\d+)",            RegexOptions.Singleline);
    private static readonly Regex M_SizeRx    = new(@"_size\s*:\s*\{value:(\d+)",             RegexOptions.Singleline);
    private static readonly Regex M_UnspentRx = new(@"_unassignedSkillPoint.*?value:(\d+)",   RegexOptions.Singleline);
    private static readonly Regex M_ExpRx     = new(@"_exp\s*:\s*\{value:(\d+)",              RegexOptions.Singleline);

    /*───────────────────────────────────────────────────────────────
     *  Inventory
     *──────────────────────────────────────────────────────────────*/
    private static readonly Regex ItemRx = new(
        @"\{Key:([A-Za-z][A-Za-z0-9_]+),\s*Value:\{value:(\d{1,9}),",
        RegexOptions.Singleline);

    /*══════════════════════════════════════════════════════════════
     *  1.  PARSE
     *══════════════════════════════════════════════════════════════*/
    internal static SaveMeta Parse(string blob)
    {
        var meta = new SaveMeta();

        /*── environment ──*/
        CaptureToken (blob, SeasonRx,  "Season",        s => meta.Season        = s, meta);
        CaptureToken (blob, WeatherRx, "Weather",       s => meta.Weather       = s, meta);
        CaptureFloat (blob, SeasonTimerRx,  "SeasonTimer",  v => meta.SeasonTimer  = v, meta);
        CaptureFloat (blob, WeatherTimerRx, "WeatherTimer", v => meta.WeatherTimer = v, meta);

        /*── player ──*/
        CaptureToken (blob, PlayerNameRx,      "Player.Name",          v => meta.Player.Name                = v, meta);
        CaptureFloat (blob, PlayTimeSecRx,     "Player.PlayTimeSec",   v => meta.Player.PlayTimeSec         = v, meta);
        CaptureInt   (blob, GoldInPossessionRx,"Player.GoldInPoss",    v => meta.Player.GoldInPossession    = v, meta);
        CaptureInt   (blob, GoldInBankRx,      "Player.GoldInBank",    v => meta.Player.GoldInBank          = v, meta);
        CaptureInt   (blob, TotalEarnedGoldRx, "Player.TotalEarned",   v => meta.Player.TotalEarnedGold     = v, meta);
        CaptureInt   (blob, CafePointRx,       "Player.CafePoint",     v => meta.Player.CafePoint           = v, meta);

        /*── monsters zone ──*/
        int zoneIdx = blob.IndexOf("_monsters:{{", StringComparison.Ordinal);
        if (zoneIdx >= 0)
        {
            int zoneEnd = FindMatchingBraces(blob, zoneIdx + "_monsters:".Length);
            var zone    = blob.Substring(zoneIdx, zoneEnd - zoneIdx);
            int offset  = zoneIdx;

            foreach (var blk in ExtractMonsterBlocks(zone, offset))
            {
                var mon = new MonsterMeta {
                    Id = blk.Id,
                    Skills = new List<SkillMeta>(),
                    Stats = new StatBlock(0, 0, 0, 0, 0, 0, new EditableRange[6] {
                        new EditableRange(0,0), new EditableRange(0,0), new EditableRange(0,0),
                        new EditableRange(0,0), new EditableRange(0,0), new EditableRange(0,0)
                    })
                };

                /* simple fields */
                TryCapture(M_NameRx,   blk, (v,r)=>{mon.Name   = v; mon.NameRange   = r;},
                                        $"M.{mon.Id}.Name",   meta);
                TryCapture(M_KindRx,   blk, (v,r)=>{mon.Kind   = v; mon.KindRange   = r;},
                                        $"M.{mon.Id}.Kind",   meta);
                TryCapture(M_LevelRx,  blk, (v,r)=>{mon.Level  = int.Parse(v);
                                                     mon.LevelRange  = r;},
                                        $"M.{mon.Id}.Level",  meta);
                TryCapture(M_SizeRx,   blk, (v,r)=>{mon.Size   = int.Parse(v);
                                                     mon.SizeRange   = r;},
                                        $"M.{mon.Id}.Size",   meta);
                TryCapture(M_UnspentRx,blk, (v,r)=>{mon.UnspentPoints=int.Parse(v);
                                                     mon.UnspentRange = r;},
                                        $"M.{mon.Id}.Unspent",meta);
                TryCapture(M_ExpRx,    blk, (v,r)=>{mon.Exp    = long.Parse(v);
                                                     mon.ExpRange    = r;},
                                        $"M.{mon.Id}.Exp",    meta);

                /* stats */
                var st = TryParseStats(blk.Inner, blk.Start);
                if (st != null)
                {
                    mon.Stats = new StatBlock(st.Value.Raw[0], st.Value.Raw[1],
                                               st.Value.Raw[2], st.Value.Raw[3],
                                               st.Value.Raw[4], st.Value.Raw[5],
                                               st.Value.Ranges);

                    string[] nms = { "HP","MP","ATK","DEF","AGI","WIS" };
                    for(int j=0;j<6;j++)
                        meta.OffsetTracker.Add($"M.{mon.Id}.Stats.{nms[j]}", st.Value.Ranges[j]);
                }

                /* skills */
                foreach (var sk in ExtractSkills(blk.Inner, blk.Start))
                {
                    var skill = new SkillMeta
                    {
                        Index     = sk.Index,
                        Name      = sk.Id,
                        Allocated = sk.Points,
                        NameRange = sk.NameRange,
                        Range     = sk.PtsRange
                    };
                    mon.Skills.Add(skill);
                    meta.OffsetTracker.Add($"M.{mon.Id}.S{sk.Index}.Name", sk.NameRange);
                    meta.OffsetTracker.Add($"M.{mon.Id}.S{sk.Index}.Points", sk.PtsRange);
                }

                meta.Monsters.Add(mon);
            }
        }

        /*── inventory ──*/
        foreach (Match m in ItemRx.Matches(blob))
        {
            var range = new EditableRange(m.Groups[2].Index, m.Groups[2].Length);
            meta.Inventory.Add(new ItemMeta
            {
                Code  = m.Groups[1].Value,
                Count = long.Parse(m.Groups[2].Value),
                Range = range
            });
            meta.OffsetTracker.Add($"I.{m.Groups[1].Value}", range);
        }

        return meta;
    }

    /*══════════════════════════════════════════════════════════════
     *  2.  Patch (ApplyChanges)  – unchanged from previous version
     *══════════════════════════════════════════════════════════════*/

    internal static string ApplyChanges(string blob, SaveMeta meta)
    {
        var sb = new StringBuilder(blob);

        void P(string k,string v)=>Patch(sb,meta,k,v);

        /* env */
        P("Season",       meta.Season);
        P("Weather",      meta.Weather);
        P("SeasonTimer",  meta.SeasonTimer.ToString(CultureInfo.InvariantCulture));
        P("WeatherTimer", meta.WeatherTimer.ToString(CultureInfo.InvariantCulture));

        /* player */
        P("Player.Name",           meta.Player.Name);
        P("Player.PlayTimeSec",    meta.Player.PlayTimeSec.ToString(CultureInfo.InvariantCulture));
        P("Player.GoldInPoss",     meta.Player.GoldInPossession.ToString());
        P("Player.GoldInBank",     meta.Player.GoldInBank.ToString());
        P("Player.TotalEarned",    meta.Player.TotalEarnedGold.ToString());
        P("Player.CafePoint",      meta.Player.CafePoint.ToString());

        /* monsters */
        foreach (var m in meta.Monsters)
        {
            P($"M.{m.Id}.Name",    m.Name);
            P($"M.{m.Id}.Kind",    m.Kind);
            P($"M.{m.Id}.Level",   m.Level.ToString());
            P($"M.{m.Id}.Size",    m.Size.ToString());
            P($"M.{m.Id}.Unspent", m.UnspentPoints.ToString());
            P($"M.{m.Id}.Exp",     m.Exp.ToString());

            P($"M.{m.Id}.Stats.HP",  m.Stats.HP.ToString());
            P($"M.{m.Id}.Stats.MP",  m.Stats.MP.ToString());
            P($"M.{m.Id}.Stats.ATK", m.Stats.ATK.ToString());
            P($"M.{m.Id}.Stats.DEF", m.Stats.DEF.ToString());
            P($"M.{m.Id}.Stats.AGI", m.Stats.AGI.ToString());
            P($"M.{m.Id}.Stats.WIS", m.Stats.WIS.ToString());

            foreach (var sk in m.Skills)
            {
                P($"M.{m.Id}.S{sk.Index}.Name", sk.Name);
                P($"M.{m.Id}.S{sk.Index}.Points", sk.Allocated.ToString());
            }
        }

        /* inventory */
        foreach (var it in meta.Inventory)
            P($"I.{it.Code}", it.Count.ToString());

        return sb.ToString();
    }

    /*──────────────────────────────────────────────────────────────
     *  Helpers – brace counter parsers
     *──────────────────────────────────────────────────────────────*/
    private static int FindMatchingBraces(string txt, int openIdx)
    {
        int depth = 0;
        for (int i = openIdx; i < txt.Length; i++)
        {
            char c = txt[i];
            if (c == '{') depth++;
            else if (c == '}' && --depth == 0) return i + 1;
        }
        return -1;
    }

    private static IEnumerable<(int Id, string Inner, int Start)>
        ExtractMonsterBlocks(string zone,int zoneOffset)
    {
        var head = new Regex(@"Key:(\d+),\s*Value:\{", RegexOptions.Compiled);
        for (var m = head.Match(zone); m.Success; m = m.NextMatch())
        {
            int id = int.Parse(m.Groups[1].Value);
            int posOpen = m.Index + m.Length - 1;
            int depth = 1, i = posOpen+1;
            while (i<zone.Length && depth>0)
            {
                if (zone[i]=='{') depth++;
                else if (zone[i]=='}') depth--;
                i++;
            }
            yield return (id, zone.Substring(posOpen+1, i-posOpen-2),
                               zoneOffset+posOpen+1);
        }
    }

    private static (int[] Raw, EditableRange[] Ranges)?
        TryParseStats(string inner,int absOffset)
    {
        int idx = inner.IndexOf("_values:{{", StringComparison.Ordinal);
        if (idx == -1) return null;
        int start = idx+"_values:{{".Length;
        int depth = 2, i = start;
        while (i<inner.Length && depth>0)
        {
            if (inner[i]=='{') depth++;
            else if (inner[i]=='}') depth--;
            i++;
        }
        var body = inner.Substring(start, i-start-1);

        var numRx = new Regex(@"value:(\d+)", RegexOptions.Compiled);
        var nums = new List<(int v,int pos,int len)>();
        foreach (Match m in numRx.Matches(body))
            nums.Add((int.Parse(m.Groups[1].Value),
                      m.Groups[1].Index,
                      m.Groups[1].Length));
        if (nums.Count!=6) return null;

        int[] raw = new int[6];
        var rngs  = new EditableRange[6];
        for (int k=0;k<6;k++)
        {
            raw[k]=nums[k].v;
            rngs[k]=new EditableRange(absOffset+start+nums[k].pos, nums[k].len);
        }
        return (raw,rngs);
    }

    private static IEnumerable<(int Index, string Id, int Points, EditableRange NameRange, EditableRange PtsRange)>
        ExtractSkills(string inner,int absOffset)
    {
        int arrIdx = inner.IndexOf("_array", StringComparison.Ordinal);
        if (arrIdx<0) yield break;
        int brace = inner.IndexOf('{', arrIdx); if (brace<0) yield break;
        int depth=1, i=brace+1;
        while (i<inner.Length && depth>0)
        {
            if (inner[i]=='{') depth++;
            else if (inner[i]=='}') depth--;
            i++;
        }
        string body = inner.Substring(brace+1, i-brace-2);

        var entryRx = new Regex(@"_id\s*:\s*\{value:([^,}]+).*?_allocatedPoint\s*:\s*\{value:(\d+)",
                                RegexOptions.Singleline);
        int idx = 0;
        foreach (Match m in entryRx.Matches(body))
        {
            int bodyOffset = absOffset + brace + 1;
            int namePos = bodyOffset + m.Groups[1].Index;
            var nameRange = new EditableRange(namePos, m.Groups[1].Length);
            int pPos = bodyOffset + m.Groups[2].Index;
            var ptsRange = new EditableRange(pPos, m.Groups[2].Length);
            yield return (idx++, m.Groups[1].Value, int.Parse(m.Groups[2].Value), nameRange, ptsRange);
        }
    }

    /*──────────────────────────────────────────────────────────────
     *  Generic capture / patch helpers
     *──────────────────────────────────────────────────────────────*/
    private static void TryCapture(Regex rx, (int Id,string Inner,int Start) blk,
                                   Action<string,EditableRange> setter,
                                   string key, SaveMeta meta)
    {
        var m = rx.Match(blk.Inner);
        if (!m.Success) return;
        var r = new EditableRange(blk.Start + m.Groups[1].Index, m.Groups[1].Length);
        setter(m.Groups[1].Value, r);
        meta.OffsetTracker.Add(key, r);
    }
    private static void CaptureToken(string txt, Regex rx, string key,
                                     Action<string> setter, SaveMeta meta)
    {
        var m = rx.Match(txt); if (!m.Success) return;
        var r = new EditableRange(m.Groups[1].Index, m.Groups[1].Length);
        setter(m.Groups[1].Value);
        meta.OffsetTracker.Add(key, r);
    }
    private static void CaptureFloat(string txt, Regex rx,string key,
                                     Action<float> set, SaveMeta meta)
    {
        var m = rx.Match(txt); if(!m.Success) return;
        if(float.TryParse(m.Groups[1].Value,NumberStyles.Float,
                          CultureInfo.InvariantCulture,out var v))
        {
            var r = new EditableRange(m.Groups[1].Index,m.Groups[1].Length);
            set(v);
            meta.OffsetTracker.Add(key,r);
        }
    }
    private static void CaptureInt(string txt, Regex rx,string key,
                                   Action<int> set, SaveMeta meta)
    {
        var m = rx.Match(txt); if(!m.Success) return;
        if(int.TryParse(m.Groups[1].Value,out var v))
        {
            var r = new EditableRange(m.Groups[1].Index,m.Groups[1].Length);
            set(v);
            meta.OffsetTracker.Add(key,r);
        }
    }
    private static void Patch(StringBuilder sb, SaveMeta meta,
                              string key, string rep)
    {
        if (!meta.OffsetTracker.TryGetRange(key, out var r))
            return;

        string oldValue = sb.ToString(r.Start, r.Length);
        Debug.WriteLine($"[PATCH] Key: {key}, Offset: {r.Start}, Length: {r.Length}, Old: '{oldValue}', New: '{rep}'");

        sb.Remove(r.Start, r.Length).Insert(r.Start, rep);
        meta.OffsetTracker.UpdateOffsets(key, rep.Length - r.Length);
    }

}
