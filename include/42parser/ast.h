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
    #include <42parser/token.h>
    #include <stddef.h>


typedef enum {
    AT_ERROR,    // Error node

    AT_COMMAND,        // <argument>+

    // Operations:
    AT_COMMAND_CHAIN,  // <command>  ; <command>
    AT_OPERATION_AND,  // <command> && <command>
    AT_OPERATION_OR,   // <command> || <command>

    AT_COUNT,          // keep last
} ast_type_t;


typedef struct {
    char **args;
    size_t arg_count;
    size_t arg_capacity;
} ast_command_t;


typedef struct {
    ast_type_t type;
    void *data;
} ast_t;


ast_t *ast_create(ast_type_t type);
void ast_delete(ast_t *ast);


// Command:
ast_command_t *ast_command_create(void);
void ast_command_append(ast_command_t *command, const token_t *token);
void ast_command_delete(ast_command_t *command);


#endif
