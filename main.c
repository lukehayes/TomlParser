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

    TomlToken* t = TokenizeToml(buffer);

    PrintBuffer(buffer);

    DestroyBufferData(buffer);

    PS("Parsing Done.");

    return 0;
}
