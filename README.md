# Learning SDL2
## WARNING! This project is no longer maintained.
## This project is a platformer in making using SDL2
### Description
I love programming, specially in lower level languages like *C/C++*. But when I started learning the [Godot game engine](https://godotengine.org),
I had to use *GDScript*. I lost my motivation back then, and didn't try to make a game again.  
Late last year though, I discovered a channel called **PolyMars**. He uses different libraries to make small games for game jams. To make things harder, 
he picks up a new library every game jam, learns it and uses to make his game that he submites to a specific jam. I saw him making a platformer game using 
the **SDL2** library. I got really interested, and after some research I learned more about **SDL2**. Following the [**codergopher**'s SDL2 tutorial](https://www.youtube.com/watch?v=KsG6dJlLBDw&list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS),
I started this project.  

The `main` branch follows the main tutorial until part 8, `latest` branch continues **codergopher's** unfinished game and `rewrite` branch contains newly structered project code base.

### How to run the project
The project currently depends on `SDL2` and `SDL2_image`. This has been only tested on **Windows** and **Arch Linux**, but it's possible to port it to other platforms.
**SDL2** is a *low level* yet *cross platform* library.

If you are using **Windows**, compile and run the project using [CMake](https://cmake.org/) with these commands in the **Visual Studio Developer Command Prompt**:
``` 
git submodule update --recursive
vcpkg\bootstrap-vcpkg.bat
vcpkg\vcpkg install sdl2 sdl2-image
cmake -Bbuild -S.
cmake --build build
Debug\main.exe
```

If you are using **Linux**, I recommend to use [Ninja](https://ninja-build.org/) for faster builds:
```
git submodule update --recursive
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install sdl2 sdl2-image
cmake -Bbuild/ -S. -G"Ninja"
cmake --build build
./main
```

#### There is nothing you can do in this game though. The game doesn't receive any keyboard inputs, this is a demo of how the game may look in the future.
