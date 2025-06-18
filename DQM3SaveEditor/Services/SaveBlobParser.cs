// Services/SaveBlobParser.cs
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.Services;

/// <summary>
/// Parse et patch le blob texte du save (quasi-JSON) sans DOM complet.
/// </summary>
public static class SaveBlobParser
{
    // Regex patterns for fields (singleline for multiline JSON)
    private static readonly Regex SeasonRegex = new(@"_player\s*:\s*{[^}]*?_environmentData\s*:\s*{[^}]*?_season\s*:\s*""(?<val>[^""]+)""", RegexOptions.Singleline);
    private static readonly Regex WeatherRegex = new(@"_player\s*:\s*{[^}]*?_environmentData\s*:\s*{[^}]*?_weather\s*:\s*""(?<val>[^""]+)""", RegexOptions.Singleline);
    private static readonly Regex SeasonTimerRegex = new(@"_timeParam\s*:\s*{[^}]*?seasonTimer\s*:\s*(?<val>[\d.]+)", RegexOptions.Singleline);
    private static readonly Regex WeatherTimerRegex = new(@"_timeParam\s*:\s*{[^}]*?weatherTimer\s*:\s*(?<val>[\d.]+)", RegexOptions.Singleline);
    // TODO: Add more regex for monsters, inventory, etc.

    /// <summary>
    /// Parse le blob texte et extrait les champs éditables.
    /// </summary>
    public static SaveMeta Parse(string blob)
    {
        Debug.WriteLine($"[DEBUG] SaveBlobParser.Parse starting - blob length: {blob.Length}");
        
        var meta = new SaveMeta();

        // Find and store editable fields with their ranges
        Debug.WriteLine($"[DEBUG] Starting regex parsing...");
        
        var seasonMatch = SeasonRegex.Match(blob);
        if (seasonMatch.Success)
        {
            meta.Season = seasonMatch.Groups["val"].Value;
            meta.Ranges["Season"] = new EditableRange(seasonMatch.Groups["val"].Index, seasonMatch.Groups["val"].Length);
            Debug.WriteLine($"[DEBUG] Found Season: '{meta.Season}' at position {seasonMatch.Groups["val"].Index}");
        }
        else
        {
            Debug.WriteLine($"[DEBUG] Season regex did not match");
        }
        
        var weatherMatch = WeatherRegex.Match(blob);
        if (weatherMatch.Success)
        {
            meta.Weather = weatherMatch.Groups["val"].Value;
            meta.Ranges["Weather"] = new EditableRange(weatherMatch.Groups["val"].Index, weatherMatch.Groups["val"].Length);
            Debug.WriteLine($"[DEBUG] Found Weather: '{meta.Weather}' at position {weatherMatch.Groups["val"].Index}");
        }
        else
        {
            Debug.WriteLine($"[DEBUG] Weather regex did not match");
        }
        
        var seasonTimerMatch = SeasonTimerRegex.Match(blob);
        if (seasonTimerMatch.Success)
        {
            meta.SeasonTimer = float.Parse(seasonTimerMatch.Groups["val"].Value, CultureInfo.InvariantCulture);
            meta.Ranges["SeasonTimer"] = new EditableRange(seasonTimerMatch.Groups["val"].Index, seasonTimerMatch.Groups["val"].Length);
            Debug.WriteLine($"[DEBUG] Found SeasonTimer: {meta.SeasonTimer} at position {seasonTimerMatch.Groups["val"].Index}");
        }
        else
        {
            Debug.WriteLine($"[DEBUG] SeasonTimer regex did not match");
        }
        
        var weatherTimerMatch = WeatherTimerRegex.Match(blob);
        if (weatherTimerMatch.Success)
        {
            meta.WeatherTimer = float.Parse(weatherTimerMatch.Groups["val"].Value, CultureInfo.InvariantCulture);
            meta.Ranges["WeatherTimer"] = new EditableRange(weatherTimerMatch.Groups["val"].Index, weatherTimerMatch.Groups["val"].Length);
            Debug.WriteLine($"[DEBUG] Found WeatherTimer: {meta.WeatherTimer} at position {weatherTimerMatch.Groups["val"].Index}");
        }
        else
        {
            Debug.WriteLine($"[DEBUG] WeatherTimer regex did not match");
        }

        // TODO: Parse monsters, inventory, etc. using similar span/regex logic
        Debug.WriteLine($"[DEBUG] SaveBlobParser.Parse completed. Found {meta.Ranges.Count} editable fields");

        return meta;
    }

    /// <summary>
    /// Applique les changements du SaveMeta au blob texte original.
    /// </summary>
    public static string ApplyChanges(string originalBlob, SaveMeta meta)
    {
        Debug.WriteLine($"[DEBUG] SaveBlobParser.ApplyChanges starting - original length: {originalBlob.Length}");
        
        var sb = new StringBuilder(originalBlob);

        // Patch season
        if (meta.Ranges.TryGetValue("Season", out var seasonRange))
        {
            Debug.WriteLine($"[DEBUG] Patching Season from '{originalBlob.Substring(seasonRange.Start, seasonRange.Length)}' to '{meta.Season}'");
            sb.Remove(seasonRange.Start, seasonRange.Length);
            sb.Insert(seasonRange.Start, meta.Season);
            // Update offsets
            meta.OffsetTracker.UpdateOffsets("Season", meta.Season.Length - seasonRange.Length);
        }
        
        // Patch weather
        if (meta.Ranges.TryGetValue("Weather", out var weatherRange))
        {
            Debug.WriteLine($"[DEBUG] Patching Weather from '{originalBlob.Substring(weatherRange.Start, weatherRange.Length)}' to '{meta.Weather}'");
            sb.Remove(weatherRange.Start, weatherRange.Length);
            sb.Insert(weatherRange.Start, meta.Weather);
            meta.OffsetTracker.UpdateOffsets("Weather", meta.Weather.Length - weatherRange.Length);
        }
        
        // Patch timers
        if (meta.Ranges.TryGetValue("SeasonTimer", out var stRange))
        {
            var val = meta.SeasonTimer.ToString(CultureInfo.InvariantCulture);
            Debug.WriteLine($"[DEBUG] Patching SeasonTimer from '{originalBlob.Substring(stRange.Start, stRange.Length)}' to '{val}'");
            sb.Remove(stRange.Start, stRange.Length);
            sb.Insert(stRange.Start, val);
            meta.OffsetTracker.UpdateOffsets("SeasonTimer", val.Length - stRange.Length);
        }
        
        if (meta.Ranges.TryGetValue("WeatherTimer", out var wtRange))
        {
            var val = meta.WeatherTimer.ToString(CultureInfo.InvariantCulture);
            Debug.WriteLine($"[DEBUG] Patching WeatherTimer from '{originalBlob.Substring(wtRange.Start, wtRange.Length)}' to '{val}'");
            sb.Remove(wtRange.Start, wtRange.Length);
            sb.Insert(wtRange.Start, val);
            meta.OffsetTracker.UpdateOffsets("WeatherTimer", val.Length - wtRange.Length);
        }

        // TODO: Patch monsters, inventory, etc.

        var patchedBlob = sb.ToString();
        Debug.WriteLine($"[DEBUG] SaveBlobParser.ApplyChanges completed - patched length: {patchedBlob.Length}");
        
        return patchedBlob;
    }
}
