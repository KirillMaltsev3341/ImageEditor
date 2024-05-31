/**
 * @file ProcessColors.cpp
 * @brief Implementation of methods for working with color correction (inverse (inverse colors), gray (convert to black and white), etc.)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImageBMP.h"


void ie::ImageBMP::clear()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            setColor(x, y, {0, 0, 0});
        }
    }
}

void ie::ImageBMP::colorReplace(ColorBGR old_color, ColorBGR new_color)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (getColor(x, y) == old_color) {
                setColor(x, y, new_color);
            }
        }
    }
}

void ie::ImageBMP::bgrFilter(int component_idx, unsigned char component_value)
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            
            ColorBGR color = getColor(x, y);

            if (component_idx == R_IDX) {
                color.r = component_value;
            } else if (component_idx == G_IDX) {
                color.g = component_value;
            } else if (component_idx == B_IDX) {
                color.b = component_value;
            }
            
            setColor(x, y, color);
        }
    }
}

void ie::ImageBMP::inverseColors()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            ColorBGR color = getColor(x, y);
            color.inverse();
            setColor(x, y, color);
        }
    }
}

void ie::ImageBMP::grayColors()
{
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            ColorBGR color = getColor(x, y);
            color.gray();
            setColor(x, y, color);
        }
    }
}