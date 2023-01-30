#ifndef TOML_PRINT_H
#define TOML_PRINT_H

#include "toml_parser.h"

/**-----------------------------------------------------------------------------
 = HELPFUL TOML PRINT FUNCTIONS
-----------------------------------------------------------------------------**/

void PS(const char* str);

void PC(char c);

void PCNN(char c);

void PI(int i);

void PF(float f);

void PrintString(const char* str);

void PrintTomlTable(TomlTable* table);

void PrintBuffer(BufferData* buffer);

#endif // TOML_PRINT_H
