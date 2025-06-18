using System;
using System.Windows.Input;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.ViewModels;

public class EnvironmentViewModel : ViewModelBase
{
    private string _season = "Spring";
    private string _weather = "Fine";
    private int _hour;
    private int _minute;

    public string Season
    {
        get => _season;
        set => SetField(ref _season, value);
    }

    public string Weather
    {
        get => _weather;
        set => SetField(ref _weather, value);
    }

    public int Hour
    {
        get => _hour;
        set => SetField(ref _hour, Math.Clamp(value, 0, 23));
    }

    public int Minute
    {
        get => _minute;
        set => SetField(ref _minute, Math.Clamp(value, 0, 59));
    }

    public ICommand ResetTimersCommand { get; }

    public EnvironmentViewModel()
    {
        ResetTimersCommand = new RelayCommand(_ => ResetTimers());
    }

    private void ResetTimers()
    {
        Hour = 12;
        Minute = 0;
    }

    public EnvironmentState ToModel() => new()
    {
        Season = Season,
        Weather = Weather,
        Hour = Hour,
        Minute = Minute
    };

    public void FromModel(EnvironmentState model)
    {
        Season = model.Season;
        Weather = model.Weather;
        Hour = model.Hour;
        Minute = model.Minute;
    }
} 