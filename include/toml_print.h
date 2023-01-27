#ifndef TOML_PRINT_H
#define TOML_PRINT_H

#include <stdio.h>

/**-----------------------------------------------------------------------------
 = HELPFUL TOML PRINT FUNCTIONS
-----------------------------------------------------------------------------**/

void PrintString(const char* str)
{
    printf("STR: %s\n", str);
}

void PrintBuffer(BufferData* buffer)
{
    printf("Data: %s. \nSIZE: %i\n", buffer->data, buffer->size);
}

#endif // TOML_PRINT_H
