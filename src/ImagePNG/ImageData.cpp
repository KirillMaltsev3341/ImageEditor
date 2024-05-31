/**
 * @file ImageData.cpp
 * @brief Implementation of methods for working with image data (row_pointers_)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"
#include <stdlib.h>


void ie::ImagePNG::allocateMemmoryForRowPointers()
{
    row_pointers_ = (png_bytepp) malloc(sizeof(png_bytep) * height_);
    for (int y = 0; y < height_; y++) {
        row_pointers_[y] = (png_bytep) malloc(sizeof(png_byte) * pixel_size_ * width_);
    }
}

void ie::ImagePNG::freeMemmoryForRowPointers()
{
    for (int y = 0; y < height_; y++) {
        free(row_pointers_[y]);
    }
    if (row_pointers_) {
        free(row_pointers_);
    }
}

bool ie::ImagePNG::checkCoordsValidity(int x, int y)
{
    return (x >= 0 && x < width_ && y >= 0 && y < height_);
}

ie::ColorRGBA ie::ImagePNG::getColor(int x, int y)
{   
    if (!checkCoordsValidity(x, y)) {
        return {0, 0, 0, 0};
    }
    
    ColorRGBA color;
    color.r = row_pointers_[y][x * pixel_size_ + R_IDX];
    color.g = row_pointers_[y][x * pixel_size_ + G_IDX];
    color.b = row_pointers_[y][x * pixel_size_ + B_IDX];
    color.a = row_pointers_[y][x * pixel_size_ + A_IDX];
    return color;
}

void ie::ImagePNG::setColor(int x, int y, ColorRGBA color)
{
    if (!checkCoordsValidity(x, y)) {
        return;
    }
    row_pointers_[y][x * pixel_size_ + R_IDX] = color.r;
    row_pointers_[y][x * pixel_size_ + G_IDX] = color.g;
    row_pointers_[y][x * pixel_size_ + B_IDX] = color.b;
    row_pointers_[y][x * pixel_size_ + A_IDX] = color.a;
}
