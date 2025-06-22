using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows.Input;
using DQM3SaveEditor.Models;
using DQM3SaveEditor.Services;
using Microsoft.Win32;
using DQM3SaveEditor.ViewModels;
using System.Linq;

namespace DQM3SaveEditor.ViewModels;

public class MainViewModel : ViewModelBase
{
    private readonly ISaveFileService _saveFileService;
    private bool _isDirty;
    private int _selectedTabIndex;

    public EnvironmentViewModel Environment { get; }
    public MonstersViewModel Monsters { get; }
    public InventoryViewModel Inventory { get; }
    public PlayerViewModel Player { get; }

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
    public ICommand UnlockAllMonstersCommand { get; }
    public ICommand UnlockAllSkillsCommand { get; }
    public ICommand UnlockAllLibraryCommand { get; }

    public MainViewModel(ISaveFileService saveFileService)
    {
        _saveFileService = saveFileService;
        Environment = new EnvironmentViewModel();
        Monsters = new MonstersViewModel();
        Inventory = new InventoryViewModel();
        Player = new PlayerViewModel(new PlayerState());

        // Subscribe to property changes to set IsDirty
        Environment.PropertyChanged += (_, __) => IsDirty = true;
        Monsters.PropertyChanged += (_, __) => IsDirty = true;
        Inventory.PropertyChanged += (_, __) => IsDirty = true;
        Player.PropertyChanged += (_, __) => IsDirty = true;

        LoadSaveCommand = new RelayCommand(_ => LoadSave());
        SaveSaveCommand = new RelayCommand(_ => SaveSave(), _ => IsDirty);
        UnlockAllMonstersCommand = new RelayCommand(_ => UnlockAllMonsters());
        UnlockAllSkillsCommand = new RelayCommand(_ => UnlockAllSkills());
        UnlockAllLibraryCommand = new RelayCommand(_ => UnlockAllLibrary());
    }

    private async void LoadSave()
    {
        var dialog = new OpenFileDialog
        {
            Filter = "Save Files|*.bin|All Files|*.*"
        };

        if (dialog.ShowDialog() == true)
        {
            try
            {
                var (monsters, inventory, environment) = await _saveFileService.LoadAsync(dialog.FileName);
                Monsters.FromModel(monsters);
                Inventory.FromModel(inventory);
                Environment.FromModel(environment);
                // Load player data
                if (_saveFileService is SaveFileService concrete)
                {
                    var playerState = concrete.GetPlayerState();
                    Player.FromModel(playerState);
                }
                Console.WriteLine($"Save loaded successfully from: {dialog.FileName}");
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
                if (_saveFileService is SaveFileService concrete)
                {
                    concrete.SetPlayerState(Player.ToModel());
                }
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

    private void UnlockAllMonsters()
    {
        // TODO: Implement unlock logic
    }

    private void UnlockAllSkills()
    {
        // TODO: Implement unlock logic
    }

    private void UnlockAllLibrary()
    {
        try
        {
            // Load the full library blob from resources
            var libraryPath = System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Resources", "library.txt");
            if (!System.IO.File.Exists(libraryPath))
            {
                System.Diagnostics.Debug.WriteLine($"library.txt not found at {libraryPath}");
                return;
            }
            var libraryBlob = System.IO.File.ReadAllText(libraryPath);

            // Replace the _library block in the current blob
            if (_saveFileService is SaveFileService concrete)
            {
                var currentBlobField = typeof(SaveFileService).GetField("_currentBlob", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                var currentMetaField = typeof(SaveFileService).GetField("_currentMeta", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (currentBlobField == null || currentMetaField == null) return;
                var currentBlob = currentBlobField.GetValue(concrete) as string;
                if (string.IsNullOrEmpty(currentBlob)) return;

                // Find the _library block and replace it
                var rx = new System.Text.RegularExpressions.Regex("_library:\\{.*?\\},_gamePlay:", System.Text.RegularExpressions.RegexOptions.Singleline);
                var replaced = rx.Replace(currentBlob, m => libraryBlob + ",_gamePlay:", 1);
                if (replaced == currentBlob) return;

                // Re-parse the blob to update meta
                var meta = DQM3SaveEditor.Services.SaveBlobParser.Parse(replaced);
                currentBlobField.SetValue(concrete, replaced);
                currentMetaField.SetValue(concrete, meta);

                // Update in-memory models
                Monsters.FromModel(meta.ExportMonsters().ToList());
                Inventory.FromModel(meta.ExportInventory().ToList());
                Environment.FromModel(new EnvironmentState { Season = meta.Season, Weather = meta.Weather });
                Player.FromModel(meta.ExportPlayer());
                IsDirty = true;
            }
        }
        catch (Exception ex)
        {
            System.Diagnostics.Debug.WriteLine($"UnlockAllLibrary error: {ex}");
        }
    }
} 