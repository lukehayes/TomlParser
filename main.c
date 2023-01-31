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
    TomlRow* r1 = malloc(sizeof(TomlRow));
    r1->key   = "name";
    r1->value = malloc(sizeof(char) * 2);

    DestroyBufferData(buffer);
    strncpy(r1->value, "Bob", 10);
    // r1->value = "Bob\0";

    TomlRow r2 = {.key = "health" };
    
    PI(strlen(r1->value));

    PrintTomlRow(r1);


    FreeTomlRow(r1);

    return 0;
}
