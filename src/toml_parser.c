#include "toml_parser.h"

/**
 * Get the size of a file in bytes.
 *
 * @param FILE* fp
 *
 * @return int
 */
int GetFileSize(FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    int file_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return file_length;
}

/**
 * Read the contents of a file and store it in memory.
 *
 * @param const char* toml_file    The name of the .toml file
 *
 * @return char*    Contents of the file. Must be freed.
 *
 */
char* ReadFile(const char* toml_file)
{
    FILE* fp = fopen(toml_file, "r+");

    int file_length = GetFileSize(fp);

    if(ferror(fp))
        printf("An error occurred opening file %s \n", toml_file);

    char* buffer = malloc(sizeof(char) * file_length);

    fread(buffer, 1, file_length,fp);
    fclose(fp);

    return buffer;
}
