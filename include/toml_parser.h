#ifndef TOML_PARSER_H
#define TOML_PARSER_H

#include <stdio.h>
#include <stdlib.h>

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
 * Handy location to store data that has been read in.
 */
typedef struct BufferData
{
    char* data;
    size_t size;

} BufferData;

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
    const char* root;
    TomlRow* fields;

} TomlTable;


/**-----------------------------------------------------------------------------
 = FUNCTIONS
-----------------------------------------------------------------------------**/

/**
 * Get the size of a file in bytes.
 *
 * @param FILE* fp
 *
 * @return int
 */
int GetFileSize(FILE* fp);

/**
 * Read the contents of a file and store it in memory.
 *
 * @param const char* toml_file    The name of the .toml file
 *
 * @return BufferData*
 */
BufferData* ReadFile(const char* toml_file);

/**
 * Destroy all of the memory allocated for this buffer
 *
 * @param char* buffer    Contents of .toml file.
 *
 * @return void
 */
void DestroyBufferData(BufferData* buffer);


#endif // TOML_PARSER_H
