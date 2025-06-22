using System;
using System.Globalization;
using System.Windows;
using System.Windows.Data;

namespace DQM3SaveEditor.Converters
{
    public class SkillsCountToVisibilityConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value is int count && parameter != null && int.TryParse(parameter.ToString(), out int idx))
            {
                return count > idx ? Visibility.Collapsed : Visibility.Visible;
            }
            return Visibility.Visible;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
} 