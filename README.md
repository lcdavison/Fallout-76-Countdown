# Fallout-76-Countdown

[![Build Status](https://travis-ci.org/lcdavison/Fallout-76-Countdown.svg?branch=master)](https://travis-ci.org/lcdavison/Fallout-76-Countdown)

This is a little countdown timer that I coded, to countdown to the release date of Bethesda Game Studios new MMORPG *Fallout 76*.

## Compiling

### Windows - MinGW

```shell
g++ -o f76countdown.exe source/*.cpp -I (Location to MinGW32 includes folder) -L (Location to MinGW32 lib folder) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 
```

### Linux

```bash
g++ -o f76countdown source/*.cpp -I /usr/include/SDL2 -lSDL2 -lSDL2_image -lSDL2_ttf 
```

## To Run

Running the countdown timer requires the following DLL's.

* libstdC++-6.dll	-	Can be found in MinGW's *bin* folder

* SDL2.dll		-	*https://www.libsdl.org/release/SDL2-devel-2.0.8-mingw.tar.gz*
* SDL2_image.dll	-	*https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.3-mingw.tar.gz*
* SDL2_ttf.dll		-	*https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.14-mingw.tar.gz*
* libfreetype-6.dll	-	*Found with SDL_ttf DLL's*
* libjpeg-9.dll		-	*Found with SDL_image DLL's*
* zlib1.dll		-	*Found with SDL_image DLL's*
