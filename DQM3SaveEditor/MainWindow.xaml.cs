using System.Windows;
using DQM3SaveEditor.Services;
using DQM3SaveEditor.ViewModels;

namespace DQM3SaveEditor;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
        DataContext = new MainViewModel(new SaveFileService());
    }

    private void ExitMenuItem_Click(object sender, RoutedEventArgs e)
    {
        Close();
    }
}