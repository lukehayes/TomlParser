#include "toml_parser.h"
#include "toml_print.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalpha() - Note to self.


TomlToken* TokenizeToml(BufferData* buffer)
{
    // TODO Implement
}

TomlTable* ParseToml(BufferData* buffer)
{
    // TDOO Stop segfault for now implement properly later.
    TomlTable* t = malloc(sizeof(TomlTable));

    return t;
}

/**
 * Destroy a TomlTable struct
 *
 * @param TomlTable*
 */
void DestroyTomlTable(TomlTable* table)
{
    free(table);
}

void DestroyBufferData(BufferData* buffer)
{
    printf("Buffer of size: %li freed. \n", buffer->size);
    free(buffer->data);
    free(buffer);
}
