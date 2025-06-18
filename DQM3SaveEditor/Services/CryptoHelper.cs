using System;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;

namespace DQM3SaveEditor.Services;

/// <summary>
/// Helper for AES-256-CBC + DEFLATE/INFLATE. No external deps. All static.
/// </summary>
public static class CryptoHelper
{
    private static readonly byte[] Key = Encoding.UTF8.GetBytes("xas1p290,z7g;:.,jafaba1278h4k7zl");
    private static readonly byte[] IV = Encoding.UTF8.GetBytes("hi9mrk48dcsa9abl");

    public static byte[] Decrypt(ReadOnlySpan<byte> cipher)
    {
        // AES-256-CBC, PKCS7
        using var aes = Aes.Create();
        aes.Key = Key;
        aes.IV = IV;
        aes.Mode = CipherMode.CBC;
        aes.Padding = PaddingMode.PKCS7;
        using var decryptor = aes.CreateDecryptor();
        return decryptor.TransformFinalBlock(cipher.ToArray(), 0, cipher.Length);
    }

    public static byte[] Encrypt(ReadOnlySpan<byte> clear)
    {
        // AES-256-CBC, PKCS7
        using var aes = Aes.Create();
        aes.Key = Key;
        aes.IV = IV;
        aes.Mode = CipherMode.CBC;
        aes.Padding = PaddingMode.PKCS7;
        using var encryptor = aes.CreateEncryptor();
        return encryptor.TransformFinalBlock(clear.ToArray(), 0, clear.Length);
    }

    public static byte[] Inflate(ReadOnlySpan<byte> compressed)
    {
        // Raw DEFLATE (RFC 1951, no zlib header)
        using var msIn = new MemoryStream(compressed.ToArray());
        using var deflate = new DeflateStream(msIn, CompressionMode.Decompress, true);
        using var msOut = new MemoryStream();
        deflate.CopyTo(msOut);
        return msOut.ToArray();
    }

    public static byte[] Deflate(ReadOnlySpan<byte> clear)
    {
        // Raw DEFLATE (RFC 1951, no zlib header)
        using var msOut = new MemoryStream();
        using (var deflate = new DeflateStream(msOut, CompressionLevel.Optimal, true))
        {
            deflate.Write(clear);
        }
        return msOut.ToArray();
    }
} 