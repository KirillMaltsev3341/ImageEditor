/**
 * @file ColoredPixels.cpp
 * @brief Implementation of methods for working with memory and cleaning colored pixels data (colored_pixels_ - can be used for some filling algs)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"
#include <stdlib.h>


void ie::ImagePNG::allocateMemmoryForColoredPixels()
{
    colored_pixels_ = (bool**) malloc(sizeof(bool*) * height_);
    for (int y = 0; y < height_; y++) {
        colored_pixels_[y] = (bool*) malloc(sizeof(bool) * width_);
    }
}

void ie::ImagePNG::freeMemmoryForColoredPixels()
{
    for (int y = 0; y < height_; y++) {
        free(colored_pixels_[y]);
    }
    free(colored_pixels_);
}

void ie::ImagePNG::clearColoredPixels()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            colored_pixels_[y][x] = false;
        }
    }
}