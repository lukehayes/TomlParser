#ifndef TOML_PRINT_H
#define TOML_PRINT_H

#include "toml_parser.h"

// ========================================================================
// String Print Helpers
// ========================================================================
void PS(const char* str);

void PC(char c);

void PCNN(char c);

void PI(int i);

void PF(float f);

void PrintString(const char* str);

// void PrintTomlTable(TomlTable* table);

void PrintBuffer(BufferData* buffer);

// ========================================================================
// TOML print helpers
// ========================================================================
void FreeTomlRow(TomlRow* row);

void PrintTomlRow(TomlRow* row);

#endif // TOML_PRINT_H
