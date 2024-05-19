/**
 * @file ImagePNG.h
 * @brief Header with a description of the ImagePNG class
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef IMAGE_PNG_H
#define IMAGE_PNG_H

#include "Structures.h"
#include <png.h>
#include <vector>

#define SIG_BYTES                 8
#define TURN_180                  0
#define TURN_90_CLOCKWISE         1
#define TURN_90_COUNTERCLOCKWISE  2
#define VERTICAL                  0
#define HORIZONTAL                1
#define FILE_ERROR                40
#define PNG_PROCESSING_ERROR      41

/**
 * @brief namespace of ImageEditor.h
 * 
 */
namespace ie
{


/**
 * @brief Outputs errors to the out stream when processing PNG images
 * 
 * @param[in] error_massage the error message that will be displayed in the out stream
 * @param[in] exit_code the error code with which the program will terminate
 */
void throwError(const char *error_massage, int exit_code);


/**
 * @brief Check if the PNG file matches the format
 * 
 * @param[in] input_file input file
 * @return true - if the file matches the format
 * @return false - if the file does not match format
 */
bool checkFileValidity(FILE *input_file);


/**
 * @brief Displaying basic information about a PNG file in the out stream
 * 
 * @param[in] input_file_name input file name
 */
void showImageInfo(const char *input_file_name);


/**
 * @brief Class for working with PNG files
 * 
 */
class ImagePNG
{
public:

    /**
     * @brief Construct a new ImagePNG object
     * 
     */
    ImagePNG();


    /**
     * @brief Destroy the ImagePNG object
     * 
     */
    ~ImagePNG();

    /**
     * @brief Get the Width object
     * 
     * @return int - image width
     */
    int getWidth();
    

    /**
     * @brief Get the Height image
     * 
     * @return int - image height
     */
    int getHeight();


    /**
     * @brief Get the pixel Color 
     * 
     * @param[in] x the X coordinate of the pixel
     * @param[in] y the Y coordinate of the pixel
     * @return Color - pixel color
     */
    Color getColor(int x, int y);


    /**
     * @brief Set the Color object
     * 
     * @param[in] x the X coordinate of the pixel
     * @param[in] y the Y coordinate of the pixel
     * @param[in] color pixel color
     */
    void setColor(int x, int y, Color color);


    /**
     * @brief Set the Size image<br>
     * (sets the color value for all pixels {0, 0, 0, 0})
     * 
     * @param[in] width image wigth
     * @param[in] height image height
     */
    void setSize(int width, int height);


    /**
     * @brief Read an image from a PNG file<br>
     * (converts images to 8-bit/color RGBA when reading)
     * 
     * @param[in] input_file_name input file name
     */
    void readImageFromFile(const char *input_file_name);


    /**
     * @brief Write an image to a PNG file<br>
     * (outputs image as 8-bit/color RGBA)
     * 
     * @param[in] output_file_name output file name
     */
    void writeImageToFile(const char *output_file_name);


    /**
     * @brief Clear the image<br>
     * (sets the color value for all pixels {0, 0, 0, 0})
     * 
     */
    void clear();


    /**
     * @brief Resize the image and insert the original one at the position x0, y0 for the upper-left corner)
     * 
     * @param[in] x0 the X coordinate of the upper-left corner of the original image insertion
     * @param[in] y0 the Y coordinate of the upper-left corner of the original image insertion
     * @param[in] new_width new image width
     * @param[in] new_height new image height
     */
    void resize(int x0, int y0, int new_width, int new_height);
    

    /**
     * @brief Return a new object of the ImagePNG class, which is part of the image
     * 
     * @param[in] x0 the X coordinate of upper left corner of the copy area
     * @param[in] y0 the Y coordinate of upper left corner of the copy area
     * @param[in] x1 the X coordinate of lower right corner of the copy area
     * @param[in] y1 the Y coordinate of lower right corner of the copy area
     * @return ImagePNG - copied area
     */
    ImagePNG copy(int x0, int y0, int x1, int y1);
    

    /**
     * @brief Insert an image at the position x0, y0 for the upper-left corner
     * 
     * @param[in] src_image image to copy
     * @param[in] x0 the X coordinate of upper left corner of insertion
     * @param[in] y0 the Y coordinate of upper left corner of insertion
     */
    void paste(ImagePNG& src_image, int x0, int y0);

    
    /**
     * @brief Rotate the image at angles multiple of 90
     * 
     * @param[in] rotation_type type of rotation (TURN_180, TURN_90_CLOCKWISE or TURN_90_COUNTERCLOCKWISE)
     */
    void rotate(int rotation_type);


    /**
     * @brief Reflect the image
     * 
     * @param[in] reflection_type type of reflection (format can be: VERTICAL or HORIZONTAL)
     */
    void reflect(int reflection_type);

    
    /**
     * @brief Draw Bresenham line<br>
     * (line with thickness 1)
     * 
     * @param[in] x0 the X coordinate of the beginning of the line
     * @param[in] y0 the Y coordinate of the beginning of the line
     * @param[in] x1 the X coordinate of the end of the line
     * @param[in] y1 the Y coordinate of the end of the line
     * @param[in] color line color
     */
    void drawBresenhamLine(int x0, int y0, int x1, int y1, Color color);


    /**
     * @brief Draw line<br>
     * (line with any thickness)<br>
     * (thickness is set by drawing circles at each point of the line)
     * 
     * @param[in] x0 the X coordinate of the beginning of the line
     * @param[in] y0 the Y coordinate of the beginning of the line
     * @param[in] x1 the X coordinate of the end of the line
     * @param[in] y1 the Y coordinate of the end of the line
     * @param[in] thickness thickenss of the line
     * @param[in] color line color
     */
    void drawLine(int x0, int y0, int x1, int y1, 
        int thickness, Color color);


    /**
     * @brief Draw Bresenham circle<br>
     * (circle with thickness 1)
     * 
     * @param[in] x0 the X coordinate of the center of the circle
     * @param[in] y0 the X coordinate of the center of the circle
     * @param[in] radius circle radius
     * @param[in] color circle color
     */
    void drawBresenhamCircle(int x0, int y0, int radius, Color color);


    /**
     * @brief Draw circle<br>
     * (circle with any thickness)
     * 
     * @param[in] x0 the X coordinate of the center of the circle
     * @param[in] y0 the X coordinate of the center of the circle
     * @param[in] radius circle radius
     * @param[in] thickness circle thickness
     * @param[in] color circle color
     * @param[in] fill should it be filled in (format can be: true or false)
     * @param[in] fill_color circle fill color
     */
    void drawCircle(int x0, int y0, int radius, int thickness, 
        Color color, bool fill, Color fill_color);


    /**
     * @brief Draw polygon<br>
     * (polygon with any thickness)<br>
     * (used alg: scan line)
     * 
     * @param[in] vertices the vector of polygon coordinates in the order of their connection
     * @param[in] thickness polygon thickness
     * @param[in] color polygon color
     * @param[in] fill should it be filled in (true or false)
     * @param[in] fill_color polygon fill color
     */
    void drawPolygon(std::vector<Coord> vertices, int thickness, 
        Color color, bool fill, Color fill_color);


    /**
     * @brief Check if point is in polygon
     * 
     * @param[in] x the X coordinate of point
     * @param[in] y the X coordinate of point
     * @param[in] vertices the vector of polygon coordinates in the order of their connection
     * @return true - point is in the polygon
     * @return false - point is not in the polygon
     */
    bool inPolygon(int x, int y, std::vector<Coord>& vertices);
    

    /**
     * @brief Replace a certain color with a new one
     * 
     * @param[in] old_color old color (foramat: {R, G, B, A})
     * @param[in] new_color new color (format: {R, G, B, A})
     */
    void colorReplace(Color old_color, Color new_color);


    /**
     * @brief Replace a certain color component
     * 
     * @param[in] component_idx color component (format can be: R_IDX, G_IDX or B_IDX)
     * @param[in] component_value the new value of the component (format: [0..255])
     */
    void rgbaFilter(int component_idx, int component_value);


    /**
     * @brief Inverts the colors of the image
     * 
     */
    void inverseColors();


    /**
     * @brief Converts the image to black and white
     * 
     */
    void grayColors();


    /**
     * @brief Fill with color
     * 
     * @param[in] x the X coordinate of the beginning of the fill
     * @param[in] y the Y coordinate of the beginning of the fill
     * @param[in] color fill color
     */
    void fill(int x, int y, Color color);

private:
    const int     pixel_size_;          ///< number of bytes per pixel
    png_structp   png_ptr_;             ///< pointer to the PNG structure
    png_infop     info_ptr_;            ///< pointer to the info structure
    png_infop     end_info_ptr_;        ///< pointer to the end_info structure
    int           width_;               ///< image width
    int           height_;              ///< image height
    png_byte      bit_depth_;           ///< bit depth (converts to 8)
    png_byte      color_type_;          ///< color type (converts to 6)
    png_byte      interlace_type_;
    png_byte      compression_type_;
    png_byte      filter_type_;
    int           number_of_passes_;
    png_bytepp    row_pointers_;        ///< image data
    bool          **colored_pixels_;    ///< can be used by some algorithms of filling

    
    /**
     * @brief Allocate memmory for image data (width_ * height_)
     * 
     */
    void allocateMemmoryForRowPointers();


    /**
     * @brief Free memmory for image data
     * 
     */
    void freeMemmoryForRowPointers();


    /**
     * @brief Set all pixels to {0, 0, 0, 0}
     * 
     */
    void clearRowPointers();


    /**
     * @brief Allocate memmory for colored pixels (width_ * height_)
     * 
     */
    void allocateMemmoryForColoredPixels();


    /**
     * @brief Free memmory for colored pixels
     * 
     */
    void freeMemmoryForColoredPixels();


    /**
     * @brief Set all pixels to 0<br>
     * (means: not colored)
     */
    void clearColoredPixels();


    /**
     * @brief Reads info structure
     * 
     */
    void readInfoFields();


    /**
     * @brief Converts image to 8-bit/color RGBA
     * 
     */
    void transformInput();


    /**
     * @brief Check if coordinate belongs to the image
     * 
     * @param[in] x the X coordinate of the pixel
     * @param[in] y the Y coordinate of the pixel
     * @return true - coordinate belongs to the image
     * @return false - coordinate does not belong to the image
     */
    bool checkCoordsValidity(int x, int y);


    /**
     * @brief Check if pixel is colored<br>
     * (can be used only for special filling algs)
     * 
     * @param[in] x the X coordinate of the pixel
     * @param[in] y the Y coordinate of the pixel
     * @return true - pixel is colored
     * @return false - pixel is not colored
     */
    bool isColored(int x, int y);
    

    /**
     * @brief Draw Bresenham line low<br>
     * (line with thickness 1 and slope < 1)<br>
     * (method used by DrawBresenhamLine)
     * 
     * @param[in] x0 X coordinate of the beginning of the line
     * @param[in] y0 Y coordinate of the beginning of the line
     * @param[in] x1 X coordinate of the end of the line
     * @param[in] y1 Y coordinate of the end of the line
     * @param[in] color line color
     */
    void drawBresenhamLineLow(int x0, int y0, int x1, int y1, Color color);


    /**
     * @brief Draw Bresenham line high<br>
     * (line with thickness 1 and slope > 1)<br>
     * (method used by DrawBresenhamLine)
     * 
     * @param[in] x0 X coordinate of the beginning of the line
     * @param[in] y0 Y coordinate of the beginning of the line
     * @param[in] x1 X coordinate of the end of the line
     * @param[in] y1 Y coordinate of the end of the line
     * @param[in] color line color
     */
    void drawBresenhamLineHigh(int x0, int y0, int x1, int y1, Color color);


    /**
     * @brief Draw line high<br>
     * (line with thickness 1 and slope < 1)<br>
     * (method used by DrawLine)
     * 
     * @param[in] x0 X coordinate of the beginning of the line
     * @param[in] y0 Y coordinate of the beginning of the line
     * @param[in] x1 X coordinate of the end of the line
     * @param[in] y1 Y coordinate of the end of the line
     * @param[in] color line color
     */
    void drawLineHigh(int x0, int y0, int x1, int y1, 
        int thickness, Color color);


    /**
     * @brief Draw line high<br>
     * (line with thickness 1 and slope > 1)<br>
     * (method used by DrawLine)
     * 
     * @param[in] x0 X coordinate of the beginning of the line
     * @param[in] y0 Y coordinate of the beginning of the line
     * @param[in] x1 X coordinate of the end of the line
     * @param[in] y1 Y coordinate of the end of the line
     * @param[in] color line color
     */
    void drawLineLow(int x0, int y0, int x1, int y1, 
        int thickness, Color color);
    

    /**
     * @brief Fill pilygon<br>
     * (used by DrawPolygon)
     * 
     * @param[in] vertices the vector of polygon coordinates in the order of their connection
     * @param[in] fill_color polygon fill color
     */
    void fillPolygon(std::vector<Coord>& vertices, Color& fill_color);
    

    /**
     * @brief Flood fill<br>
     * (can be used by special filling algs)<br>
     * (uses colored_pixels_)
     * 
     * @param[in] x the X coordinate of the beginning of the fill
     * @param[in] y the Y coordinate of the beginning of the fill
     * @param[in] color fill color
     */
    void floodFill(int x, int y, Color color);
};

}
#endif