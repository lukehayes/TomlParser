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
    /**
     * ========================================================================
     * Final API example:
     * ------------------
     *
     * GetTable(table) -> Return a full table and all children.
     *
     * GetTableValue(key, table) -> Return the value for 'key' in a specific table.
     *
     * GetValue(key) -> Search a complete table for the first instance of 'key'
     * ======================================================================== */

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
