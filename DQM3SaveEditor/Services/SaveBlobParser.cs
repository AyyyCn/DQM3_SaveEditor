// Services/SaveBlobParser.cs
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.Services;

internal static class SaveBlobParser
{
    /*───────────────────────────────────────────────────────────────
     *  Flat, unique fields
     *──────────────────────────────────────────────────────────────*/
    private static readonly Regex SeasonRx = new(
        @"_season\s*:\s*""?([^,\r\n}""\s]+)""?", RegexOptions.Singleline);
    private static readonly Regex WeatherRx = new(
        @"_weather\s*:\s*""?([^,\r\n}""\s]+)""?", RegexOptions.Singleline);
    private static readonly Regex SeasonTimerRx = new(
        @"seasonTimer\s*:\s*([\d.+\-Ee]+)(?=[,\r\n}])", RegexOptions.Singleline);
    private static readonly Regex WeatherTimerRx = new(
        @"weatherTimer\s*:\s*([\d.+\-Ee]+)(?=[,\r\n}])", RegexOptions.Singleline);

    /*───────────────────────────────────────────────────────────────
     *  Monster-internal small fields  (★ new patterns) 
     *──────────────────────────────────────────────────────────────*/
    private static readonly Regex M_NameRx = new(
        @"_name\s*:\s*""?([^,""\r\n}]+)""?", RegexOptions.Singleline);
    private static readonly Regex M_KindRx = new(
        @"_kind\s*:\s*\{value:([^,}]+)", RegexOptions.Singleline);      // ★
    private static readonly Regex M_LevelRx = new(
        @"_level\s*:\s*\{value:(\d+),?\}", RegexOptions.Singleline);      // ★
    private static readonly Regex M_SizeRx = new(
        @"_size\s*:\s*\{value:(\d+),?\}", RegexOptions.Singleline);      // ★
    private static readonly Regex M_UnspentRx = new(
        @"_unassignedSkillPoint(?:\.value)?\s*:\s*\{?\s*(?:value\s*:\s*)?(\d+)",
        RegexOptions.Singleline);
    private static readonly Regex M_SkillPtRx = new(
        @"_allocatedPoint(?:\.value)?\s*:\s*\{?\s*(?:value\s*:\s*)?(\d+)",
        RegexOptions.Singleline);

    /* stats block: six "value:x" in order - more flexible pattern */
    private static readonly Regex StatsBlockRx = new(                       // ★
        @"_basicParam[^}]*?_values:\{\{value:(\d+),?\},\{value:(\d+),?\},\{value:(\d+),?\},\{value:(\d+),?\},\{value:(\d+),?\},\{value:(\d+),?\}\}",
        RegexOptions.Singleline);

    /*───────────────────────────────────────────────────────────────
     *  Inventory
     *──────────────────────────────────────────────────────────────*/
    private static readonly Regex ItemRx = new(
        @"\{Key:([A-Za-z][A-Za-z0-9_]+),\s*Value:\{value:(\d{1,9}),",
        RegexOptions.Singleline);

    /*══════════════════════════════════════════════════════════════
     *  1.  Parse
     *══════════════════════════════════════════════════════════════*/
    internal static SaveMeta Parse(string blob)
    {
        var meta = new SaveMeta();

        /* env */
        CaptureToken(blob, SeasonRx, "Season", s => meta.Season = s, meta);
        CaptureToken(blob, WeatherRx, "Weather", s => meta.Weather = s, meta);
        CaptureFloat(blob, SeasonTimerRx, "SeasonTimer", v => meta.SeasonTimer = v, meta);
        CaptureFloat(blob, WeatherTimerRx, "WeatherTimer", v => meta.WeatherTimer = v, meta);

        /* monsters zone */
        int zoneIdx = blob.IndexOf("_monsters:{{", StringComparison.Ordinal);
        if (zoneIdx >= 0)
        {
            int zoneEnd = FindMatchingBraces(blob, zoneIdx + "_monsters:".Length);
            var zone = blob.Substring(zoneIdx, zoneEnd - zoneIdx);
            int offset = zoneIdx;

            foreach (var blk in ExtractMonsterBlocks(zone, offset))
            {
                var mon = new MonsterMeta 
                { 
                    Id = blk.Id, 
                    Skills = new List<SkillMeta>(),
                    Stats = new StatBlock(0, 0, 0, 0, 0, 0, new EditableRange[6]) // Default stats
                };

                /* name / kind / level / size / unspent */
                TryCapture(M_NameRx, blk, (v, r) => { mon.Name = v; mon.NameRange = r; },
                                        $"M.{mon.Id}.Name", meta);
                TryCapture(M_KindRx, blk, (v, r) => { mon.Kind = v; mon.KindRange = r; },
                                        $"M.{mon.Id}.Kind", meta);
                
                // Debug: Show what we're trying to parse for level
                var levelMatch = M_LevelRx.Match(blk.Inner);
                if (levelMatch.Success)
                {
                    mon.Level = int.Parse(levelMatch.Groups[1].Value);
                    mon.LevelRange = new EditableRange(blk.Start + levelMatch.Groups[1].Index, levelMatch.Groups[1].Length);
                    meta.OffsetTracker.Add($"M.{mon.Id}.Level", mon.LevelRange);
                    Console.WriteLine($"  [Monsters] Level: {mon.Level}");
                }
                else
                {
                    Console.WriteLine($"  [Monsters] WARNING: No level found for monster {mon.Id}");
                    // Try alternative level patterns
                    var altLevelPatterns = new[] {
                        @"_level\s*:\s*(\d+)",
                        @"level\s*:\s*(\d+)",
                        @"_level\s*:\s*\{value:(\d+),?\}"
                    };
                    foreach (var pattern in altLevelPatterns)
                    {
                        var altMatch = Regex.Match(blk.Inner, pattern, RegexOptions.Singleline);
                        if (altMatch.Success)
                        {
                            mon.Level = int.Parse(altMatch.Groups[1].Value);
                            mon.LevelRange = new EditableRange(blk.Start + altMatch.Groups[1].Index, altMatch.Groups[1].Length);
                            meta.OffsetTracker.Add($"M.{mon.Id}.Level", mon.LevelRange);
                            Console.WriteLine($"  [Monsters] Level (alt): {mon.Level}");
                            break;
                        }
                    }
                }
                
                TryCapture(M_SizeRx, blk, (v, r) => {
                    mon.Size = int.Parse(v);
                    mon.SizeRange = r;
                },
                                        $"M.{mon.Id}.Size", meta);
                TryCapture(M_UnspentRx, blk, (v, r) => {
                    mon.UnspentPoints = int.Parse(v);
                    mon.UnspentRange = r;
                },
                                        $"M.{mon.Id}.Unspent", meta);

                /* stats */
                // Debug: Show what we're trying to parse for stats
                Console.WriteLine($"  [Monsters] Looking for stats in monster {mon.Id}");
                var sMatch = StatsBlockRx.Match(blk.Inner);
                if (sMatch.Success)
                {
                    Console.WriteLine($"  [Monsters] Stats block found with {sMatch.Groups.Count - 1} values");
                    int[] raw = new int[6];
                    for (int i = 0; i < 6; i++) 
                    {
                        raw[i] = int.Parse(sMatch.Groups[i + 1].Value);
                        Console.WriteLine($"    [Monsters] Stat[{i}]: {raw[i]}");
                    }

                    var names = new[] { "HP", "MP", "ATK", "DEF", "AGI", "WIS" };
                    var ranges = new EditableRange[6];
                    for (int i = 0; i < 6; i++)
                    {
                        ranges[i] = new EditableRange(blk.Start + sMatch.Groups[i + 1].Index,
                                                      sMatch.Groups[i + 1].Length);
                        meta.OffsetTracker.Add($"M.{mon.Id}.Stats.{names[i]}", ranges[i]);
                    }
                    mon.Stats = new StatBlock(raw[0], raw[1], raw[2], raw[3], raw[4], raw[5], ranges);
                }
                else
                {
                    Console.WriteLine($"  [Monsters] WARNING: No stats block found for monster {mon.Id}");
                    // Try alternative stats patterns
                    var altStatsPatterns = new[] {
                        @"_values:\{\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),",
                        @"_values:\{\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),\},\{value:(\d+),\}\}",
                        @"_values:\{(\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\}"
                    };
                    foreach (var pattern in altStatsPatterns)
                    {
                        var altMatch = Regex.Match(blk.Inner, pattern, RegexOptions.Singleline);
                        if (altMatch.Success)
                        {
                            Console.WriteLine($"  [Monsters] Stats block found (alt pattern) with {altMatch.Groups.Count - 1} values");
                            int[] raw = new int[6];
                            for (int i = 0; i < 6; i++) 
                            {
                                raw[i] = int.Parse(altMatch.Groups[i + 1].Value);
                                Console.WriteLine($"    [Monsters] Stat[{i}]: {raw[i]}");
                            }

                            var names = new[] { "HP", "MP", "ATK", "DEF", "AGI", "WIS" };
                            var ranges = new EditableRange[6];
                            for (int i = 0; i < 6; i++)
                            {
                                ranges[i] = new EditableRange(blk.Start + altMatch.Groups[i + 1].Index,
                                                              altMatch.Groups[i + 1].Length);
                                meta.OffsetTracker.Add($"M.{mon.Id}.Stats.{names[i]}", ranges[i]);
                            }
                            mon.Stats = new StatBlock(raw[0], raw[1], raw[2], raw[3], raw[4], raw[5], ranges);
                            break;
                        }
                    }
                }

                /* skills */
                int idx = 0;
                foreach (Match s in M_SkillPtRx.Matches(blk.Inner))
                {
                    var sk = new SkillMeta
                    {
                        Index = idx,
                        Allocated = int.Parse(s.Groups[1].Value),
                        Range = new EditableRange(blk.Start + s.Groups[1].Index,
                                                      s.Groups[1].Length)
                    };
                    mon.Skills.Add(sk);
                    meta.OffsetTracker.Add($"M.{mon.Id}.S{idx}", sk.Range);
                    idx++;
                }

                meta.Monsters.Add(mon);
            }
        }
        
        // Debug: Show what monsters were parsed
        Console.WriteLine($"=== MONSTER PARSING COMPLETE - Total monsters: {meta.Monsters.Count} ===");
        foreach (var mon in meta.Monsters)
        {
            Console.WriteLine($"  Monster {mon.Id}: Name='{mon.Name}', Kind='{mon.Kind}', Level={mon.Level}, Size={mon.Size}, Exp={mon.Exp}");
            Console.WriteLine($"    Stats: HP={mon.Stats.HP}, MP={mon.Stats.MP}, ATK={mon.Stats.ATK}, DEF={mon.Stats.DEF}, AGI={mon.Stats.AGI}, WIS={mon.Stats.WIS}");
            Console.WriteLine($"    Skills: {mon.Skills.Count} skills, Unspent: {mon.UnspentPoints}");
        }

        /* inventory */
        foreach (Match m in ItemRx.Matches(blob))
        {
            var range = new EditableRange(m.Groups[2].Index, m.Groups[2].Length);
            meta.Inventory.Add(new ItemMeta
            {
                Code = m.Groups[1].Value,
                Count = long.Parse(m.Groups[2].Value),
                Range = range
            });
            meta.OffsetTracker.Add($"I.{m.Groups[1].Value}", range);
        }

        return meta;
    }

    /*══════════════════════════════════════════════════════════════
     *  2.  ApplyChanges
     *══════════════════════════════════════════════════════════════*/
    internal static string ApplyChanges(string blob, SaveMeta meta)
    {
        var sb = new StringBuilder(blob);
        Console.WriteLine("=== APPLYING CHANGES ===");
        Console.WriteLine($"Original blob length: {blob.Length}");

        // Collect all changes first, then apply them in reverse order
        var changes = new List<(int Start, int Length, string Replacement, string Key)>();

        /* environment */
        Console.WriteLine($"Collecting Season: '{meta.Season}'");
        CollectChange(changes, meta, "Season", meta.Season);
        Console.WriteLine($"Collecting Weather: '{meta.Weather}'");
        CollectChange(changes, meta, "Weather", meta.Weather);
        Console.WriteLine($"Collecting SeasonTimer: {meta.SeasonTimer}");
        CollectChange(changes, meta, "SeasonTimer", meta.SeasonTimer.ToString(CultureInfo.InvariantCulture));
        Console.WriteLine($"Collecting WeatherTimer: {meta.WeatherTimer}");
        CollectChange(changes, meta, "WeatherTimer", meta.WeatherTimer.ToString(CultureInfo.InvariantCulture));

        /* monsters */
        Console.WriteLine($"Collecting changes for {meta.Monsters.Count} monsters");
        foreach (var m in meta.Monsters)
        {
            Console.WriteLine($"  Collecting monster {m.Id}: Name='{m.Name}', Level={m.Level}, Size={m.Size}");
            CollectChange(changes, meta, $"M.{m.Id}.Name", m.Name);
            CollectChange(changes, meta, $"M.{m.Id}.Kind", m.Kind);
            CollectChange(changes, meta, $"M.{m.Id}.Level", m.Level.ToString());
            CollectChange(changes, meta, $"M.{m.Id}.Size", m.Size.ToString());
            CollectChange(changes, meta, $"M.{m.Id}.Unspent", m.UnspentPoints.ToString());

            Console.WriteLine($"    Stats: HP={m.Stats.HP}, MP={m.Stats.MP}, ATK={m.Stats.ATK}, DEF={m.Stats.DEF}, AGI={m.Stats.AGI}, WIS={m.Stats.WIS}");
            CollectChange(changes, meta, $"M.{m.Id}.Stats.HP", m.Stats.HP.ToString());
            CollectChange(changes, meta, $"M.{m.Id}.Stats.MP", m.Stats.MP.ToString());
            CollectChange(changes, meta, $"M.{m.Id}.Stats.ATK", m.Stats.ATK.ToString());
            CollectChange(changes, meta, $"M.{m.Id}.Stats.DEF", m.Stats.DEF.ToString());
            CollectChange(changes, meta, $"M.{m.Id}.Stats.AGI", m.Stats.AGI.ToString());
            CollectChange(changes, meta, $"M.{m.Id}.Stats.WIS", m.Stats.WIS.ToString());

            foreach (var sk in m.Skills)
                CollectChange(changes, meta, $"M.{m.Id}.S{sk.Index}", sk.Allocated.ToString());
        }

        /* inventory */
        Console.WriteLine($"Collecting changes for {meta.Inventory.Count} inventory items");
        foreach (var it in meta.Inventory)
        {
            Console.WriteLine($"  Collecting item {it.Code}: {it.Count}");
            CollectChange(changes, meta, $"I.{it.Code}", it.Count.ToString());
        }

        // Apply changes in reverse order (highest position first)
        changes.Sort((a, b) => b.Start.CompareTo(a.Start));
        
        Console.WriteLine($"Applying {changes.Count} changes in reverse order:");
        foreach (var change in changes)
        {
            var originalValue = sb.ToString(change.Start, change.Length);
            Console.WriteLine($"  Patching {change.Key}: '{originalValue}' -> '{change.Replacement}' at pos {change.Start}");
            
            // Ensure exact replacement
            var paddedReplacement = change.Replacement.PadLeft(change.Length, ' ');
            if (paddedReplacement.Length > change.Length)
            {
                paddedReplacement = change.Replacement.Substring(0, change.Length);
            }
            
            sb.Remove(change.Start, change.Length).Insert(change.Start, paddedReplacement);
            Console.WriteLine($"    Replaced with '{paddedReplacement}' (length: {paddedReplacement.Length})");
        }

        Console.WriteLine("=== CHANGES APPLIED ===");
        Console.WriteLine($"Original blob length: {blob.Length}");
        Console.WriteLine($"Patched blob length: {sb.Length}");
        if (sb.Length != blob.Length)
        {
            Console.WriteLine($"WARNING: Blob size changed! Original: {blob.Length}, New: {sb.Length}");
            Console.WriteLine($"Difference: {sb.Length - blob.Length} bytes");
            
            // Show the first difference
            for (int i = 0; i < Math.Min(blob.Length, sb.Length); i++)
            {
                if (blob[i] != sb[i])
                {
                    Console.WriteLine($"First difference at position {i}: Original='{blob[i]}' ({(int)blob[i]}), New='{sb[i]}' ({(int)sb[i]})");
                    break;
                }
            }
        }
        return sb.ToString();
    }

    private static void CollectChange(List<(int Start, int Length, string Replacement, string Key)> changes, 
                                     SaveMeta meta, string key, string replacement)
    {
        // Try to get range from Ranges dictionary first (for environment data)
        if (meta.Ranges.TryGetValue(key, out var r))
        {
            changes.Add((r.Start, r.Length, replacement, key));
            return;
        }
        
        // Try to get range from OffsetTracker (for monster/inventory data)
        if (meta.OffsetTracker.TryGetRange(key, out r))
        {
            changes.Add((r.Start, r.Length, replacement, key));
        }
        else
        {
            Console.WriteLine($"  WARNING: Could not find range for key '{key}'");
        }
    }

    /*──────────────────────────────────────────────────────────────
     *  Brace counter helpers
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

    private static IEnumerable<(int Id, string Inner, int Start)> ExtractMonsterBlocks(string zone, int zoneOffset)
    {
        var head = new Regex(@"Key:(\d+),\s*Value:\{", RegexOptions.Compiled);
        for (var m = head.Match(zone); m.Success; m = m.NextMatch())
        {
            int id = int.Parse(m.Groups[1].Value);
            int posOpen = m.Index + m.Length - 1;
            int depth = 1, i = posOpen + 1;
            for (; i < zone.Length && depth > 0; i++)
                depth += zone[i] == '{' ? 1 : zone[i] == '}' ? -1 : 0;

            yield return (id,
                          zone.Substring(posOpen + 1, i - posOpen - 2),
                          zoneOffset + posOpen + 1);
        }
    }

    /*──────────────────────────────────────────────────────────────
     *  Capture & patch helpers
     *──────────────────────────────────────────────────────────────*/
    private static void TryCapture(Regex rx, (int Id, string Inner, int Start) blk,
                                   Action<string, EditableRange> setter,
                                   string key, SaveMeta meta)
    {
        var m = rx.Match(blk.Inner);
        if (!m.Success) return;
        var range = new EditableRange(blk.Start + m.Groups[1].Index,
                                      m.Groups[1].Length);
        setter(m.Groups[1].Value, range);
        meta.OffsetTracker.Add(key, range);
    }

    private static void CaptureToken(string blob, Regex rx, string key,
                                     Action<string> setter, SaveMeta meta)
    {
        var m = rx.Match(blob);
        if (!m.Success) return;
        var r = new EditableRange(m.Groups[1].Index, m.Groups[1].Length);
        setter(m.Groups[1].Value);
        meta.Ranges[key] = r;
        meta.OffsetTracker.Add(key, r);
    }

    private static void CaptureFloat(string blob, Regex rx, string key,
                                     Action<float> setter, SaveMeta meta)
    {
        var m = rx.Match(blob);
        if (!m.Success) return;
        if (float.TryParse(m.Groups[1].Value, NumberStyles.Float,
                           CultureInfo.InvariantCulture, out var v))
        {
            var r = new EditableRange(m.Groups[1].Index, m.Groups[1].Length);
            setter(v);
            meta.Ranges[key] = r;
            meta.OffsetTracker.Add(key, r);
        }
    }
}
