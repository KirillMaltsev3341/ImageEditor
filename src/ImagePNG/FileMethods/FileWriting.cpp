/**
 * @file FileReading.cpp
 * @brief Implementation of methods for wrtiting PNG files
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "ImagePNG.h"
#include "Error.h"
#include <png.h>

void ie::ImagePNG::writeImageToFile(const char *output_file_name)
{   
    FILE *fout = fopen(output_file_name, "wb");
    if (!fout) {
        fclose(fout);
        throwError("Error: file could not be opened.", PNG_FILE_ERROR);
    }

    png_structp png_ptr_ = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_ptr_) {
        fclose(fout);
        throwError("Error: png_create_write_struct failed.", PNG_PROCESSING_ERROR);
    }
    
    png_infop info_ptr_ = png_create_info_struct(png_ptr_);

    if (!info_ptr_) {
        png_destroy_info_struct(png_ptr_, (png_infopp)NULL);
        fclose(fout);
        throwError("Error: (info_ptr) png_create_info_struct failed.", PNG_PROCESSING_ERROR);
    }

    if (setjmp(png_jmpbuf(png_ptr_))) {
        png_destroy_info_struct(png_ptr_, &info_ptr_);
        fclose(fout);
        throwError("Error: png_init_io failed.", PNG_PROCESSING_ERROR);
    }
    
    png_init_io(png_ptr_, fout);


    if (setjmp(png_jmpbuf(png_ptr_))) {
        png_destroy_info_struct(png_ptr_, &info_ptr_);
        fclose(fout);
        throwError("Error: png_set_IHDR failed.", PNG_PROCESSING_ERROR);
    }

    png_set_IHDR(
        png_ptr_, 
        info_ptr_, 
        width_, 
        height_, 
        bit_depth_, 
        color_type_,
        interlace_type_, 
        compression_type_, 
        filter_type_
    );
    
    png_write_info(png_ptr_, info_ptr_);

    if (setjmp(png_jmpbuf(png_ptr_))) {
        png_destroy_info_struct(png_ptr_, &info_ptr_);
        fclose(fout);
        throwError("Error: png_write_image failed.", PNG_PROCESSING_ERROR);
    }
    
    png_write_image(png_ptr_, row_pointers_);

    if (setjmp(png_jmpbuf(png_ptr_))) {
        png_destroy_info_struct(png_ptr_, &info_ptr_);
        fclose(fout);
        throwError("Error: png_write_end failed.", PNG_PROCESSING_ERROR);
    }

    png_write_end(png_ptr_, NULL);
    
    png_destroy_write_struct(&png_ptr_, &info_ptr_);

    fclose(fout);
}