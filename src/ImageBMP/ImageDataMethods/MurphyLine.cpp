/**
 * @file MurphyLine.cpp
 * @brief Implementation of methods for drawing a line using the Murphy algorithm (with any thickness)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImageBMP.h"
#include <algorithm>


void ie::ImageBMP::drawMurphyLine(int x0, int y0, int x1, int y1, 
    int thickness, ColorBGR color)
{
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        for (int i = 0; i <= thickness/2; i++) {
            drawBresenhamLineLow(x0, y0-i, x1, y1-i, color);
            drawBresenhamLineLow(x0, y0+i, x1, y1+i, color);
        }
    } else {
        if (y0 > y1) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        for (int i = 0; i <= thickness/2; i++) {
            drawBresenhamLineHigh(x0-i, y0, x1-i, y1, color);
            drawBresenhamLineHigh(x0+i, y0, x1+i, y1, color);
        }
    }
}