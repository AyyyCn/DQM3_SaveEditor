using System;
using System.Globalization;
using System.Windows.Data;

namespace DQM3SaveEditor.Converters;

public class BoolToDirtyMarkConverter : IValueConverter
{
    public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        return value is bool isDirty && isDirty ? "●" : string.Empty;
    }

    public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
} 