/**
 * @file Circle.cpp
 * @brief Implementation of methods for drawing a circle (with any thickness)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImageBMP.h"
#include <algorithm>


bool ie::ImageBMP::checkOnCircleLine(int x, int y, int x0, int y0, int radius, int thickness)
{
    bool flag1 = (x-x0)*(x-x0) + (y-y0)*(y-y0) <= (radius+thickness/2)*(radius+thickness/2);
    bool flag2 = (x-x0)*(x-x0) + (y-y0)*(y-y0) >= (std::max(0, radius-thickness/2))*(std::max(0, radius-thickness/2));
    return flag1 && flag2;
}

bool ie::ImageBMP::checkInCircle(int x, int y, int x0, int y0, int radius, int thickness)
{
    bool flag = (x-x0)*(x-x0) + (y-y0)*(y-y0) <= (radius-thickness/2)*(radius-thickness/2);
    return flag;
}

void ie::ImageBMP::drawCircle(int x0, int y0, int radius, int thickness, 
    ColorBGR color, bool fill, ColorBGR fill_color)
{
    for (int y = std::max(0, y0-radius-thickness/2); y <= std::min(height_-1, y0+radius+thickness/2); y++) {
        for (int x = std::max(0, x0-radius-thickness/2); x <= std::min(width_-1, x0+radius+thickness/2); x++) {
            if (fill && checkInCircle(x, y, x0, y0, radius, thickness)) {
                setColor(x, y, fill_color);
            }
            if (checkOnCircleLine(x, y, x0, y0, radius, thickness)) {
                setColor(x, y, color);
            }
        }
    }

    drawBresenhamCircle(x0, y0, radius-thickness/2, color);
    drawBresenhamCircle(x0, y0, radius+thickness/2, color);
}