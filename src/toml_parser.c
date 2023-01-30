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

TomlTable* ParseToml(BufferData* buffer)
{
    char* buf = buffer->data;
    TomlTable* table = malloc(sizeof(TomlTable));

    for(int i = 0; i<= buffer->size; i++) {

        char current_char = *(buf + i);
        char* name = malloc(sizeof(char));


        if(isalpha(current_char))
        {
            static int c = 1;
            char nc = *(buf + i + c);

            name = realloc(name, sizeof(char) * c);
            PS(name);
            c++;
        }
    }

    return table;
}

void DestroyBufferData(BufferData* buffer)
{
    printf("Buffer of size: %li freed. \n", buffer->size);
    free(buffer->data);
    free(buffer);
}
