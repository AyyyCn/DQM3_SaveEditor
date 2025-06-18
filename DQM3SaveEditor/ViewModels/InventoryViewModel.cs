using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Windows.Input;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.ViewModels;

public class InventoryViewModel : ViewModelBase
{
    private ObservableCollection<ItemStack> _items = new();
    private ItemStack? _selectedItem;

    public ObservableCollection<ItemStack> Items
    {
        get => _items;
        set => SetField(ref _items, value);
    }

    public ItemStack? SelectedItem
    {
        get => _selectedItem;
        set => SetField(ref _selectedItem, value);
    }

    public ICommand AddItemCommand { get; }
    public ICommand RemoveSelectedCommand { get; }

    public InventoryViewModel()
    {
        AddItemCommand = new RelayCommand(_ => AddItem());
        RemoveSelectedCommand = new RelayCommand(_ => RemoveSelected(), _ => SelectedItem != null);
    }

    private void AddItem()
    {
        var item = new ItemStack { Code = "NEW_ITEM", Count = 1 };
        Items.Add(item);
        SelectedItem = item;
    }

    private void RemoveSelected()
    {
        if (SelectedItem != null)
        {
            Items.Remove(SelectedItem);
            SelectedItem = null;
        }
    }

    public List<ItemStack> ToModel() => new List<ItemStack>(Items);

    public void FromModel(List<ItemStack> items)
    {
        Items = new ObservableCollection<ItemStack>(items);
    }
} 