using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using DQM3SaveEditor.Models;
using DQM3SaveEditor.Services;

namespace DQM3SaveEditor.Models;

/// <summary>
/// In-memory editable representation of the save file.
/// </summary>
public class SaveMeta
{
    public string Season { get; set; } = "";
    public string Weather { get; set; } = "";
    public float SeasonTimer { get; set; }
    public float WeatherTimer { get; set; }
    public ObservableCollection<MonsterMeta> Monsters { get; set; } = new();
    public List<ItemStack> Inventory { get; set; } = new();

    // For patching: map of field keys to their EditableRange in the text blob
    public Dictionary<string, EditableRange> Ranges { get; set; } = new();

    // For offset tracking
    public OffsetTracker OffsetTracker { get; set; } = new();

    // Dirty flag for UI
    public bool IsDirty { get; set; }

    /// <summary>
    /// Export monsters to List<Monster> for ViewModels
    /// </summary>
    public List<Monster> ExportMonsters()
    {
        return Monsters.Select(m => new Monster
        {
            Id = m.Id,
            Name = m.Name,
            Kind = m.Kind,
            Level = m.Level,
            Size = m.Size,
            UnspentPoints = m.UnspentPoints,
            BasicStats = m.BasicStats,
            Skills = m.Skills.Select(s => new SkillAllocation
            {
                Id = s.Id,
                Name = s.Name,
                AllocatedPoints = s.AllocatedPoints
            }).ToList()
        }).ToList();
    }

    /// <summary>
    /// Import monsters from List<Monster> while preserving IDs
    /// </summary>
    public void ImportMonsters(List<Monster> monsters)
    {
        // Clear existing monsters
        Monsters.Clear();
        
        // Add new monsters, preserving IDs where possible
        foreach (var monster in monsters)
        {
            var monsterMeta = new MonsterMeta
            {
                Id = monster.Id,
                Name = monster.Name,
                Kind = monster.Kind,
                Level = monster.Level,
                Size = monster.Size,
                UnspentPoints = monster.UnspentPoints,
                BasicStats = monster.BasicStats,
                Skills = monster.Skills.Select(s => new SkillAllocationMeta
                {
                    Id = s.Id,
                    Name = s.Name,
                    AllocatedPoints = s.AllocatedPoints
                }).ToList()
            };
            Monsters.Add(monsterMeta);
        }
    }
}

/// <summary>
/// Editable monster fields for patching.
/// </summary>
public class MonsterMeta
{
    public int Id { get; set; }
    public string Name { get; set; } = "";
    public string Kind { get; set; } = "";
    public int Level { get; set; }
    public int Size { get; set; }
    public int UnspentPoints { get; set; }
    public BasicStats BasicStats { get; set; } = new();
    public List<SkillAllocationMeta> Skills { get; set; } = new();
    // TODO: Add more fields as needed
    public Dictionary<string, EditableRange> Ranges { get; set; } = new();
}

public class SkillAllocationMeta
{
    public int Id { get; set; }
    public string Name { get; set; } = "";
    public int AllocatedPoints { get; set; }
    public EditableRange Range { get; set; }
} 