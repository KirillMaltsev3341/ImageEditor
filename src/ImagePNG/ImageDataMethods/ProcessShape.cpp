/**
 * @file ProcessShape.cpp
 * @brief Implementation of methods for working with image shape (getWidth, getHeight, setSize, etc.)
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ImagePNG.h"
#include <algorithm>


int ie::ImagePNG::getWidth()
{
    return width_;
}

int ie::ImagePNG::getHeight()
{
    return height_;
}

void ie::ImagePNG::setSize(int width, int height)
{
    width_ = width;
    height_ = height;
    
    allocateMemmoryForRowPointers();
    
    clear();
}

void ie::ImagePNG::resize(int x0, int y0, int new_width, int new_height)
{
    ImagePNG copy_image = copy(0, 0, width_-1, height_-1);
    setSize(new_width, new_height);
    this->paste(copy_image, x0, y0);
}

ie::ImagePNG ie::ImagePNG::copy(int x0, int y0, int x1, int y1)
{
    if (x0 > x1) {
        std::swap(x0, x1);
    }
    if (y0 > y1) {
        std::swap(y0, y1);
    }

    ImagePNG copy_image;
    copy_image.setSize(x1-x0+1, y1-y0+1);
    for (int y = 0; y < copy_image.getHeight(); y++) {
        for (int x = 0; x < copy_image.getWidth(); x++) {
            copy_image.setColor(x, y, getColor(x + x0, y + y0));
        }
    }
    return copy_image;
}

void ie::ImagePNG::paste(ImagePNG& src_image, int x0, int y0)
{
    for (int y = 0; y < src_image.getHeight(); y++) {
        for (int x = 0; x < src_image.getWidth(); x++) {
            setColor(x + x0, y + y0, src_image.getColor(x, y));
        }
    }
}

void ie::ImagePNG::rotate(int rotation_type)
{
    ImagePNG copy_image = copy(0, 0, width_-1, height_-1);

    if (rotation_type == PNG_TURN_180) {
        clear();
        for (int y = 0; y < height_; y++) {
            for (int x = 0; x < width_; x++) {
                setColor(x, y, copy_image.getColor(width_ - x - 1, height_ - y - 1));
            }
        }
    }
    if (rotation_type == PNG_TURN_90_CLOCKWISE) {
        setSize(height_, width_);
        for (int y = 0; y < height_; y++) {
            for (int x = 0; x < width_; x++) {
                setColor(x, y, copy_image.getColor(y, width_ - x - 1));
            }
        }
    }
    if (rotation_type == PNG_TURN_90_COUNTERCLOCKWISE) {
        setSize(height_, width_);
        for (int y = 0; y < height_; y++) {
            for (int x = 0; x < width_; x++) {
                setColor(x, y, copy_image.getColor(height_ - y - 1, x));
            }
        }
    }
}

void ie::ImagePNG::reflect(int reflection_type)
{
    if (reflection_type == PNG_VERTICAL) {
        for (int y = 0; y < height_/2; y++) {
            for (int x = 0; x < width_; x++) {
                ColorRGBA a = getColor(x, y);
                ColorRGBA b = getColor(x, height_-y-1);
                setColor(x, y, b);
                setColor(x, height_-y-1, a);
            }
        }
    }
    if (reflection_type == PNG_HORIZONTAL) {
        for (int y = 0; y < height_; y++) {
            for (int x = 0; x < width_/2; x++) {
                ColorRGBA a = getColor(x, y);
                ColorRGBA b = getColor(width_-x-1, y);
                setColor(x, y, b);
                setColor(width_-x-1, y, a);
            }
        }
    }
    
}