#TiRG-dll
##TiRG text bounding box finder as a dll 32-bit or 64-bit

TiRG-dll has two exported functions for use with _ctypes_ or other foreign function libraries:
```
char* getTextBBoxesFromBytes(char* b, int w, int h);
char* getTextBBoxesFromFile(char* path, int w, int h);
```
The first, **getTextBBoxesFromBytes**, can be passed a bytes object or equivalent. Each byte in the bytes object represents an RGB value of a pixel in the image, so every third byte begins a new pixel. There should be no alpha channel. The second function, **getTextBBoxesFromFile**, takes the path of a raw image file, basically a bytes object written to disk. Both functions require the width and height of the image. 

Both return an identical C string, a comma separated list of integers. The integers are in sets of four where the first two represent the X and Y coordinates of the top left corner of a text bounding box, and the second two represent the X and Y coordinates of the bottom right corner. An example might look like the following.
```
1,8,108,15,1,38,58,45,1,53,58,60,3,83,120,90
```
The above string represents four bounding boxes:
```
(1,8,108,15), (1,38,58,45), (1,53,58,60), (3,83,120,90)
```

Run requirements:
- KERNEL32.dll

Build requires:
- CMake => 3.20
- [Microsoft Visual Studio/Microsoft Visual Code](https://visualstudio.microsoft.com/)]
- [Microsoft Visual C++ Redistributable](https://docs.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist)] => msvc 140

Compiled DLL output
`root\build\source\Release`

Ensures statically linked dependencies with `dumpbin.exe /DEPENDENTS`:
`'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.31.31103\bin\Hostx86\x86\dumpbin.exe' /DEPENDENTS C:\tirg-dll\build\source\Release\tirg-32.dll`

Original website: http://tirg.sourceforge.net

Licensed under Public Domain License, as the original was.