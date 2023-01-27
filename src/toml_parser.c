#include "toml_parser.h"

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

void ParseToml(char* buffer, int size)
{
    /*fread(buffer,4, size, fp);*/

    /*for(int i = 0; i<= size; i++) {*/

        /*if( isalpha(*(buf+i)) )*/
        /*{*/
            /*printf("%c", *(buf+i));*/
        /*}else*/
        /*{*/
            /*switch(*(buf+i))*/
            /*{*/
                /*case '[':*/
                    /*printf("\n[");*/
                /*case ']':*/
                    /*printf("]\n");*/
                /*default:*/
            /*}*/
        /*}*/
    /*}*/
    /*printf("\n", *buf);*/

    /*fclose(fp);*/
}

void DestroyBufferData(BufferData* buffer)
{
    printf("Buffer of size: %i freed. \n", buffer->size);
    free(buffer->data);
    free(buffer);
}
