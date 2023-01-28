#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "toml_parser.h"
#include "toml_print.h"

int main()
{
    BufferData* buffer = ReadFile("data.toml");

    TomlTable* t = ParseToml(buffer);

    char c = 65;

    PC(c);

    PrintBuffer(buffer);

    PrintTomlTable(t);

    free(t);

    DestroyBufferData(buffer);

    return 0;
}
