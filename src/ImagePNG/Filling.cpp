/**
 * @file Filling.cpp
 * @brief Implementation of methods for filling algs
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"
#include <queue>


void ie::ImagePNG::floodFill(int x, int y, Color color)
{
    std::queue<Coord> coords;
    coords.push({x, y});

    while (!coords.empty()) {
        Coord coord = coords.front();
        if (checkCoordsValidity(coord.x, coord.y) && !isColored(coord.x, coord.y)) {
            setColor(coord.x, coord.y, color);
            coords.push({coord.x+1, coord.y});
            coords.push({coord.x-1, coord.y});
            coords.push({coord.x, coord.y+1});
            coords.push({coord.x, coord.y-1});
        }
        coords.pop();
    }
}

void ie::ImagePNG::fill(int x, int y, Color color)
{
    clearColoredPixels();
    Color start_color = getColor(x, y);

    std::queue<Coord> coords;
    coords.push({x, y});

    while (!coords.empty()) {
        Coord coord = coords.front();
        if (checkCoordsValidity(coord.x, coord.y) && 
            getColor(coord.x, coord.y) == start_color && 
            !isColored(coord.x, coord.y)) {
            
            setColor(coord.x, coord.y, color);
            coords.push({coord.x+1, coord.y});
            coords.push({coord.x-1, coord.y});
            coords.push({coord.x, coord.y+1});
            coords.push({coord.x, coord.y-1});
        }
        coords.pop();
    }
}