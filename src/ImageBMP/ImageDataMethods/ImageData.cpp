/**
 * @file ImageData.cpp
 * @brief Implementation of methods for working with image data (bit_map_)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImageBMP.h"
#include <stdlib.h>


void ie::ImageBMP::allocateMemmoryForBitmap()
{
    bitmap_ = (ColorBGR**) malloc(sizeof(ColorBGR*) * height_);
    for (int y = 0; y < height_; y++) {
        bitmap_[y] = (ColorBGR*) malloc((width_*sizeof(ColorBGR)+3)&(-4));
    }
}

void ie::ImageBMP::freeMemmoryForBitmap()
{
    for (int y = 0; y < height_; y++) {
        free(bitmap_[y]);
    }
    if (bitmap_) {
        free(bitmap_);
    }
}

bool ie::ImageBMP::checkCoordsValidity(int x, int y)
{
    return (x >= 0 && x < width_ && y >= 0 && y < height_);
}


ie::ColorBGR ie::ImageBMP::getColor(int x, int y)
{   
    if (!checkCoordsValidity(x, y)) {
        return {0, 0, 0};
    }
    
    return bitmap_[y][x];
}

void ie::ImageBMP::setColor(int x, int y, ColorBGR color)
{
    if (!checkCoordsValidity(x, y)) {
        return;
    }
    bitmap_[y][x] = color;
}