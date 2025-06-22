using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using DQM3SaveEditor.Services;

namespace DQM3SaveEditor.Views;

public partial class MonsterSelectionDialog : Window
{
    private List<MonsterInfo> _allMonsters;
    public MonsterInfo? SelectedMonster { get; private set; }

    public MonsterSelectionDialog()
    {
        InitializeComponent();
        _allMonsters = MonsterMappingService.GetAllMonsters();
        MonsterGrid.ItemsSource = _allMonsters;
    }

    private void SearchBox_TextChanged(object sender, TextChangedEventArgs e)
    {
        var text = SearchBox.Text.Trim().ToLower();
        if (string.IsNullOrEmpty(text))
        {
            MonsterGrid.ItemsSource = _allMonsters;
        }
        else
        {
            MonsterGrid.ItemsSource = _allMonsters.Where(m =>
                m.Name.ToLower().Contains(text) ||
                (m.JapaneseName != null && m.JapaneseName.ToLower().Contains(text))
            ).ToList();
        }
    }

    private void MonsterGrid_MouseDoubleClick(object sender, MouseButtonEventArgs e)
    {
        if (MonsterGrid.SelectedItem is MonsterInfo mi)
        {
            SelectedMonster = mi;
            DialogResult = true;
            Close();
        }
    }

    private void SelectButton_Click(object sender, RoutedEventArgs e)
    {
        if (MonsterGrid.SelectedItem is MonsterInfo mi)
        {
            SelectedMonster = mi;
            DialogResult = true;
            Close();
        }
    }

    private void CancelButton_Click(object sender, RoutedEventArgs e)
    {
        DialogResult = false;
        Close();
    }
} 