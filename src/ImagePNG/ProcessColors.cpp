/**
 * @file ProcessColors.cpp
 * @brief Implementation of methods for working with color correction (inverse (inverse colors), gray (convert to black and white), etc.)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"


void ie::ImagePNG::colorReplace(Color old_color, Color new_color)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (getColor(x, y) == old_color) {
                setColor(x, y, new_color);
            }
        }
    }
}

void ie::ImagePNG::rgbaFilter(int component_idx, int component_value)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            row_pointers_[y][x * pixel_size_ + component_idx] = component_value;
        }
    }
}

void ie::ImagePNG::inverseColors()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            Color color = getColor(x, y);
            color.inverse();
            setColor(x, y, color);
        }
    }
}

void ie::ImagePNG::grayColors()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            Color color = getColor(x, y);
            color.gray();
            setColor(x, y, color);
        }
    }
}