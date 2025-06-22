namespace DQM3SaveEditor.Models;

public class PlayerState
{
    public string Name { get; set; } = string.Empty;
    public double PlayTimeSec { get; set; }
    public int GoldInPossession { get; set; }
    public int GoldInBank { get; set; }
    public int TotalEarnedGold { get; set; }
    public int CafePoint { get; set; }
} 