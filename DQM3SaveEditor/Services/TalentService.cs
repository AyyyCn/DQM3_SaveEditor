using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace DQM3SaveEditor.Services;

public static class TalentService
{
    private static List<string>? _talentNames;

    public static List<string> GetAllTalentNames()
    {
        if (_talentNames == null)
        {
            try
            {
                var talentPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Resources", "talent.txt");
                if (File.Exists(talentPath))
                {
                    _talentNames = File.ReadAllLines(talentPath).Where(line => !string.IsNullOrWhiteSpace(line)).ToList();
                }
                else
                {
                    _talentNames = new List<string>();
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine($"Error loading talents: {ex.Message}");
                _talentNames = new List<string>();
            }
        }
        return _talentNames;
    }
} 