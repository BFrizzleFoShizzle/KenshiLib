# KenshiLib
KenshiLib is a library that reconstructs Kenshi's structures, exporting a version-independent API for accessing variables and calling and hooking methods.

KenshiLib is released under the GPLv3, please be aware that this generally means KenshiLib plugins must also be released under the GPLv3. KenshiLib also contains 3rd-party components with additional licenses.

## Developing RE_Kenshi/KenshiLib plugins
Example KenshiLib plugins can be found [here](https://github.com/BFrizzleFoShizzle/KenshiLib_Examples/).

The easiest way to set up standard plugin dependencies is to use the [KenshiLib_Examples dependencies](https://github.com/BFrizzleFoShizzle/KenshiLib_Examples_deps) repo, which comes with all required KenshiLib includes + precompiled libs for KenshiLib/Ogre/Boost/Etc.

The steps for setting up a new KenshiLib plugin:  
Set the compiler toolchain to Visual Studio 2010.  
Add KenshiLib's `Include` dir to your includes.  
Add Boost 1.60.0 includes.  
Add KenshiLib + OgreMain .lib files to the linker input (OgreMain .lib is in the KenshiLib repo, KenshiLib .lib is included in [KenshiLib releases](https://github.com/KenshiReclaimer/KenshiLib/releases)).

### Plugin Best-practices
DO use KenshiLib's built-in function hooking system, it is designed to handle multiple plugins hooking the same function.  
DON'T use 3rd-party function hooking/detouring libraries as these can cause issues when multiple plugins hook the same function using different libraries.  
DON'T access the UI from non-UI threads. Most MyGUI functions are NOT thread-safe, this will cause race conditions that will intermittently crash the game.  
If you are exporting functions for other plugins to use, it is wise to make your plugin a Preload Plugin (doccumentation coming) so that it is loaded before other plugins.

## Compiling

Requires Visual Studio 2019 or newer and the Visual C++ 2010 x64 compilers. KenshiLib MUST be compiled using the Visual Studio 2010 compiler. Copies of Visual Studio 2010 can be found on the [Wayback Machine](https://archive.org/search?query=visual+studio+2010).

You may also require the VS2010 SP1 update (also available above).

![Image](https://github.com/user-attachments/assets/fd4db477-d0dc-4449-99c9-8b343c95a5a1)

Also requires [boost 1.60.0](https://www.boost.org/releases/1.60.0/) and the `multihook` version of [MinHook](https://github.com/m417z/minhook/tree/multihook).

Open the project and compile in RELEASE mode. DEBUG is currently broken.
