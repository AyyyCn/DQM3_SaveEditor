using System.Collections.Generic;

namespace DQM3SaveEditor.Services;

/// <summary>
/// Tracks and updates offsets for all EditableRanges after a patch (for in-place editing).
/// </summary>
public class OffsetTracker
{
    private readonly List<(EditableRange Range, string Key)> _ranges = new();

    public void Add(string key, EditableRange range) => _ranges.Add((range, key));

    /// <summary>
    /// Call after a patch to update all subsequent ranges.
    /// </summary>
    public void UpdateOffsets(string patchedKey, int delta)
    {
        bool found = false;
        for (int i = 0; i < _ranges.Count; i++)
        {
            if (_ranges[i].Key == patchedKey)
            {
                found = true;
                continue;
            }
            if (found)
            {
                var (range, key) = _ranges[i];
                _ranges[i] = (new EditableRange(range.Start + delta, range.Length), key);
            }
        }
    }
} 