#ifndef TOML_PARSER_H
#define TOML_PARSER_H

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
    STRING,
    SQUOTE,
    DQUOTE,
    DOT,
    COMMA

} TokenType;


/**
 * An individual token parsed from a .toml file.
 */
typedef struct Token {

    char*  value;
    size_t length;

} Token;


#endif // TOML_PARSER_H
