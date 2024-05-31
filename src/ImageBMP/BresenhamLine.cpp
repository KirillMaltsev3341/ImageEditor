/**
 * @file BresenhamLine.cpp
 * @brief Implementation of methods for drawing a line using the Bresenham algorithm (with thickness = 1)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImageBMP.h"
#include <algorithm>


void ie::ImageBMP::drawBresenhamLineLow(int x0, int y0, int x1, int y1, ColorBGR color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    int D = 2 * dy - dx;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        setColor(x, y, color);        

        if (D > 0) {
            y += yi;
            D += 2 * (dy - dx);
        } else {
            D += 2 * dy;
        }
    }
}

void ie::ImageBMP::drawBresenhamLineHigh(int x0, int y0, int x1, int y1, ColorBGR color)
{

    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = x0;
    for (int y = y0; y <= y1; y++) {
        setColor(x, y, color);

        if (D > 0) {
            x += xi;
            D += 2 * (dx - dy);
        } else {
            D += 2 * dx;
        }
    }
}

void ie::ImageBMP::drawBresenhamLine(int x0, int y0, int x1, int y1, ColorBGR color)
{
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        drawBresenhamLineLow(x0, y0, x1, y1, color);
    } else {
        if (y0 > y1) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        drawBresenhamLineHigh(x0, y0, x1, y1, color);
    }
}