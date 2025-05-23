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
    #define AST_ARGUMENT_INIT_CAP 20
    #define AST_BUFFER_GROWTH_FACTOR 1.5f

    #include <42parser/token.h>
    #include <stdbool.h>
    #include <stddef.h>


typedef enum {
    AT_ERROR,             // <generic error>

    // Values:
    AT_VARIABLE,          // Variable name (stores char *)
    AT_SUBSTITUTION,      // CMD Substitution (stores ast_t *)

    // Sub-atoms:
    AT_RAW_ARGUMENT,      // Raw argument (i.e. 'text')
    AT_ARGUMENT_STR,      // Format argument, but with whitespace
    AT_ARGUMENT,          // Format argument (gets split in interpreter)
    AT_REDIRECT,          // All kinds of redirections

    // Atoms:
    AT_COMMAND,           // [<sub-atom>]+ (at least one non-redirection)
    AT_COMPOUND,          // [<statement>]

    // Expressions:
    AT_OPERATION_AND,     // <command> && <command>
    AT_OPERATION_OR,      // <command> || <command>
    AT_PIPELINE,          // <command> [| <command>]+

    // Statements:
    AT_IF_STATEMENT,
    AT_WHILE_LOOP,
    AT_FOREACH_LOOP,
    // CASE statements

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


typedef enum {
    RT_FILE_DESCRIPTOR,
    RT_FILE_PATH,
    RT_HEREDOC_END,
    RT_HERESTRING,
} redirect_type_t;


typedef union {
    int fd;
    ast_t *heredoc_end;
    ast_t *path;
} redirect_data_t;


typedef struct {
    redirect_type_t type;    // type of redirect
    redirect_data_t new_fd;  // thing to replace old fd with
    int old_fd;              // fd to replace with new fd
    int open_flags;          // flags to open file with (if needed)
} ast_redirect_t;


typedef struct {
    size_t is_string;
    union {
        char *str;
        ast_t *node;
    } val;
} ast_arg_comp_t;


typedef struct {
    ast_arg_comp_t *data;
    size_t capacity;
    size_t length;
} ast_argument_t;


typedef struct {
    bool is_command;
    union {
        ast_node_buffer_t *test_args;
        ast_t *command;
    } condition;
} ast_condition_t;


typedef struct {
    ast_condition_t *conditions;
    ast_t **bodies;
    size_t count;
    size_t capacity;
} ast_if_stmnt_t;


typedef struct {
    ast_condition_t condition;
    ast_t *body;
} ast_while_loop_t;


typedef struct {
    ast_t *variable;
    ast_node_buffer_t *list;
    ast_t *body;
} ast_foreach_loop_t;


typedef void (*ast_delete_fnc_t)(void *);
typedef void (*ast_print_fnc_t)(const ast_t *, unsigned short);


ast_t *ast_create(ast_type_t type);
void ast_delete(ast_t *ast);

// AST Utils:
const char *ast_strtype(const ast_t *node);

// Printing (for debug / because it's pretty :>)
void ast_print(const ast_t *ast);
void ast_print_indent(unsigned short indent_level);
void ast_print_node(const ast_t *ast, unsigned short depth);
void ast_print_binary_operation(const ast_t *ast, unsigned short depth);
void ast_print_container(const ast_t *ast, unsigned short depth);
void ast_print_variable(const ast_t *ast, unsigned short depth);
void ast_print_raw_argument(const ast_t *ast, unsigned short depth);
void ast_print_argument(const ast_t *ast, unsigned short depth);
void ast_print_substitution(const ast_t *ast, unsigned short depth);

// Implementation functions (need to be forward declared for double recursion)
void ast_delete_binop_data(void *data);
void ast_delete_conditional_data(void *data);
void ast_redirect_delete(ast_redirect_t *redirect);
void ast_while_loop_delete(ast_while_loop_t *data);
void ast_foreach_loop_delete(ast_foreach_loop_t *loop);

// Node buffer:
ast_node_buffer_t *ast_node_buffer_create(void);
void ast_node_buffer_append(ast_node_buffer_t *buffer, ast_t *node);
void ast_node_buffer_delete(ast_node_buffer_t *buffer);

// Arguments:
ast_argument_t *ast_argument_create(void);
void ast_argument_delete(ast_argument_t *arg);
void ast_argument_grow(ast_argument_t *arg);
void ast_argument_add_char(ast_argument_t *arg, char c);
void ast_argument_add_node(ast_argument_t *arg, ast_t *node);

// If Statements:
ast_if_stmnt_t *ast_if_stmnt_create(void);
void ast_if_stmnt_grow(ast_if_stmnt_t *data);
void ast_if_stmnt_add(ast_if_stmnt_t *data,
    ast_condition_t condition, ast_t *body);
void ast_if_stmnt_delete(ast_if_stmnt_t *data);


#endif
