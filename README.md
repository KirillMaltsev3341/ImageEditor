# ImageEditor

A library with basic image processing functionality.  
Types of files that can be processed:
- PNG
- ~~BMP~~

## Сontent
- [Preliminary requirements](#preliminary-requirements)
- [Installation](#installation)
  - [Quick installation](#quick-installation)
  - [Manually installation](#manually-installation)
- [Testing](#tesing)
- [Compilation](#compilation)
- [Agreements](#agreements)

<a name="preliminary-requirements"></a>
## Preliminary requirements
- g++
- make
- libpng (+zlib)


<a name="installation"></a>
## Installation

<a name="quick-installation"></a>
### Quick installation
If you want a quick installation, just enter these lines into the console:

```
git clone ...
cd ImageEditor
make install_required_soft
make
```

<a name="manually-installation"></a>
### Manually installation
To install required software by yourself visit:
- [libpng](https://github.com/pnggroup/libpng) (with a normal installation, zlib is automatically installed)
- [zlib](https://github.com/madler/zlib)

Next, enter these lines into the console:

```bash
git clone ...
cd ImageEditor
make
```

The shared library will be located in the **lib** folder and will have the name *libImageEditor.so*


<a name="testing"></a>
## Testing
To check if everything is working correctly use:

```bash
make test
```

<a name="compilation"></a>
## Compilation
Example code:

```C++
#include "ImageEditor.h"

int main()
{
    ie::ImagePNG image;
    image.setSize(800, 800);

    image.drawCircle(150, 200, 40, 8, {255, 0, 255, 255}, true, {0, 0, 255, 255});
    
    image.drawPolygon(
        {
            {400, 400},
            {580, 350},
            {500, 560}
        }, 4, {255, 255, 255, 255}, true, {0, 128, 0, 255}
    );

    image.writeImageToFile("result.png");
}
```

To compile it:

```bash
g++ main.cpp -Wl,-rpath={...}/ImageEditor/lib -L{...}/ImageEditor/lib -lImageEditor -I{...}/ImageEditor/include
```

After running the a.out file, you should get the result.png file

<a name="agreements"></a>
## Agreements
- 1. The global discrete coordinates of a pixel are located in its center.  
![Image alt](https://github.com/KirillMaltsev3341/Images/raw/main/Coordinates.png)