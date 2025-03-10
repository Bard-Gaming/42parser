/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Main header file for
** everything related to
** parsing
*/

#ifndef PARSER_PARSE_H
    #define PARSER_PARSE_H
    #include <42parser/ast.h>
    #include <42parser/token.h>


typedef struct {
    token_t *current;
    token_t *next;
} parser_t;


void parser_next(parser_t *parser);

// Parsing pipeline (highest precedence to lowest)
ast_t *parse_line(const char *line);
ast_t *parse_command(parser_t *parser);


#endif
