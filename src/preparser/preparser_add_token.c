/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** preparser_add_token
*/

#include <42parser/preparser.h>
#include <string.h>


/*
** Adds a given token's value to the preparser.
** TODO: Optimize growth
*/
void preparser_add_token(preparser_t *preparser, const token_t *token)
{
    while (preparser->count + token->length + 1 >= preparser->capacity)
        preparser_grow(preparser);
    memcpy(preparser->output, token->start, token->length);
    preparser->count += token->length;
    preparser->output[preparser->count] = '\0';
}
