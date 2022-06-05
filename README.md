Graphics Engine OpenGl
=====================

Requirements
------------

- Windows operating system preferable (did not test it on mac)
- Visual Studio 2022
- SDL2
- GLEW3
- Assimp 5.0.1

Linking with external libraries
-----------

Create a folder named `linking` in the root of the project directory.

Create 2 sub directories `"linking\include"` and `"linking\lib"`.

### SDL
1. Install [SDL2 development libraries](https://www.libsdl.org/download-2.0.php)
2. Copy the contents of `"include"` from the zip file to `"linking\include\SDL"`
3. Copy `"lib\x64\SDL2.lib"` and `"lib\x64\SDL2main.lib"` from the zip file to `"linking\lib"`
4. Copy `"lib\x64\SDL2.dll"` from the zip file to the directory where the `main.cpp` file is located

### GLEW
1. Install [GLEW binaries](http://glew.sourceforge.net/index.html)
2. Copy the `"include\GL"` folder from the zip file to `"linking\include"`
3. Copy the `"lib\Release\x64\glew32.lib"` from the zip file to `"linking\lib"`
4. Copy `"bin\Release\x64\glew32.dll"` from the zip file to the directory where the `main.cpp` file is located

### GLM
1. Install [GLM](https://glm.g-truc.net/0.9.9/index.html)
2. Copy the `"glm"` folder from the zip file to `"linking\include"`

### Assimp 5.0.1

1. Install [Assimp 5.0.1 source code](https://github.com/assimp/assimp/releases), scroll down to find version `5.0.1`
2. Copy the `"include\assimp"` folder from the zip file to `"linking\include"`
3. Using CMake configure and generate a visual studio 2022 project.
4. Open up `Assimp.sln`, select `ALL_BUILD` from the solution explorer and run in release mode
5. Copy the `"include\assimp"` folder from the CMake assimp project to `"linking\include"`
6. Copy the `"code\Release\assimp-vs143-mt.lib` from the CMake assimp project to `"linking\lib"`
7. Copy the `"code\Relaese\assimp-vs143-mt.dll` from the CMake assimp project to the directory where the `main.cpp` file is located

Open up `opengl-engine-vs.sln` and run the program on `x64`.