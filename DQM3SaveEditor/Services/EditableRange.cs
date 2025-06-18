namespace DQM3SaveEditor.Services;

/// <summary>
/// Represents a patchable region in the save text (start, length).
/// </summary>
public readonly record struct EditableRange(int Start, int Length); 