using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Windows.Input;
using DQM3SaveEditor.Models;
using DQM3SaveEditor.Services;
using DQM3SaveEditor.Views;

namespace DQM3SaveEditor.ViewModels;

public class MonstersViewModel : ViewModelBase
{
    private ObservableCollection<MonsterViewModel> _monsters = new();
    private MonsterViewModel? _selectedMonster;

    public ObservableCollection<MonsterViewModel> Monsters
    {
        get => _monsters;
        set => SetField(ref _monsters, value);
    }

    public MonsterViewModel? SelectedMonster
    {
        get => _selectedMonster;
        set => SetField(ref _selectedMonster, value);
    }

    public ICommand AddMonsterCommand { get; }
    public ICommand EditSelectedCommand { get; }
    public ICommand DeleteSelectedCommand { get; }
    public ICommand ChangeMonsterCommand { get; }

    public MonstersViewModel()
    {
        AddMonsterCommand = new RelayCommand(_ => AddMonster());
        EditSelectedCommand = new RelayCommand(_ => EditSelected(), _ => SelectedMonster != null);
        DeleteSelectedCommand = new RelayCommand(_ => DeleteSelected(), _ => SelectedMonster != null);
        ChangeMonsterCommand = new RelayCommand(_ => ChangeMonster(), _ => SelectedMonster != null);
    }

    private void AddMonster()
    {
        var monster = new MonsterViewModel
        {
            Id = Monsters.Count + 1,
            Name = "New Monster",
            Kind = "Slime",
            Level = 1,
            Size = 1,
            UnspentPoints = 0
        };
        Monsters.Add(monster);
        SelectedMonster = monster;
    }

    private void EditSelected()
    {
        // TODO: Show edit dialog
        throw new NotImplementedException();
    }

    private void DeleteSelected()
    {
        if (SelectedMonster != null)
        {
            Monsters.Remove(SelectedMonster);
            SelectedMonster = null;
        }
    }

    private void ChangeMonster()
    {
        if (SelectedMonster == null) return;

        var dialog = new MonsterSelectionDialog();
        if (dialog.ShowDialog() == true && dialog.SelectedMonster != null)
        {
            var selectedMonsterInfo = dialog.SelectedMonster;
            SelectedMonster.Kind = selectedMonsterInfo.JapaneseName ?? selectedMonsterInfo.Name;
            // The EnglishKind will be automatically updated by the property setter
        }
    }

    public List<Monster> ToModel() => Monsters.Select(m => m.ToModel()).ToList();

    public void FromModel(List<Monster> monsters)
    {
        Monsters = new ObservableCollection<MonsterViewModel>(
            monsters.Select(m =>
            {
                var vm = new MonsterViewModel();
                vm.FromModel(m);
                return vm;
            })
        );
    }
} 