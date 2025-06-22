// Models/Monster.cs
using System.Collections.Generic;

namespace DQM3SaveEditor.Models;

public class Monster
{
    public int Id { get; set; }
    public string Name { get; set; } = "";
    public string Kind { get; set; } = "";
    public int Level { get; set; }
    public int Size { get; set; }
    public long Exp { get; set; }

    public int UnspentPoints { get; set; }

    public BasicStats BasicStats { get; set; } = new();   // view-model struct
    public List<SkillAllocation> Skills { get; set; } = new();
}

public class BasicStats          // UI-friendly POCO (no ranges)
{
    public int HP { get; set; }
    public int MP { get; set; }
    public int ATK { get; set; }
    public int DEF { get; set; }
    public int AGI { get; set; }
    public int WIS { get; set; }
}
