/**
 * @file Error.h
 * @brief Header with a error handling functions
 * @version 0.1.0
 * @date 2024-05-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef ERROR_H
#define ERROR_H

#define PNG_FILE_ERROR          40
#define PNG_PROCESSING_ERROR    41

#define BMP_FILE_ERROR          40
#define BMP_PROCESSING_ERROR    41

/**
 * @brief namespace of ImageEditor.h
 * 
 */
namespace ie
{


/**
 * @brief Outputs errors to the out stream when processing images
 * 
 * @param[in] error_message the error message that will be displayed in the out stream
 * @param[in] exit_code the error code with which the program will terminate
 */
void throwError(const char *error_message, int exit_code);

}

#endif