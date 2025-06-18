// Services/SaveFileService.cs
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
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
    #region ISaveFileService – API publique ----------------------------------------------------

    public async Task<(List<Monster> Monsters,
                       List<ItemStack> Inventory,
                       EnvironmentState Environment)>
        LoadAsync(string path)
    {
        var (blob, meta) = await DecryptAndParseAsync(path);

        // Map vers modèles WPF (shallow copy suffisant)
        var monsters = new List<Monster>(meta.ExportMonsters());
        var inventory = new List<ItemStack>(meta.Inventory);
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
        // 1. Lire + parser fichier existant
        var (blob, meta) = await DecryptAndParseAsync(path);

        // 2. Injecter les modifications en mémoire
        meta.Season = environment.Season;
        meta.Weather = environment.Weather;
        meta.Inventory = inventory;             // remplace la liste
        meta.ImportMonsters(monsters);          // met à jour en conservant les ID

        // 3. Demander au parser le blob patché
        var patchedBlob = SaveBlobParser.ApplyChanges(blob, meta);

        // 4. Re-chiffrer + ré-écrire
        await EncryptAndWriteAsync(path, patchedBlob);
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
