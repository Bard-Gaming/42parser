/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** lexer_make_redirect_out
*/

#include <42parser/lexer.h>


static void scan_file_descriptor(lexer_t *lexer)
{
    while ('0' <= *lexer->current && *lexer->current <= '9')
        lexer->current++;
}

/*
** Make a redirection token.
** The redirection can be of types
** TT_REDIRECT_WRITE or TT_REDIRECT_APPEND.
*/
token_t *lexer_make_redirect_out(lexer_t *lexer)
{
    scan_file_descriptor(lexer);
    lexer->current++;
    if (*lexer->current == '>')
        lexer->current++;
    if (*lexer->current == '&') {
        lexer->current++;
        scan_file_descriptor(lexer);
    }
    return token_create(
        TT_REDIRECT_OUT, lexer->start,
        lexer->start - lexer->current
    );
}
