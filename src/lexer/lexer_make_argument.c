/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** lexer_make_argument
*/

#include <42parser/lexer.h>
#include <42parser/token.h>
#include <stdbool.h>


static bool is_argument_end(char c)
{
    static const char *non_arg_chars = ";&| \t\n\"'";
    const char *current = non_arg_chars;

    if (c == '\0')
        return true;
    while (*current != '\0') {
        if (c == *current)
            return true;
        current++;
    }
    return false;
}

token_t *lexer_make_argument(lexer_t *lexer)
{
    while (!is_argument_end(*lexer->current))
        lexer->current++;
    return token_create(
        TT_ARGUMENT, lexer->start,
        lexer->current - lexer->start
    );
}
