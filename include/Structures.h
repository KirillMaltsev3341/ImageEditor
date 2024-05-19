/**
 * @file Structures.h
 * @brief Header with a description of the Coord and Color structures
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

#define R_IDX        0
#define G_IDX        1
#define B_IDX        2
#define A_IDX        3


/**
 * @brief namespace of ImageEditor.h
 * 
 */
namespace ie
{


/**
 * @brief Structure for representing pixel coordinates
 * 
 */
struct Coord
{
    int x;
    int y;
};


/**
 * @brief Structure for representing pixel color
 * 
 */
struct Color
{
    int r; ///< red component
    int g; ///< green component
    int b; ///< blue component
    int a; ///< alpha component

    /**
     * @brief Check if colors are the same
     * 
     * @param[in] other object for comparison
     * @return true - if the same
     * @return false - if not the same
     */
    bool operator==(Color other)
    {
        return (r == other.r) && 
               (g == other.g) && 
               (b == other.b) && 
               (a == other.a);
    }


    /**
     * @brief Check if colors are not the same
     * 
     * @param[in] other object for comparison
     * @return true - if not the same
     * @return false - if the same
     */
    bool operator!=(Color other)
    {
        return !(*this == other);
    }

    /**
     * @brief inverse pixel color
     * 
     */
    void inverse()
    {
        r = 255 - r;
        g = 255 - g;
        b = 255 - b;
    }


    /**
     * @brief convert pixel color to black and white
     * 
     */
    void gray()
    {
        r = (0.299 * r) + (0.587 * g) + (0.114 * b);
        g = (0.299 * r) + (0.587 * g) + (0.114 * b);
        b = (0.299 * r) + (0.587 * g) + (0.114 * b);
    }
};

}
#endif