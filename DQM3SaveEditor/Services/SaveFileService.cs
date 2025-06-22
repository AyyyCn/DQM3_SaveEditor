// Services/SaveFileService.cs
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.Services;

/// <summary>
/// Concrete ISaveFileService – utilise SaveBlobParser pour lire/patcher
/// sans reproduire le sérialiseur propriétaire du jeu.
/// </summary>
public sealed class SaveFileService : ISaveFileService
{
    private string _currentBlob = "";
    private SaveMeta? _currentMeta = null;

    #region ISaveFileService – API publique ----------------------------------------------------

    public async Task<(List<Monster> Monsters,
                       List<ItemStack> Inventory,
                       EnvironmentState Environment)>
        LoadAsync(string path)
    {
        var (blob, meta) = await DecryptAndParseAsync(path);
        
        // Store the current blob and meta for saving
        _currentBlob = blob;
        _currentMeta = meta;

        // Map vers modèles WPF (shallow copy suffisant)
        var monsters = meta.ExportMonsters().ToList();
        var inventory = meta.ExportInventory().ToList();
        var env = new EnvironmentState
        {
            Season = meta.Season,
            Weather = meta.Weather
        };
        return (monsters, inventory, env);
    }

    public async Task SaveAsync(string path,
                                List<Monster> monsters,
                                List<ItemStack> inventory,
                                EnvironmentState environment)
    {
        Console.WriteLine("=== SaveFileService.SaveAsync STARTED ===");
        Console.WriteLine($"Path: {path}");
        Console.WriteLine($"Monsters: {monsters.Count}");
        Console.WriteLine($"Inventory: {inventory.Count}");
        Console.WriteLine($"Environment: Season={environment.Season}, Weather={environment.Weather}");
        
        if (_currentMeta == null)
        {
            throw new InvalidOperationException("No save file has been loaded. Please load a save file first.");
        }
        
        Console.WriteLine($"Using cached blob length: {_currentBlob.Length}");
        Console.WriteLine($"Cached meta - Monsters: {_currentMeta.Monsters.Count}, Inventory: {_currentMeta.Inventory.Count}");

        // 2. Injecter les modifications en mémoire
        _currentMeta.Season = environment.Season;
        _currentMeta.Weather = environment.Weather;
        _currentMeta.ImportInventory(inventory);
        _currentMeta.ImportMonsters(monsters);
        Console.WriteLine("Imported changes to meta");

        // 3. Demander au parser le blob patché
        var patchedBlob = SaveBlobParser.ApplyChanges(_currentBlob, _currentMeta);
        Console.WriteLine($"Patched blob length: {patchedBlob.Length}");

        // 4. Re-chiffrer + ré-écrire
        await EncryptAndWriteAsync(path, patchedBlob);
        Console.WriteLine("=== SaveFileService.SaveAsync COMPLETED ===");
    }

    #endregion -------------------------------------------------------------------------------

    #region Helpers ----------------------------------------------------------------------------

    private static async Task<(string Blob, SaveMeta Meta)> DecryptAndParseAsync(string path)
    {
        // ---- I/O : lecture + decryption + inflate ----
        var encrypted = await File.ReadAllBytesAsync(path);
        var compressed = CryptoHelper.Decrypt(encrypted);
        var clearBytes = CryptoHelper.Inflate(compressed);
        var blob = Encoding.UTF8.GetString(clearBytes);

        // ---- Parsing rapide (span/regex) ----
        var meta = SaveBlobParser.Parse(blob);
        return (blob, meta);
    }

    private static async Task EncryptAndWriteAsync(string path, string patchedBlob)
    {
        var patchedBytes = Encoding.UTF8.GetBytes(patchedBlob);
        var compressed = CryptoHelper.Deflate(patchedBytes);
        var encrypted = CryptoHelper.Encrypt(compressed);
        await File.WriteAllBytesAsync(path, encrypted);
    }

    #endregion -------------------------------------------------------------------------------
}
