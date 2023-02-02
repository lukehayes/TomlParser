#ifndef TOML_PARSER_H
#define TOML_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include "toml_io.h"

#define BUFFER_ROW_SIZE 100

/**-----------------------------------------------------------------------------
 = STRUCTS/ENUMS
-----------------------------------------------------------------------------**/

/**
 * All of the possible tokens that can be defined in a .toml file.
 */
typedef enum TokenType {

    LEFTBRACE,
    RIGHTBRACE,
    EQUALS,
    STRCHAR,
    SQUOTE,
    DQUOTE,
    DOT,
    COMMA,
    SPACE

} TokenType;

/**
 * Token represents a complete/valid token on TOML.
 */
typedef struct Token
{
    char* value;
    size_t size;
    TokenType type;
} Token;

/**
 * Toml Entry represents a single row of a table.
 */
typedef struct TomlRow
{
    char key[BUFFER_ROW_SIZE];
    char value[BUFFER_ROW_SIZE];

} TomlRow;

/**
 * Toml table root structure.
 */
typedef struct TomlTable
{
    char* root;
    TomlRow* fields;

} TomlTable;


/**
 * Destroy all of the memory allocated for this buffer
 *
 * @param BufferData* buffer    Contents of .toml file.
 *
 * @return void
 */
void DestroyBufferData(BufferData* buffer);

/**
 * Destroy all of the memory allocated for this table.
 *
 * @param TomlTable* table.
 *
 * @return void
 */
void DestroyTomlTable(TomlTable* table);

/**
 * Parse an individual TOML table title.
 *
 * @param BufferData* buffer    Contents of .toml file.
 *
 * @return TomlTable table.
 */
TomlTable* ParseTableTitle(BufferData* buffer);

#endif // TOML_PARSER_H
