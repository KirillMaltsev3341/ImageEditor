/**
 * @file ImageBMP.cpp
 * @brief Implementation of the class constructor and destructor + showImageInfo method
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImageBMP.h"
#include <stdlib.h>
#include <stdio.h>


ie::ImageBMP::ImageBMP() :
    bmp_header_
    {
        BMP_SIGNATURE,
        static_cast<unsigned char>( (width_*height_)*3+sizeof(bmp_header_)+sizeof(dib_header_) ),
        0,
        0,
        sizeof(bmp_header_)+sizeof(dib_header_)
    },

    dib_header_
    {
        sizeof(dib_header_),
        static_cast<unsigned int>(width_),
        static_cast<unsigned int>(height_),
        1,
        BMP_BITS_PER_PIXEL,
        BMP_COMPRESSION,
        static_cast<unsigned int>(height_*width_)*3,
        0,
        0,
        0,
        0
    },
    
    width_(0),
    height_(0),
    bitmap_(NULL)
{}

ie::ImageBMP::~ImageBMP()
{
    freeMemmoryForBitmap();
}

void ie::ImageBMP::showInfo()
{
    printf("%d x %d, %d-bit/color\n", width_, height_, BMP_BITS_PER_PIXEL);
}