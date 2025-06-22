using System;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using DQM3SaveEditor.ViewModels;
using System.IO;
using System.Diagnostics;
using DQM3SaveEditor.Services;

namespace DQM3SaveEditor.Views
{
    public partial class MonsterCard : UserControl, INotifyPropertyChanged
    {
        public MonsterCard()
        {
            InitializeComponent();
            Debug.WriteLine("[MonsterCard] Constructor called");
        }

        public static readonly DependencyProperty MonsterProperty = DependencyProperty.Register(
            nameof(Monster), typeof(MonsterViewModel), typeof(MonsterCard), new PropertyMetadata(null, OnMonsterChanged));

        public MonsterViewModel Monster
        {
            get => (MonsterViewModel)GetValue(MonsterProperty);
            set
            {
                SetValue(MonsterProperty, value);
                DataContext = value;
                Debug.WriteLine("[MonsterCard] Monster property set");
            }
        }

        public string ImagePath
        {
            get
            {
                if (Monster == null) return string.Empty;
                var info = DQM3SaveEditor.Services.MonsterMappingService.GetMonsterByJapaneseName(Monster.Kind);
                if (info == null)
                {
                    System.Diagnostics.Debug.WriteLine($"[MonsterCard] No mapping found for JapaneseName: {Monster.Kind}");
                    return string.Empty;
                }
                var safeName = info.Name.Replace(' ', '_').Replace("'", "_").Replace("-", "_");
                var fileName = $"{safeName}.1.jpg"; // No ID
                var relPath = System.IO.Path.Combine("Resources", "MonsterImages", fileName);
                var absPath = System.IO.Path.GetFullPath(relPath);
                System.Diagnostics.Debug.WriteLine($"[MonsterCard] ImagePath computed: {relPath} (abs: {absPath}) Exists: {System.IO.File.Exists(absPath)}");
                return relPath;
            }
        }

        private static void OnMonsterChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            var control = d as MonsterCard;
            if (control != null)
            {
                control.DataContext = control.Monster;
                control.OnPropertyChanged(nameof(ImagePath));
                Debug.WriteLine("[MonsterCard] OnMonsterChanged called");
            }
        }

        public event PropertyChangedEventHandler? PropertyChanged;
        protected void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
} 