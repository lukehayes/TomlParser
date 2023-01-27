#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "toml_parser.h"
#include "toml_print.h"

int main()
{
    BufferData* buffer = ReadFile("data.toml");

    PrintBuffer(buffer);
    DestroyBufferData(buffer);

    return 0;
}
