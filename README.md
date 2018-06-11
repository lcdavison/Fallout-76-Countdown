# Fallout-76-Countdown

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

* libfreetype-6.dll
* libjpeg-9.dll
* libstdC++-6.dll
* SDL2.dll
* SDL2_image.dll
* SDL2_ttf.dll
* zlib1.dll
