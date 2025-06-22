using System;
using System.Globalization;
using System.IO;
using System.Windows.Data;
using System.Windows.Media.Imaging;

namespace DQM3SaveEditor.Converters
{
    public class ImagePathToBitmapConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value is string path && !string.IsNullOrEmpty(path))
            {
                string absPath = Path.GetFullPath(path);
                Console.WriteLine($"[ImagePathToBitmapConverter] Attempting to load: {absPath}");
                if (File.Exists(absPath))
                {
                    try
                    {
                        Console.WriteLine($"[ImagePathToBitmapConverter] File exists: {absPath}");
                        return new BitmapImage(new Uri(absPath, UriKind.Absolute));
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"[ImagePathToBitmapConverter] Exception: {ex.Message}");
                    }
                }
                else
                {
                    Console.WriteLine($"[ImagePathToBitmapConverter] File does NOT exist: {absPath}");
                }
            }
            return System.Windows.DependencyProperty.UnsetValue;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
} 