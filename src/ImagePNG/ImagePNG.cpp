/**
 * @file ImagePNG.cpp
 * @brief Implementation of the class constructor and destructor + showImageInfo method
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"
#include <stdlib.h>


ie::ImagePNG::ImagePNG() :
    pixel_size_         (4),
    png_ptr_            (NULL),
    info_ptr_           (NULL),
    end_info_ptr_       (NULL),
    width_              (0),
    height_             (0),
    bit_depth_          (8),
    color_type_         (PNG_COLOR_TYPE_RGBA),
    interlace_type_     (PNG_INTERLACE_NONE),
    compression_type_   (PNG_COMPRESSION_TYPE_DEFAULT),
    filter_type_        (PNG_FILTER_TYPE_DEFAULT),
    number_of_passes_   (0),
    row_pointers_       (NULL)
{}

ie::ImagePNG::~ImagePNG()
{
    freeMemmoryForRowPointers();
}

void ie::ImagePNG::showInfo()
{
    printf("%d x %d, %d-bit/color, color type - %d\n", width_, height_, bit_depth_, color_type_);
}