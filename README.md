# ImageEditor

A library with basic image processing functionality.  
Types of files that can be processed:
- PNG
- BMP

## Сontent
- [Preliminary requirements](#preliminary-requirements)
- [Installation](#installation)
  - [Quick installation](#quick-installation)
  - [Manually installation](#manually-installation)
- [Testing](#testing)
- [Example](#example)
- [Agreements](#agreements)
- [Additionally](#additionally)

<a name="preliminary-requirements"></a>
## Preliminary requirements
- libpng
- zlib


<a name="installation"></a>
## Installation

<a name="quick-installation"></a>
### Quick installation

```bash
git clone https://github.com/KirillMaltsev3341/ImageEditor.git
cd ImageEditor
make install_required_soft
make
```

<a name="manually-installation"></a>
### Manually installation
To install required software by yourself visit:
- [libpng](https://github.com/pnggroup/libpng) (with a normal installation, zlib is automatically installed)
- [zlib](https://github.com/madler/zlib)

```bash
git clone https://github.com/KirillMaltsev3341/ImageEditor.git
cd ImageEditor
make
```

The shared library will be located in the ***lib*** folder and will have the name ***libImageEditor.so***


<a name="testing"></a>
## Testing

```bash
make test
```

<a name="example"></a>
## Example

```C++
#include "ImageEditor.h"

int main()
{
    ie::ImagePNG image;
    image.setSize(400, 400);

    image.drawCircle(200, 200, 120, 8, {255, 0, 0, 255}, true, {0, 0, 255, 255});
    
    image.drawPolygon(
        {
            {118, 120},
            {282, 120},
            {200, 314}
        }, 2, {255, 255, 255, 255}, true, {0, 255, 0, 255}
    );

    image.writeImageToFile("result.png");
}
```

```bash
g++ main.cpp -I{...}/ImageEditor/include -Wl,-rpath={...}/ImageEditor/lib -L{...}/ImageEditor/lib -lImageEditor
```

Result:  
![Image alt](https://github.com/KirillMaltsev3341/Images/raw/main/result.png)

<a name="agreements"></a>
## Agreements
  1. The global discrete coordinates of a pixel are located in its center.  
![Image alt](https://github.com/KirillMaltsev3341/Images/raw/main/Coordinates.png)


<a name="additionally"></a>
## Additionally
first: OF COURSE, THE PROJECT STRUCTURE IS FAR FROM PERFECT, but who cares lol...  
second: just look here [source of inspiration](https://github.com/SFML/SFML)  
CPP files are removed after building, soooooo draw conclusions  
it was possible to make 100500 inheritances and layers of abstraction but I am lazy ass  
Haters be like:  
![Image alt](https://github.com/KirillMaltsev3341/Images/raw/main/Hater.jpeg)
