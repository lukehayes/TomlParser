#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "io.h"
#include "toml_parser.h"
#include "toml_print.h"

int main()
{
    BufferData* buffer = ReadFile("data.toml");

    TomlTable* t = ParseToml(buffer);

    PrintBuffer(buffer);

    PrintTomlTable(t);
    DestroyTomlTable(t);
    DestroyBufferData(buffer);

    return 0;
}
