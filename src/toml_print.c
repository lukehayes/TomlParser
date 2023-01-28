#include "toml_print.h"
#include <stdio.h>

void PS(const char* str)
{
    printf("STR: %s\n", str);
}

void PC(char c)
{
    printf("CHAR: %c\n", c);
}

void PI(int i)
{
    printf("INT: %i\n", i);
}

void PF(float f)
{
    printf("FLOAT: %f\n", f);
}

void PrintString(const char* str)
{
    printf("STR: %s\n", str);
}

void PrintTomlTable(TomlTable* table)
{
    printf("\n----------------------------------------------\n");
    printf("Toml Table: \n");
    printf("\nName: %s \n", table->name);
    printf("----------------------------------------------\n");
}

void PrintBuffer(BufferData* buffer)
{
    printf("\n----------------------------------------------\n");
    printf("Buffer Data: \n");
    printf("\nData: %s \nSIZE: %li\n", buffer->data, buffer->size);
    printf("----------------------------------------------\n");
}
