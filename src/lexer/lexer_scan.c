/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** lexer_scan
*/

#include <42parser/lexer.h>
#include <42parser/token.h>
#include <stdbool.h>


static bool is_whitespace(char c)
{
    return
        c == '\t' ||
        c == ' ';
}

static token_t *get_scanned_token(lexer_t *lexer)
{
    switch (*lexer->start) {
    case '"':
    case '\'':
        return lexer_make_string(lexer);
    case '(':
        return lexer_make_generic(lexer, TT_LPAREN);
    case ')':
        return lexer_make_generic(lexer, TT_RPAREN);
    case ';':
        return lexer_make_generic(lexer, TT_SEMICOLON);
    default:
        return lexer_make_argument(lexer);
    }
}

static void skip_whitespace(lexer_t *lexer)
{
    while (is_whitespace(*lexer->start))
        lexer->start++;
    lexer->current = lexer->start;
}

/*
** Scan a single token.
** Returns NULL if no source has,
** been loaded, and an error token
** on other errors.
*/
token_t *lexer_scan(void)
{
    lexer_t *lexer = lexer_get();

    lexer->start = lexer->current;
    if (lexer->start == NULL)
        return NULL;
    skip_whitespace(lexer);
    if (*lexer->start == '\0')
        return token_create(TT_ERROR, NULL, 0);
    return get_scanned_token(lexer);
}
