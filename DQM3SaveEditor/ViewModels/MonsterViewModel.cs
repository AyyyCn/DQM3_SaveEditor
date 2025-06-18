using System.Collections.Generic;
using System.Collections.ObjectModel;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.ViewModels;

public class MonsterViewModel : ViewModelBase
{
    private int _id;
    private string _name = string.Empty;
    private string _kind = string.Empty;
    private int _level;
    private int _size;
    private int _unspentPoints;
    private BasicStats _basicStats = new();
    private ObservableCollection<SkillAllocation> _skills = new();

    public int Id
    {
        get => _id;
        set => SetField(ref _id, value);
    }

    public string Name
    {
        get => _name;
        set => SetField(ref _name, value);
    }

    public string Kind
    {
        get => _kind;
        set => SetField(ref _kind, value);
    }

    public int Level
    {
        get => _level;
        set => SetField(ref _level, value);
    }

    public int Size
    {
        get => _size;
        set => SetField(ref _size, value);
    }

    public int UnspentPoints
    {
        get => _unspentPoints;
        set => SetField(ref _unspentPoints, value);
    }

    public BasicStats BasicStats
    {
        get => _basicStats;
        set => SetField(ref _basicStats, value);
    }

    public ObservableCollection<SkillAllocation> Skills
    {
        get => _skills;
        set => SetField(ref _skills, value);
    }

    public Monster ToModel() => new()
    {
        Id = Id,
        Name = Name,
        Kind = Kind,
        Level = Level,
        Size = Size,
        UnspentPoints = UnspentPoints,
        BasicStats = BasicStats,
        Skills = new List<SkillAllocation>(Skills)
    };

    public void FromModel(Monster model)
    {
        Id = model.Id;
        Name = model.Name;
        Kind = model.Kind;
        Level = model.Level;
        Size = model.Size;
        UnspentPoints = model.UnspentPoints;
        BasicStats = model.BasicStats;
        Skills = new ObservableCollection<SkillAllocation>(model.Skills);
    }
} 