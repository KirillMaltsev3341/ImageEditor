/**
 * @file BresenhamCircle.cpp
 * @brief Implementation of methods for drawing a circle using the Bresenham algorithm (with thickness = 1)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"


void ie::ImagePNG::drawBresenhamCircle(int x0, int y0, int radius, ColorRGBA color)
{
    int D = 3 - 2 * radius;
    int x = 0;
    int y = radius;
    while (x <= y) {
        setColor(x+x0, y+y0, color);
        setColor(y+x0, x+y0, color);
        setColor(-y+x0, x+y0, color);
        setColor(-x+x0, y+y0, color);
        setColor(-x+x0, -y+y0, color);
        setColor(-y+x0, -x+y0, color);
        setColor(y+x0, -x+y0, color);
        setColor(x+x0, -y+y0, color);

        if (D < 0) {
            D += 4 * x + 6;
            x++;
        } else {
            D += 4 * (x - y) + 10;
            x++;
            y--;
        }
    }
}