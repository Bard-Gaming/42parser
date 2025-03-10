/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Header file for
** lexer tokens
*/

#ifndef PARSER_TOKEN_H
    #define PARSER_TOKEN_H
    #include <stddef.h>


typedef enum {
    TT_ERROR,

    // Single char:
    TT_SEMICOLON,

    TT_ARGUMENT,
} token_type_t;


typedef struct {
    token_type_t type;
    const char *start;
    size_t length;
} token_t;


token_t *token_create(token_type_t type, const char *start, size_t length);
char *token_value(const token_t *token);
void token_delete(token_t *token);


#endif
