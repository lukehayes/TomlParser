#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "toml_parser.h"
#include "toml_print.h"

void FreeTomlRow(TomlRow* row)
{
    free(row->value);
    free(row);
}

void PrintTomlRow(TomlRow* row)
{
    printf("Row: %s, Value: %s \n", row->key, (char*)row->value);
    printf("--------\n");
}

int main()
{
    BufferData* buffer = ReadFile("data.toml");

    char* title = ParseTableTitle(buffer);

    PI(strlen(title));

    for (int i = 0; i <= 6; i++)
    {
        PC(*(title+i));
    }

    free(title);
    DestroyBufferData(buffer);

    return 0;
}
