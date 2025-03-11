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


// User entry:
ast_t *parse_line(const char *line);

// Parser utils:
void parser_init(parser_t *parser);
void parser_next(parser_t *parser);
void parser_term(parser_t *parser);

// Parser grammar (highest to lowest precedence):
ast_t *parse_statement(parser_t *parser);
ast_t *parse_atom(parser_t *parser);

// Parser rules:
ast_t *parse_binary_operation(parser_t *parser);
ast_t *parse_command(parser_t *parser);
ast_t *parse_parenthesis(parser_t *parser);


#endif
