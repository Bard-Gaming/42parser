/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Header file for all
** operations tied to
** the abstract syntax
** tree or its nodes
*/

#ifndef PARSER_ABSTRACT_SYNTAX_NODE_H
    #define PARSER_ABSTRACT_SYNTAX_NODE_H


typedef enum {
    AT_ERROR,  // preferred first (null initialization)

    AT_ARGUMENT,

    AT_COUNT,  // keep last
} ast_type_t;


typedef struct {
    ast_type_t type;
    void *data;
} ast_t;


ast_t *ast_create(ast_type_t type);
void ast_delete(ast_t *ast);


#endif
