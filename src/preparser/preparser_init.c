/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** preparser_init
*/

#include <42parser/preparser.h>


/*
** Initializes the given preparser
** with default values.
*/
void preparser_init(preparser_t *preparser, const char *input)
{
    lexer_load_src(&preparser->lexer, input);
    preparser->current = lexer_scan(&preparser->lexer);
}
