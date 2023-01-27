#ifndef TOML_PRINT_H
#define TOML_PRINT_H

#include <stdio.h>
#include "toml_parser.h"

/**-----------------------------------------------------------------------------
 = HELPFUL TOML PRINT FUNCTIONS
-----------------------------------------------------------------------------**/

void PrintString(const char* str)
{
    printf("STR: %s\n", str);
}

void PrintBuffer(BufferData* buffer)
{
    printf("\n----------------------------------------------\n");
    printf("Buffer Data: \n");
    printf("\nData: %s \nSIZE: %li\n", buffer->data, buffer->size);
    printf("----------------------------------------------\n");
}

#endif // TOML_PRINT_H
