/**
 * @file ProcessPixels.cpp
 * @brief Implementation of methods for working with pixels (getColor, setColor, etc.)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"


bool ie::ImagePNG::checkCoordsValidity(int x, int y)
{
    return (x >= 0 && x < width_ && y >= 0 && y < height_);
}

void ie::ImagePNG::clear()
{
    clearRowPointers();
    clearColoredPixels();
}

ie::Color ie::ImagePNG::getColor(int x, int y)
{   
    if (!checkCoordsValidity(x, y)) {
        return {0, 0, 0, 0};
    }
    
    Color color;
    color.r = row_pointers_[y][x * pixel_size_ + R_IDX];
    color.g = row_pointers_[y][x * pixel_size_ + G_IDX];
    color.b = row_pointers_[y][x * pixel_size_ + B_IDX];
    color.a = row_pointers_[y][x * pixel_size_ + A_IDX];
    return color;
}

void ie::ImagePNG::setColor(int x, int y, Color color)
{
    if (!checkCoordsValidity(x, y)) {
        return;
    }
    colored_pixels_[y][x] = true;
    row_pointers_[y][x * pixel_size_ + R_IDX] = color.r;
    row_pointers_[y][x * pixel_size_ + G_IDX] = color.g;
    row_pointers_[y][x * pixel_size_ + B_IDX] = color.b;
    row_pointers_[y][x * pixel_size_ + A_IDX] = color.a;
}

bool ie::ImagePNG::isColored(int x, int y)
{
    if (!checkCoordsValidity(x, y)) {
        return false;
    }
    return colored_pixels_[y][x];
}