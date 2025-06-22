using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows.Input;
using DQM3SaveEditor.Models;
using DQM3SaveEditor.Services;
using Microsoft.Win32;

namespace DQM3SaveEditor.ViewModels;

public class MainViewModel : ViewModelBase
{
    private readonly ISaveFileService _saveFileService;
    private bool _isDirty;
    private int _selectedTabIndex;

    public EnvironmentViewModel Environment { get; }
    public MonstersViewModel Monsters { get; }
    public InventoryViewModel Inventory { get; }
    public LibraryViewModel Library { get; }

    public bool IsDirty
    {
        get => _isDirty;
        set => SetField(ref _isDirty, value);
    }

    public int SelectedTabIndex
    {
        get => _selectedTabIndex;
        set => SetField(ref _selectedTabIndex, value);
    }

    public ICommand LoadSaveCommand { get; }
    public ICommand SaveSaveCommand { get; }

    public MainViewModel(ISaveFileService saveFileService)
    {
        _saveFileService = saveFileService;
        Environment = new EnvironmentViewModel();
        Monsters = new MonstersViewModel();
        Inventory = new InventoryViewModel();
        Library = new LibraryViewModel();

        // Subscribe to property changes to set IsDirty
        Environment.PropertyChanged += (_, __) => IsDirty = true;
        Monsters.PropertyChanged += (_, __) => IsDirty = true;
        Inventory.PropertyChanged += (_, __) => IsDirty = true;
        Library.PropertyChanged += (_, __) => IsDirty = true;

        LoadSaveCommand = new RelayCommand(_ => LoadSave());
        SaveSaveCommand = new RelayCommand(_ => SaveSave(), _ => IsDirty);
    }

    private async void LoadSave()
    {
        var dialog = new OpenFileDialog
        {
            Filter = "Save Files|*.bin;*.sav|All Files|*.*"
        };

        if (dialog.ShowDialog() == true)
        {
            try
            {
                var (monsters, inventory, environment) = await _saveFileService.LoadAsync(dialog.FileName);
                Monsters.FromModel(monsters);
                Inventory.FromModel(inventory);
                Environment.FromModel(environment);
                IsDirty = false;
            }
            catch (Exception ex)
            {
                // TODO: Show error dialog
                System.Diagnostics.Debug.WriteLine($"Error loading save: {ex}");
            }
        }
    }

    private async void SaveSave()
    {
        Console.WriteLine("=== SAVE SAVE STARTED ===");
        Console.WriteLine($"IsDirty: {IsDirty}");
        Console.WriteLine($"Monsters count: {Monsters.Monsters.Count}");
        Console.WriteLine($"Inventory count: {Inventory.Items.Count}");
        
        var dialog = new SaveFileDialog
        {
            Filter = "Save Files|*.bin;*.sav|All Files|*.*"
        };

        if (dialog.ShowDialog() == true)
        {
            try
            {
                Console.WriteLine($"Saving to: {dialog.FileName}");
                await _saveFileService.SaveAsync(
                    dialog.FileName,
                    Monsters.ToModel(),
                    Inventory.ToModel(),
                    Environment.ToModel()
                );
                IsDirty = false;
                Console.WriteLine("=== SAVE COMPLETED SUCCESSFULLY ===");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"=== SAVE ERROR: {ex} ===");
                // TODO: Show error dialog
                System.Diagnostics.Debug.WriteLine($"Error saving save: {ex}");
            }
        }
        else
        {
            Console.WriteLine("Save dialog cancelled");
        }
    }
} 