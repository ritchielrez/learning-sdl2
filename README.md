# Learning SDL2
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
The project currently depends on `SDL2` and `SDL2_image`. This has been only tested on **Windows**, but it's possible to port it to other platforms.
**SDL2** is a *low level* yet *cross platform* library. You will need to edit `CMakeLists.txt`, in order to compile the project using **MinGW**.  

If you're using the latest **Visual Studio**, then great! Just install [vcpkg](https://vcpkg.io), which helps us to install external libraries.
After setting up `vcpkg`, run the following command in `Visual Studio Developer Command Prompt`:
```
vcpkg install sdl2 sdl2-image
```

Then compile and run the project using [CMake](https://cmake.org/):
``` 
cmake -Bbuild/ -S.
cd build
MSBuild.exe -m learning-sdl2.sln
./Debug/main.exe
```

#### There is nothing you can do there though. The game doesn't receive any keyboard inputs, this is more like a demo, which still took quite some time to make :)
