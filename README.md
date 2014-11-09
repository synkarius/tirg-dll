#TiRG-dll
##TiRG text bounding box finder as a dll

TiRG-dll has two exported functions for use with _ctypes_ or other foreign function libraries:
```
char* getTextBBoxesFromBytes(char* b, int w, int h);
char* getTextBBoxesFromFile(char* path, int w, int h);
```
The first, _getTextBBoxesFromBytes_, can be passed a bytes object or equivalent. Each byte in the bytes object represents an RGB value of a pixel in the image, so every third byte begins a new pixel. There should be no alpha channel. The second, _getTextBBoxesFromFile_, takes the path of a raw image file, basically a bytes object written to disk. Both functions require the width and height of the image. 

Both return an identical C string, a comma separated list of integers. The integers are in sets of four where the first two represent the X and Y coordinates of the top left corner of a text bounding box, and the second two represent the X and Y coordinates of the bottom right corner. An example might look like the following.
```
1,8,108,15,1,38,58,45,1,53,58,60,3,83,120,90
```
The above string represents four bounding boxes:
```
(1,8,108,15), (1,38,58,45), (1,53,58,60), (3,83,120,90)
```


Original website: http://tirg.sourceforge.net

Licensed under Public Domain License, as the original was.
