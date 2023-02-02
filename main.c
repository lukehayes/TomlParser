#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "toml_io.h"
#include "toml_parser.h"
#include "toml_print.h"

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

    TomlTable* table = ParseTableTitle(buffer);


    DestroyTomlTable(table);
    DestroyBufferData(buffer);

    return 0;
}
