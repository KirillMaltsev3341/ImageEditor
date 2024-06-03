/**
 * @file FileWriting.cpp
 * @brief Implementation of methods for writing BMP files
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "ImageBMP.h"
#include "Error.h"
#include <stdio.h>

void ie::ImageBMP::writeImageToFile(const char *output_file_name)
{   
    FILE *fout = fopen(output_file_name, "wb");
    if (!fout) {
        fclose(fout);
        throwError("Error: file could not be opened.", BMP_FILE_ERROR);
    }

    fwrite(&bmp_header_, 1, sizeof(BMPHeader), fout);
    fwrite(&dib_header_, 1, sizeof(DIBHeader), fout);
    
    fseek(fout, bmp_header_.pixel_offset, SEEK_SET);
    
    for (int y = 0; y < height_; y++) {
        fwrite(bitmap_[height_ - y - 1], 1, (width_*sizeof(ColorBGR)+3)&(-4), fout);
    }
    
    fclose(fout);
}