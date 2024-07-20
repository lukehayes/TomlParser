#include "io.h"
#include "toml_parser.h"
#include "toml_print.h"

#include <ctype.h>
#include <string.h>

int main()
{
    BufferData* buffer = ReadFile("data.toml");

    int charCount = 0;
    int seperatorCount = 0;


    while(charCount != buffer->size)
    {
        char* currentChar = buffer->data;

        if(*currentChar == '[')
        {
            // TODO Implement this properly.
            strtok(buffer->data, "[]");
        }

        if(*currentChar == ']')
        {
            printf("Close Square Bracket \n");
        }

        if(isalnum(*currentChar))
        {
            printf("Churrent %c ...\n", *currentChar);
        }
        charCount += 1;
        buffer->data++;

    }





    DestroyBufferData(buffer);
    PS("Parsing Done.");

    return 0;
}
