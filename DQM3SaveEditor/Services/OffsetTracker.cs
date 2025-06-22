// OffsetTracker.cs  (drop-in replacement: only UpdateOffsets changed)

using System.Collections.Generic;

namespace DQM3SaveEditor.Services;

/// <summary>
/// Keeps every EditableRange plus its logical key
/// and realigns Start offsets after each in-place patch.
/// </summary>
public class OffsetTracker
{
    private readonly List<(EditableRange Range, string Key)> _ranges = new();

    public void Add(string key, EditableRange range) => _ranges.Add((range, key));

    public bool TryGetRange(string key, out EditableRange range)
    {
        foreach (var (r, k) in _ranges)
            if (k == key) { range = r; return true; }
        range = default;
        return false;
    }

    /// <param name="patchedKey">key just patched</param>
    /// <param name="delta"> newLength - oldLength (can be ±)</param>
    public void UpdateOffsets(string patchedKey, int delta)
    {
        if (delta == 0) return;

        // locate the *actual* range that changed
        EditableRange patched = default;
        foreach (var (r, k) in _ranges)
            if (k == patchedKey) { patched = r; break; }

        if (patched.Length == 0) return;      // safety

        int pivot = patched.Start + patched.Length;   // first byte *after* patch

        for (int i = 0; i < _ranges.Count; i++)
        {
            var (r, k) = _ranges[i];
            if (r.Start >= pivot)                   // text that comes after
                _ranges[i] = (new EditableRange(r.Start + delta, r.Length), k);
        }
    }
}
