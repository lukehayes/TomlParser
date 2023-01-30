#ifndef TOML_PARSER_H
#define TOML_PARSER_H

#include <stdio.h>
#include <stdlib.h>

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
 * An individual token parsed from a .toml file.
 */
typedef struct Token {

    char  value;
    TokenType type;
    size_t length;

} Token;


/**
 * An individual toml table field.
 */
typedef struct TomlEntry
{
    const char* key;
    void* value;

} TomlEntry;

typedef struct TomlTable
{
    char* name;
    struct TomlEntry* entry;

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
 * Run a basic lexical analysis of file.
 *
 * @param BufferData* data    Data to be tokenized.
 *
 * @return TokenType*
 */
Token* TokenizeToml(BufferData* buffer);

/**
 * Parse toml and retrieve meaningful data.
 *
 * @param BufferData*
 *
 * @return TomlTable*
 */
TomlTable* ParseToml(BufferData* buffer);


/**
 * Destroy all of the memory allocated for this buffer
 *
 * @param char* buffer    Contents of .toml file.
 *
 * @return void
 */
void DestroyBufferData(BufferData* buffer);




#endif // TOML_PARSER_H
