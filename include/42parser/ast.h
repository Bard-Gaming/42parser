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

    #define AST_BUFFER_INIT_CAP 4
    #define AST_BUFFER_GROWTH_FACTOR 1.5f

    #include <42parser/token.h>
    #include <stdbool.h>
    #include <stddef.h>


typedef enum {
    AT_ERROR,             // <generic error>

    // Sub-atoms:
    AT_ARGUMENT,          // TT_ARGUMENT (stores char *)
    AT_RAW_STRING,        // TT_RAW_STRING (stores char *)
    AT_FORMAT_STRING,     // TT_FORMAT_STRING (stores )
    AT_REDIRECT_OUT,      // TT_REDIRECT_OUT or TT_REDIRECT_APPEND
    AT_REDIRECT_IN,       // TT_REDIRECT_IN
    AT_REDIRECT_HEREDOC,  // TT_REDIRECT_HEREDOC

    // Atoms:
    AT_COMMAND,           // [<sub-atom>]+ (at least one non-redirection necessary)
    AT_COMPOUND,          // [<statement>]

    // Expressions:
    AT_OPERATION_AND,     // <command> && <command>
    AT_OPERATION_OR,      // <command> || <command>
    AT_PIPELINE,          // <command> [| <command>]+

    // Statements:
    // IF statements
    // CASE statements
    // WHILE statements
    // FOR statements

    // Program:
    AT_PROGRAM,           // [<operation>]+

    AT_COUNT,             // keep last
} ast_type_t;


typedef struct {
    ast_type_t type;
    void *data;
} ast_t;


typedef struct {
    ast_t **nodes;
    size_t count;
    size_t capacity;
} ast_node_buffer_t;


typedef void (*ast_delete_fnc_t)(void *data);


ast_t *ast_create(ast_type_t type);
void ast_delete(ast_t *ast);

// AST Utils:
void ast_print(const ast_t *ast);

// Implementation functions (need to be forward declared for double recursion)
void ast_print_node(const ast_t *ast, unsigned short depth);
void ast_delete_binop_data(void *data);

// Node buffer:
ast_node_buffer_t *ast_node_buffer_create(void);
void ast_node_buffer_append(ast_node_buffer_t *buffer, ast_t *node);
void ast_node_buffer_delete(ast_node_buffer_t *buffer);


#endif
