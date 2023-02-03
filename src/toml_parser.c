#include "toml_parser.h"
#include "toml_print.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // For isalpha() - Note to self.

TomlTable* ParseTableTitle(BufferData* buffer)
{
    TomlTable* table = malloc(sizeof(TomlTable));

    const int MAX = 100;
    bool loopReset = false;
    char title_buffer[MAX];

    for (int i = 0; i <= MAX; i++)
    {
        char* current_char = (buffer->data + i);

        static int counter = -1;

        switch (*current_char)
        {
            case '[':
                // ] Start of title
                break;
            case ']':
                // ] Char represents end of title
                counter = -1;
                loopReset = true;
                break;
            default:
                // Other chars are alphanum so add them to the buffer.
                title_buffer[counter] = *current_char;
                break;
        }

        if(loopReset)
        {
            break;
        }else
        {
            counter += 1;
        }

        // Once this point has been reached, we can start to parse
        // key value pairs as we are inside a table.
    }

    table->root = malloc(sizeof(char) * strlen(title_buffer));
    strncpy(table->root, title_buffer, strlen(title_buffer) );

    return table;
}

void DestroyTomlTable(TomlTable* table)
{
    free(table->root);
    free(table);
}
