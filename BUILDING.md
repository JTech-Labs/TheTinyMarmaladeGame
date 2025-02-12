# Building
This game is available for purchase on [Itch.io](https://itch.io) and [Steam](https://store.steampowered.com). As per the [`GNU General Public Licene - Version 3.0`](https://www.gnu.org/licenses/gpl-3.0.en.html), you are allowed to see the source code, and thus you may compile it for yourself if you wish.

This project is made with the [`raylib`](https://github.com/raysan5/raylib) all in pure C. This project uses [`raylib-quickstart`](https://github.com/raylib-extras/raylib-quickstart) as a template for the build system, which uses [`premake`](https://premake.github.io/) to genreate the build configurations (e.g. [`GNU make`](https://www.gnu.org/software/make/) or [`Microsoft Visual Studio`](https://visualstudio.microsoft.com/)). Please go check out both the [`raylib`](https://github.com/raysan5/raylib) and [`raylib-quickstart`](https://github.com/raylib-extras/raylib-quickstart). You can currently buy the game on [Itch.io](https://itch.io). If you wish to compile the game yourself, you can do so with the instructions below.

## Supported Platforms
The compiler configurations support the three main desktop platforms:
- GNU+Linux
- Windows
- MacOS

# Compiling
You must download the source code eaither by doing a `git pull` on this repository or download the `.zip` or `.tar.gz` of the source code.

## VScode/codium (all platforms)
*Note* You must have a compiler toolchain installed in addition to VScode/codium, if you don't know how to setup one, follow the intructions for your specific Operating System.

- Open the folder in VScode/codium
- Press `F5` to build
- You are good to go

## Linux
All GNU+Linux distributions work (**NOTE**: You will need the GNU corelibs to be able to compile the game).
Please check and install the GNU+Linux [dependencies](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#dependencies) before you compile.

### Instructions
- Change directory into the `build/` folder
- Run `./premake5 gmake2` (it might give you a warning to use `gmake` instead of `gmake2`, don't worry about it)
- If you are compiling for aarch64 (like a Raspberry Pi), use `./premake5rpi gmake2` instead
- Change directory back to the root of the project
- Run `make`
- You are good to go

If you have any problems making, type `make help`, there are instructions for release or debug versions and different CPU architectures.

## Windows
There are two compiler toolchains avaiable for windows: MinGW-w64 (a free compiler using GCC), and Microsoft visual studio.

### MinGW-w64
Make sure you have a modern version of MinGW-w64 (not mingw).
The best place to get it is from the [`w64devkit`](https://github.com/skeeto/w64devkit) repo releases or the verion installed with the raylib installer.

#### If you have intalled raylib from the installer
Make sure you have added the path

`C:\raylib\w64devkit\bin`

To your path environment variable so that the compiler that came with raylib can be found.

**_DO NOT_ INSTALL ANOTHER MinGW-w64 from another source such as msys2, you don't need it**

#### How to use MinGW-w64
- Double click the `build-MinGW-W64.bat` file
- Change directory into the project root folder in your terminal (`cmd` or `powershell`)
- run `make`
- You are good to go

## MacOS
We do not provide precompiled versions for MacOS as we would need a (very expensice) modern Macintosh and an (also very expensive) Apple comercial developer account, which we cannot afford at this point. However, you can always use compatibiliy software if you wish. You can also compile the source yourself if you can be bothered and wish to.

### How to compile on MacOS
- Change Direcctory into the `build/` folder
- Run `./premake5.osx gmake2`
- Change directory back into the project's root
- Run `make`
- You are good to go

# Output files
The built code will be in the `bin/` directory.

# More
If you want more information, you can run:

`make help`

Which will give you more information on OpenGL targets and architecture targets.

# Licence
Here is the licence for the original compilation system. Also check out the [`raylib-quickstart`](https://github.com/raylib-extras/raylib-quickstart) repo

Copyright (c) 2020-2024 Jeffery Myers

This software is provided "as-is", without any express or implied warranty. In no event 
will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial 
applications, and to alter it and redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim that you 
  wrote the original software. If you use this software in a product, an acknowledgment 
  in the product documentation would be appreciated but is not required.

  2. Altered source versions must be plainly marked as such, and must not be misrepresented
  as being the original software.

  3. This notice may not be removed or altered from any source distribution.
