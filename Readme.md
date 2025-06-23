# DQM3 Save Editor

*Small fun project I built to learn more about reverse‑engineering Unity/IL2CPP save formats and to practice desktop development with .NET.*

**DQM3 Save Editor** is a lightweight Windows tool that lets you open, tweak, and resave *Dragon Quest Monsters 3* `.bin` save files works both for Windows and Switch version.

---

## Features

| Category        | What you can do                                                           |
| --------------- | ------------------------------------------------------------------------- |
| **Load & Save** | Open any game save, edit freely, and write back a clean, working file.    |
| **Player**      | Change name, play‑time counter, gold, café points & more.                 |
| **Monsters**    | Add / remove monsters, tweak base stats\*, skills, properties, nicknames. |
| **Inventory**   | Add or remove items, set quantities instantly.                            |
| **Unlocks**     | One‑click unlock of all monsters, skills, library entries.                |

> \* Current editor shows the **base** stats that exist in the file.

---

## Project Layout (WPF / MVVM)

```
DQM3SaveEditor/
  ├── App.xaml               # Application startup & resources
  ├── MainWindow.xaml        # Root window with tabbed navigation
  ├── Models/                # POCO models (Monster, Player, Item…)
  ├── ViewModels/            # MVVM glue & commands
  ├── Services/              # File I/O, parsing, helpers
  ├── Converters/            # XAML value converters
  ├── Views/                 # User controls & dialogs
  └── Resources/             # Static game data & images
```

---

## Getting Started

1. **Prerequisite** – [.NET 8 Desktop Runtime](https://dotnet.microsoft.com/en-us/download/dotnet/8.0).
2. **Download** – Grab the latest `DQM3_SaveEditor.zip` from the [Releases](../../releases) page and extract it anywhere.
3. **Run** – Launch `DQM3SaveEditor.exe`, click **Load**, pick your `.bin` file, edit, then **Save**.

---

## Roadmap / Ideas

* Equipment management
* Talent‑adjusted stat calculator
* Story‑progress flags
* Item images
* 
* General UI polish

*The game is niche, so I may not continue feel free to fork and go wild.*

---

## Credits

* **metalkid** – monster ID list & images base [github](https://github.com/MetalKid)
  

---

Released under the MIT License.
