/**
 * @file FileReading.cpp
 * @brief Implementation of methods for reading BMP files
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "ImageBMP.h"
#include "Error.h"
#include <stdio.h>

bool ie::ImageBMP::checkFileValidity()
{
    return (bmp_header_.signature == BMP_SIGNATURE && 
            dib_header_.bits_per_pixel == BMP_BITS_PER_PIXEL &&
            dib_header_.compression == BMP_COMPRESSION);
}


void ie::ImageBMP::readImageFromFile(const char *input_file_name)
{
    FILE* fin = fopen(input_file_name, "rb");
    
    if (!fin) {
        throwError("Error: file could not be opened.", BMP_FILE_ERROR);
    }
    
    fread(&bmp_header_, sizeof(BMPHeader), 1, fin);
    fread(&dib_header_, sizeof(DIBHeader), 1, fin);

    if (!checkFileValidity()) {
        fclose(fin);
        throwError("Error: wrong file format.", BMP_FILE_ERROR);
    }
    
    width_ = dib_header_.width;
    height_ = dib_header_.height;

    allocateMemmoryForBitmap();

    fseek(fin, bmp_header_.pixel_offset, SEEK_SET);

    for (int y = 0; y < height_; y++) {
        fread(bitmap_[height_ - y - 1], 1, (width_*sizeof(ColorBGR)+3)&(-4), fin);
    }

    fclose(fin);
}