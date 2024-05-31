#include "Error.h"
#include <stdio.h>
#include <stdlib.h>

void ie::throwError(const char *error_message, int exit_code)
{
    printf("%s\n", error_message);
    exit(exit_code);
}