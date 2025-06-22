// Models/SaveMeta.cs
using System.Collections.Generic;
using System.Linq;
using System.Globalization;
using DQM3SaveEditor.Services;

namespace DQM3SaveEditor.Models;

/// <summary>
/// In-memory bridge between raw blob and UI.
/// All EditableRange & OffsetTracker wiring happens here.
/// </summary>
public class SaveMeta
{
    public string Season { get; set; } = "";
    public string Weather { get; set; } = "";
    public float SeasonTimer { get; set; }
    public float WeatherTimer { get; set; }

    public PlayerMeta Player { get; set; } = new();
    public List<MonsterMeta> Monsters { get; } = new();
    public List<ItemMeta> Inventory { get; } = new();

    public OffsetTracker OffsetTracker { get; } = new();

    /*─────────────────────────
     *  Converters ⇄ UI models
     *────────────────────────*/
    public IEnumerable<Monster> ExportMonsters() =>
        Monsters.Select(m => new Monster
        {
            Id = m.Id,
            Name = m.Name,
            Kind = m.Kind,
            Level = m.Level,
            Size = m.Size,
            Exp = m.Exp,
            UnspentPoints = m.UnspentPoints,

            BasicStats = new BasicStats
            {
                HP = m.Stats.HP,
                MP = m.Stats.MP,
                ATK = m.Stats.ATK,
                DEF = m.Stats.DEF,
                AGI = m.Stats.AGI,
                WIS = m.Stats.WIS
            },
            Skills = m.Skills.Select(s => new SkillAllocation
            {
                Id = s.Index,
                Name = s.Name,
                AllocatedPoints = s.Allocated
            }).ToList()
        });

    public void ImportMonsters(IEnumerable<Monster> edited)
    {
        foreach (var src in edited)
        {
            var tgt = Monsters.FirstOrDefault(x => x.Id == src.Id);
            if (tgt == null) continue;

            tgt.Name = src.Name;
            tgt.Kind = src.Kind;
            tgt.Level = src.Level;
            tgt.Size = src.Size;
            tgt.Exp = src.Exp;
            tgt.UnspentPoints = src.UnspentPoints;

            tgt.Stats = new StatBlock(
                src.BasicStats.HP,
                src.BasicStats.MP,
                src.BasicStats.ATK,
                src.BasicStats.DEF,
                src.BasicStats.AGI,
                src.BasicStats.WIS,
                tgt.Stats.Ranges // preserve the original ranges!
            );

            foreach (var sk in src.Skills)
            {
                var t = tgt.Skills.FirstOrDefault(s => s.Index == sk.Id);
                if (t != null)
                {
                    t.Allocated = sk.AllocatedPoints;
                    t.Name = sk.Name;
                }
            }
        }
    }

    public IEnumerable<ItemStack> ExportInventory() =>
        Inventory.Select(i => new ItemStack { Code = i.Code, Count = i.Count });

    public void ImportInventory(IEnumerable<ItemStack> edited)
    {
        foreach (var src in edited)
        {
            var tgt = Inventory.FirstOrDefault(x => x.Code == src.Code);
            if (tgt != null) tgt.Count = src.Count;
        }
    }

    public PlayerState ExportPlayer() => new PlayerState
    {
        Name = Player.Name,
        PlayTimeSec = Player.PlayTimeSec,
        GoldInPossession = Player.GoldInPossession,
        GoldInBank = Player.GoldInBank,
        TotalEarnedGold = Player.TotalEarnedGold,
        CafePoint = Player.CafePoint
    };

    public void ImportPlayer(PlayerState edited)
    {
        Player.Name = edited.Name;
        Player.PlayTimeSec = edited.PlayTimeSec;
        Player.GoldInPossession = edited.GoldInPossession;
        Player.GoldInBank = edited.GoldInBank;
        Player.TotalEarnedGold = edited.TotalEarnedGold;
        Player.CafePoint = edited.CafePoint;
    }
}

/*──────── internal raw blocks ────────*/

public record StatBlock(            // immutable "struct" + ranges
    int HP, int MP, int ATK,
    int DEF, int AGI, int WIS,
    EditableRange[] Ranges);

public class MonsterMeta
{
    public int Id;
    public string Name = "";
    public string Kind = "";
    public int Level;
    public int Size;
    public long Exp;

    public int UnspentPoints;

    public required StatBlock Stats;

    public EditableRange NameRange;
    public EditableRange KindRange;
    public EditableRange LevelRange;
    public EditableRange SizeRange;
    public EditableRange ExpRange;
    public EditableRange UnspentRange;

    public List<SkillMeta> Skills = new();
}

public class SkillMeta
{
    public int Index;
    public string Name = string.Empty;
    public int Allocated;
    public EditableRange Range;
    public EditableRange NameRange;
}

public class ItemMeta
{
    public string Code = "";
    public long Count;
    public EditableRange Range;
}

public class PlayerMeta
{
    public string Name = string.Empty;
    public double PlayTimeSec;
    public int GoldInPossession;
    public int GoldInBank;
    public int TotalEarnedGold;
    public int CafePoint;
}
