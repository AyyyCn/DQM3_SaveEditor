using System.Windows.Input;

namespace DQM3SaveEditor.ViewModels;

public class LibraryViewModel : ViewModelBase
{
    public ICommand UnlockAllBooksCommand { get; }
    public ICommand UnlockAllMonstersCommand { get; }

    public LibraryViewModel()
    {
        UnlockAllBooksCommand = new RelayCommand(_ => UnlockAllBooks());
        UnlockAllMonstersCommand = new RelayCommand(_ => UnlockAllMonsters());
    }

    private void UnlockAllBooks()
    {
        // TODO: Implement book unlocking
        throw new System.NotImplementedException();
    }

    private void UnlockAllMonsters()
    {
        // TODO: Implement monster unlocking
        throw new System.NotImplementedException();
    }
} 