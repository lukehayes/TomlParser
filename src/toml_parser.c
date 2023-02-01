#include "toml_parser.h"
#include "toml_print.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalpha() - Note to self.

int GetFileSize(FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    int file_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return file_length;
}

char* ParseTableTitle(BufferData* buffer)
{
    const int MAX = 10;
    char* title_buffer = malloc(sizeof(char) * MAX);

    for (int i = 0; i <= MAX; i++)
    {
        char* current_char = (buffer->data + i);

        static int counter = 0;

        switch (*current_char)
        {
            case '[':
                // ] Start of title
                break;
            case ']':
                // ] Char represents end of title
                counter = 0;
                break;
            default:
                // Other chars are alphanum so add them to the buffer.
                counter += 1;
                title_buffer[counter] = *current_char;
                break;
        }
    }

    return title_buffer;
}

BufferData* ReadFile(const char* toml_file)
{
    FILE* fp = fopen(toml_file, "r+");

    int file_length = GetFileSize(fp);
    char* testBuffer[file_length+1];

    if(ferror(fp))
        printf("An error occurred opening file %s \n", toml_file);

    BufferData* buffer = malloc(sizeof(BufferData));
    buffer->data = malloc(sizeof(char) * file_length);
    buffer->size = file_length;

    fread(buffer->data, 1, file_length,fp);

    fclose(fp);

    return buffer;
}

void DestroyBufferData(BufferData* buffer)
{
    printf("Buffer of size: %li freed. \n", buffer->size);
    free(buffer->data);
    free(buffer);
}
