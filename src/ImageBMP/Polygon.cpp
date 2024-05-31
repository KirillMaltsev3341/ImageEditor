/**
 * @file Polygon.cpp
 * @brief Implementation of methods for drawing a polygon (with any thickness) + function of checking whether the point is inside the polygon
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImageBMP.h"
#include <vector>
#include <limits.h>
#include <algorithm>


bool ie::ImageBMP::inPolygon(int x0, int y0, std::vector<Coord>& vertices)
{
    int intersections_counter = 0;
    for (int i = 0; i < vertices.size(); i++) {
        int next = (i + 1) % vertices.size();
        
        if ((vertices[i].y > y0 && vertices[next].y <= y0) || (vertices[next].y > y0 && vertices[i].y <= y0)) {
            if ((vertices[next].y - vertices[i].y) < 0) {
                if ((x0 * (vertices[next].y - vertices[i].y)) < ((vertices[next].y - vertices[i].y) * vertices[i].x + (y0 - vertices[i].y) * (vertices[next].x - vertices[i].x))) {
                    intersections_counter++;
                }
            } else {
                if ((x0 * (vertices[next].y - vertices[i].y)) > ((vertices[next].y - vertices[i].y) * vertices[i].x + (y0 - vertices[i].y) * (vertices[next].x - vertices[i].x))) {
                    intersections_counter++;
                }
            }
        }
    }
    return (intersections_counter % 2);
}

void ie::ImageBMP::getPolygonIntersections(std::vector<std::pair<int, int>>& intersections, 
    int y, std::vector<ie::Coord>& vertices)
{
    for (int i = 0; i < vertices.size(); i++) {
        int next = (i + 1) % vertices.size();

        if ((vertices[i].y > y && vertices[next].y <= y) || 
            (vertices[next].y > y && vertices[i].y <= y)) {
            
            intersections.push_back( 
                {
                (vertices[next].y - vertices[i].y) * vertices[i].x + (y - vertices[i].y) * (vertices[next].x - vertices[i].x), 
                (vertices[next].y - vertices[i].y)
                }
                );
        }
    }
}

void ie::ImageBMP::fillPolygon(std::vector<Coord>& vertices, ColorBGR& fill_color)
{
    int y_min = INT_MAX;
    int y_max = INT_MIN;
    for (int i = 0; i < vertices.size(); i++) {
        y_min = std::min(y_min, vertices[i].y);
        y_max = std::max(y_max, vertices[i].y);
    }

    for (int y = y_min; y <= y_max; y++) {
        std::vector<std::pair<int, int>> intersections;
        getPolygonIntersections(intersections, y, vertices);
        std::sort(intersections.begin(), intersections.end(), [](std::pair<int, int>& a, std::pair<int, int>& b) 
            {
                return abs(a.first * b.second) < abs(b.first * a.second);
            });

        for (int i = 0; i < intersections.size(); i += 2) {
            
            int x_start = intersections[i].first / intersections[i].second;
            if ( abs((x_start + 1) * intersections[i].second) >= abs(intersections[i].first)) {
                x_start++;
            }

            int x_end = intersections[i+1].first / intersections[i+1].second;

            for (int x = x_start; x <= x_end; x++) {
                setColor(x, y, fill_color);
            }
        }
    }
}

void ie::ImageBMP::drawPolygon(std::vector<Coord> vertices, int thickness, 
    ColorBGR color, bool fill, ColorBGR fill_color)
{
    if (fill) {
        fillPolygon(vertices, fill_color);
    }

    for (int i = 0; i < vertices.size(); i++) {
        drawLine(vertices[i].x, vertices[i].y, vertices[(i+1)%vertices.size()].x, vertices[(i+1)%vertices.size()].y, thickness, color);
    }
}