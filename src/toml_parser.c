#include "toml_parser.h"
// #include "toml_print.h"
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <ctype.h> // For isalpha() - Note to self.

TomlToken* TokenizeToml(BufferData* buffer)
{
    const char* data = buffer->data;
    int bufSize = 100;

    const char keyArr[bufSize];
    const char valArr[bufSize];

    while(*data != '\n')
    {
        const char* key;
        const char* val;

        printf("Data %c\n", *data);
        data += 1;
    }

}

TomlTable* ParseToml(BufferData* buffer)
{
    // TODO
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

int _CheckStartFormat(const char* data)
{
    if(*data != '[')
    {
        printf("TOML file doesn't start with a square bracket! Exiting.\n");
        return 0;
    }

    return 1;
}
