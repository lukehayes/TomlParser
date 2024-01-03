#include "toml_parser.h"
#include "toml_print.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalpha() - Note to self.



Token* TokenizeToml(BufferData* buffer)
{
    char* buf = buffer->data;
    Token* t = malloc(sizeof(Token) * (buffer->size + 1));

    for(int i = 0; i<= buffer->size; i++) {

        static int counter = 0;
        char current_char = *(buf + i);
        Token* tok = (t + i);

        if(!isalnum(current_char))
        {
            // Reset the counter if current char is not alphanumeric.
            counter = 0;

            switch (current_char)
            {
                case '[':
                    tok->type = LEFTBRACE;
                    tok->value = current_char;
                    break;
                case ']':
                    tok->type = RIGHTBRACE;
                    tok->value = current_char;
                    break;
                case '=':
                    tok->type = EQUALS;
                    tok->value = current_char;
                    break;
                case ',':
                    tok->type = COMMA;
                    tok->value = current_char;
                    break;
                case '.':
                    tok->type = DOT;
                    tok->value = current_char;
                    break;
                case '"':
                    tok->type = DQUOTE;
                    tok->value = current_char;
                    break;
                case '\n':
                case '\t':
                case '\r':
                default:
                    break;
            }
        }else
        {
            if(current_char != ' ')
            {
                tok->type  = STRCHAR;
                tok->value = current_char;
            }
        }
    }

    return t;
}
TomlTable* ParseToml(BufferData* buffer)
{
    char* buf = buffer->data;
    TomlTable* table = malloc(sizeof(TomlTable));

    // TODO Implement this properly.
    char* cpy = buf;
    int counter = 0;

    if(*cpy == '[')
    {
        counter++;
        cpy += counter;

        while(*(cpy) != ']')
        {
            PC(*cpy);
            cpy = cpy + counter;
            counter++;
        }

    }

    PS("Done");

    return table;
}

void DestroyBufferData(BufferData* buffer)
{
    printf("Buffer of size: %li freed. \n", buffer->size);
    free(buffer->data);
    free(buffer);
}
