using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.Services;

public class MonsterMappingService
{
    private static Dictionary<string, string> _japaneseToEnglish = new();
    private static Dictionary<string, string> _englishToJapanese = new();
    private static List<MonsterInfo> _allMonsters = new();
    private static bool _initialized = false;

    public static void Initialize()
    {
        if (_initialized) return;

        try
        {
            var jsonPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Resources", "monster.json");
            var jsonContent = File.ReadAllText(jsonPath);
            var monsters = JsonSerializer.Deserialize<List<MonsterInfo>>(jsonContent);

            if (monsters != null)
            {
                _allMonsters = monsters;
                foreach (var monster in monsters)
                {
                    if (!string.IsNullOrEmpty(monster.JapaneseName))
                    {
                        _japaneseToEnglish[monster.JapaneseName] = monster.Name;
                        _englishToJapanese[monster.Name] = monster.JapaneseName;
                    }
                }
            }
            _initialized = true;
        }
        catch (Exception ex)
        {
            System.Diagnostics.Debug.WriteLine($"Error loading monster mapping: {ex}");
        }
    }

    public static string GetEnglishName(string japaneseName)
    {
        Initialize();
        return _japaneseToEnglish.TryGetValue(japaneseName, out var englishName) ? englishName : japaneseName;
    }

    public static string GetJapaneseName(string englishName)
    {
        Initialize();
        return _englishToJapanese.TryGetValue(englishName, out var japaneseName) ? japaneseName : englishName;
    }

    public static List<MonsterInfo> GetAllMonsters()
    {
        Initialize();
        return _allMonsters.ToList();
    }

    public static MonsterInfo? GetMonsterByJapaneseName(string japaneseName)
    {
        Initialize();
        return _allMonsters.FirstOrDefault(m => m.JapaneseName == japaneseName);
    }

    public static MonsterInfo? GetMonsterByEnglishName(string englishName)
    {
        Initialize();
        return _allMonsters.FirstOrDefault(m => m.Name == englishName);
    }
}

public class MonsterInfo
{
    public int MonsterId { get; set; }
    public int FamilyId { get; set; }
    public int RankId { get; set; }
    public string Name { get; set; } = "";
    public string? JapaneseName { get; set; }
} 