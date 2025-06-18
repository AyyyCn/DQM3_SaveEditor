using System.Collections.Generic;
using System.Threading.Tasks;
using DQM3SaveEditor.Models;

namespace DQM3SaveEditor.Services;

public interface ISaveFileService
{
    Task<(List<Monster> Monsters, List<ItemStack> Inventory, EnvironmentState Environment)> LoadAsync(string path);
    Task SaveAsync(string path, List<Monster> monsters, List<ItemStack> inventory, EnvironmentState environment);
} 