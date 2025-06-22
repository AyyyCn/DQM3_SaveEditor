using System.Collections.Generic;
using System.Collections.ObjectModel;
using DQM3SaveEditor.Models;
using DQM3SaveEditor.Services;

namespace DQM3SaveEditor.ViewModels;

public class MonsterViewModel : ViewModelBase
{
    private int _id;
    private string _name = string.Empty;
    private string _kind = string.Empty;
    private string _englishKind = string.Empty;
    private int _level;
    private int _size;
    private long _exp;
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
        set 
        { 
            SetField(ref _kind, value);
            // Update English name when Japanese name changes
            EnglishKind = MonsterMappingService.GetEnglishName(value);
        }
    }

    public string EnglishKind
    {
        get => _englishKind;
        set => SetField(ref _englishKind, value);
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

    public long Exp
    {
        get => _exp;
        set => SetField(ref _exp, value);
    }

    public int UnspentPoints
    {
        get => _unspentPoints;
        set => SetField(ref _unspentPoints, value);
    }

    public int HP
    {
        get => _basicStats.HP;
        set { if (_basicStats.HP != value) { _basicStats.HP = value; OnPropertyChanged(); } }
    }
    public int MP
    {
        get => _basicStats.MP;
        set { if (_basicStats.MP != value) { _basicStats.MP = value; OnPropertyChanged(); } }
    }
    public int ATK
    {
        get => _basicStats.ATK;
        set { if (_basicStats.ATK != value) { _basicStats.ATK = value; OnPropertyChanged(); } }
    }
    public int DEF
    {
        get => _basicStats.DEF;
        set { if (_basicStats.DEF != value) { _basicStats.DEF = value; OnPropertyChanged(); } }
    }
    public int AGI
    {
        get => _basicStats.AGI;
        set { if (_basicStats.AGI != value) { _basicStats.AGI = value; OnPropertyChanged(); } }
    }
    public int WIS
    {
        get => _basicStats.WIS;
        set { if (_basicStats.WIS != value) { _basicStats.WIS = value; OnPropertyChanged(); } }
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
        Kind = Kind, // Keep Japanese name for saving
        Level = Level,
        Size = Size,
        Exp = Exp,
        UnspentPoints = UnspentPoints,
        BasicStats = new()
        {
            HP = HP,
            MP = MP,
            ATK = ATK,
            DEF = DEF,
            AGI = AGI,
            WIS = WIS
        },
        Skills = new List<SkillAllocation>(Skills)
    };

    public void FromModel(Monster model)
    {
        Id = model.Id;
        Name = model.Name;
        Kind = model.Kind; // This will trigger EnglishKind update
        Level = model.Level;
        Size = model.Size;
        Exp = model.Exp;
        UnspentPoints = model.UnspentPoints;
        
        _basicStats = model.BasicStats;
        OnPropertyChanged(nameof(HP));
        OnPropertyChanged(nameof(MP));
        OnPropertyChanged(nameof(ATK));
        OnPropertyChanged(nameof(DEF));
        OnPropertyChanged(nameof(AGI));
        OnPropertyChanged(nameof(WIS));

        Skills = new ObservableCollection<SkillAllocation>(model.Skills);
    }
} 