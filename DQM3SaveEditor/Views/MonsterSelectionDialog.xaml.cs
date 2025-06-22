using System.Collections.Generic;
using System.Linq;
using System.Windows;
using DQM3SaveEditor.Services;

namespace DQM3SaveEditor.Views;

public partial class MonsterSelectionDialog : Window
{
    private List<MonsterInfo>? _allMonsters;
    private MonsterInfo? _selectedMonster;

    public MonsterInfo? SelectedMonster => _selectedMonster;

    public MonsterSelectionDialog()
    {
        InitializeComponent();
        LoadMonsters();
    }

    private void LoadMonsters()
    {
        _allMonsters = MonsterMappingService.GetAllMonsters();
        MonsterGrid.ItemsSource = _allMonsters;
    }

    private void SearchBox_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
    {
        var searchText = SearchBox.Text.ToLower();
        if (string.IsNullOrWhiteSpace(searchText))
        {
            MonsterGrid.ItemsSource = _allMonsters;
        }
        else
        {
            var filtered = _allMonsters?.Where(m => 
                m.Name.ToLower().Contains(searchText) || 
                (m.JapaneseName?.ToLower().Contains(searchText) ?? false) ||
                m.MonsterId.ToString().Contains(searchText)
            ).ToList() ?? new List<MonsterInfo>();
            MonsterGrid.ItemsSource = filtered;
        }
    }

    private void MonsterGrid_MouseDoubleClick(object sender, System.Windows.Input.MouseButtonEventArgs e)
    {
        if (MonsterGrid.SelectedItem is MonsterInfo monster)
        {
            _selectedMonster = monster;
            DialogResult = true;
            Close();
        }
    }

    private void SelectButton_Click(object sender, RoutedEventArgs e)
    {
        if (MonsterGrid.SelectedItem is MonsterInfo monster)
        {
            _selectedMonster = monster;
            DialogResult = true;
            Close();
        }
        else
        {
            MessageBox.Show("Please select a monster first.", "No Selection", MessageBoxButton.OK, MessageBoxImage.Information);
        }
    }

    private void CancelButton_Click(object sender, RoutedEventArgs e)
    {
        DialogResult = false;
        Close();
    }
} 