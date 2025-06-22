using System.ComponentModel;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.ViewModels;

public class PlayerViewModel : INotifyPropertyChanged
{
    private string _name;
    private double _playTimeSec;
    private int _goldInPossession;
    private int _goldInBank;
    private int _totalEarnedGold;
    private int _cafePoint;

    public string Name { get => _name; set { if (_name != value) { _name = value; OnPropertyChanged(nameof(Name)); } } }
    public double PlayTimeSec { get => _playTimeSec; set { if (_playTimeSec != value) { _playTimeSec = value; OnPropertyChanged(nameof(PlayTimeSec)); } } }
    public int GoldInPossession { get => _goldInPossession; set { if (_goldInPossession != value) { _goldInPossession = value; OnPropertyChanged(nameof(GoldInPossession)); } } }
    public int GoldInBank { get => _goldInBank; set { if (_goldInBank != value) { _goldInBank = value; OnPropertyChanged(nameof(GoldInBank)); } } }
    public int TotalEarnedGold { get => _totalEarnedGold; set { if (_totalEarnedGold != value) { _totalEarnedGold = value; OnPropertyChanged(nameof(TotalEarnedGold)); } } }
    public int CafePoint { get => _cafePoint; set { if (_cafePoint != value) { _cafePoint = value; OnPropertyChanged(nameof(CafePoint)); } } }

    public PlayerViewModel(PlayerState state)
    {
        _name = state.Name;
        _playTimeSec = state.PlayTimeSec;
        _goldInPossession = state.GoldInPossession;
        _goldInBank = state.GoldInBank;
        _totalEarnedGold = state.TotalEarnedGold;
        _cafePoint = state.CafePoint;
    }

    public PlayerState ToPlayerState() => new PlayerState
    {
        Name = this.Name,
        PlayTimeSec = this.PlayTimeSec,
        GoldInPossession = this.GoldInPossession,
        GoldInBank = this.GoldInBank,
        TotalEarnedGold = this.TotalEarnedGold,
        CafePoint = this.CafePoint
    };

    public void FromModel(PlayerState state)
    {
        Name = state.Name;
        PlayTimeSec = state.PlayTimeSec;
        GoldInPossession = state.GoldInPossession;
        GoldInBank = state.GoldInBank;
        TotalEarnedGold = state.TotalEarnedGold;
        CafePoint = state.CafePoint;
    }

    public PlayerState ToModel() => ToPlayerState();

    public event PropertyChangedEventHandler? PropertyChanged;
    protected void OnPropertyChanged(string propertyName) => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
} 