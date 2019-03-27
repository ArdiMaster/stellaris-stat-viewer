# Stellaris Stat Viewer
... for all your galactic stat needs.

[![forthebadge](https://forthebadge.com/images/badges/built-with-resentment.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/uses-badges.svg)](https://forthebadge.com)
[![AppVeyor](https://ci.appveyor.com/api/projects/status/github/ArdiMaster/stellaris-stat-viewer)](https://ci.appveyor.com/project/ArdiMaster/stellaris-stat-viewer)

(work in progress)

Have you ever played Stellaris and just wondered where the heck you stand compared to the other empires?
Well, some friends of mine certainly have, and since Stellaris doesn't provide EU4-style ingame statistics,
I came up with this instead. Stellaris Stat Viewer reads in a Stellaris savegame file and gives you copious
statistics and rankings.

## Features
The user interface looks a lot like a Spreadsheet, because that's what it is. Stellaris Stat Viewer reads in
a save file and displays each empire's power ratings, ships per class, and monthly incomes. For a more
complete listing, see the [user manual](https://github.com/ArdiMaster/stellaris-stat-viewer/wiki/SSV-User-Manual).

If you have ideas for some stat/ranking you'd like to see, open an Issue and I'll see what I can do.

## Building
Stellaris Stat Viewer (or SSV, for short) is build using Qt5 and C++11. It should be possible to compile it
wherever Qt5 and CMake are available (that includes Windows, Mac, and Linux). Here's some rudimentary
instructions on how to do it (I'll elaborate on this once SSV gets closer to being something actually
useful):

**Dependencies**: SSV uses Qt5 (tested with 5.9.5, 5.11.3, 5.12.2), and CMake (version 3.0 or newer).

#### Windows
See the [relevant wiki page](https://github.com/ArdiMaster/stellaris-stat-viewer/wiki/Building-SSV-from-Source).

#### macOS
* Install Qt from [here](https://www.qt.io/download-qt-installer), if you haven't already.
* Install XCode from the Mac App Store, if you haven't already.
* Install CMake through Homebrew or from [here](https://cmake.org/download/), if you haven't already.
* Proceed as indicated under "macOS and Linux (continued)".

#### Linux
* Install make, a C++ compiler, and Qt through your distribution's package manager.
* Proceed as indicated under "macOS and Linux (continued)".

For Ubuntu, the command will look something like this:
```
sudo apt install make g++ cmake qt5-default
```

#### macOS and Linux (continued)
* get ahold of the sources (either via `git clone` or by downloading a ZIP from GitHub)
* navigate to the source folder
* create a new folder for the build, and enter it
* run CMake. Depending on your distribution, you may need to point CMake to the Qt files manually.
Take a peek at the Windows instructions to see how to accomplish that.
* run make

```
cd /path/to/sources
mkdir build
cd build
cmake ..
make
```
