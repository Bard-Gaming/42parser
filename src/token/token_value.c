/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** token_value
*/

#include <42parser/token.h>
#include <stdlib.h>
#include <string.h>


/*
** Duplicate a token's value into
** a newly allocated, null terminated
** string.
** Returns NULL on error.
*/
char *token_value(const token_t *token)
{
    char *value = malloc((token->length + 1) * sizeof(char));

    if (value == NULL)
        return NULL;
    memcpy(value, token->start, token->length);
    value[token->length] = '\0';
    return value;
}
