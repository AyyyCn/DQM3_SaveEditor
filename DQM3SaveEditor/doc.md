# DQM3SaveEditor

## Overview

**DQM3SaveEditor** is a Windows desktop application (WPF, .NET 8) for editing save files of the game "Dragon Quest Monsters 3". It provides a graphical interface to view and modify player data, monsters, inventory, and environment state within a save file. The application supports loading and saving `.bin` save files, unlocking all monsters/skills/library entries.

---

## Table of Contents

- [DQM3SaveEditor](#dqm3saveeditor)
  - [Overview](#overview)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Project Structure](#project-structure)
  - [Core Components](#core-components)
    - [Models](#models)
    - [ViewModels](#viewmodels)
    - [Services](#services)
    - [Converters](#converters)
    - [Views](#views)
  - [Resources](#resources)
  - [How to Build and Run](#how-to-build-and-run)

---

## Features

- **Load/Save DQM3 Save Files**: Open and edit `.bin` save files.
- **Edit Player Data**: Name, playtime, gold, cafe points, etc.
- **Manage Monsters**: Add, edit, delete monsters; edit stats, skills, and properties.
- **Inventory Management**: Add/remove items, edit item counts.
- **Unlock Features**: Unlock all monsters, skills, or library entries with one click.
- **Robust Test Suite**: xUnit-based tests for all major components.

---

## Project Structure

```
DQM3SaveEditor/
  ├── App.xaml, App.xaml.cs         # Application entry and resources
  ├── MainWindow.xaml, .cs          # Main window and code-behind
  ├── Models/                       # Data models (Monster, Player, etc.)
  ├── ViewModels/                   # ViewModels for MVVM pattern
  ├── Services/                     # Business logic and file operations
  ├── Converters/                   # WPF value converters
  ├── Views/                        # User controls and dialogs
  ├── Resources/                    # Game data, images, and static files
  ├── DQM3SaveEditor.csproj         # Project file
 
```

---

## Core Components

### Models

- **Monster.cs**: Represents a monster, including stats, skills, and metadata.
- **PlayerState.cs**: Player information (name, gold, playtime, etc.).
- **EnvironmentState.cs**: Game environment (season, weather).
- **ItemStack.cs**: Inventory item and count.
- **SkillAllocation.cs**: Skill points assigned to a monster.
- **SaveMeta.cs**: In-memory bridge between raw save data and UI models.

### ViewModels

Implements the MVVM pattern for UI logic and data binding.

- **MainViewModel**: Central view model, coordinates loading/saving, and tab navigation.
- **MonstersViewModel**: Manages the monster collection and related commands.
- **MonsterViewModel**: Represents a single monster for editing.
- **PlayerViewModel**: Player data for binding/editing.
- **InventoryViewModel**: Inventory management.
- **EnvironmentViewModel**: Environment state.
- **LibraryViewModel**: (Planned) Unlocking books/monsters in the library.
- **RelayCommand, ViewModelBase**: MVVM infrastructure.

### Services

- **SaveFileService**: Handles loading and saving of save files.
- **SaveBlobParser**: Parses raw save file data into models.
- **MonsterMappingService**: Maps monster names/IDs, supports localization.
- **TalentService**: Loads and manages talent/skill data.
- **CryptoHelper**: (If present) Handles encryption/decryption for save files.
- **OffsetTracker, EditableRange**: Utilities for byte-level file operations.

### Converters

- **BoolToDirtyMarkConverter**: Shows a mark if there are unsaved changes.
- **ImagePathToBitmapConverter**: Loads monster images for the UI.
- **SkillsCountToVisibilityConverter**: Controls visibility based on skill count.

### Views

- **MainWindow.xaml**: Main application window with tabs for Player, Monsters, Inventory.
- **MonsterCard.xaml**: User control for displaying/editing a monster.
- **MonsterEditDialog.xaml**: Dialog for editing monster details.
- **MonsterSelectionDialog.xaml**: Dialog for selecting a monster from the library.

---

## Resources

- **Resources/MonsterImages/**: Contains images for each monster.
- **Resources/Monster.json**: Monster metadata (names, IDs, etc.).
- **Resources/library.txt, talent.txt**: Static data for library and talents.
- **Resources/completelibrary**: (Purpose inferred: possibly for full unlock features).


---

## How to Build and Run

1. **Requirements**:
   - .NET 8 SDK
   - Windows OS (uses WPF)
2. **Build**:
   - Open in Visual Studio and build the solution, or run `dotnet build`.
3. **Run**:
   - Start the app from Visual Studio or run `dotnet run` in the project directory.
4. **Edit Save Files**:
   - Use the "Load" button to open a `.bin` save file.
   - Edit player, monsters, or inventory as needed.
   - Click "Save" to write changes to a new or existing file.

---


