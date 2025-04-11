/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** ast_print
*/

#include <42parser/ast.h>
#include <string.h>
#include <stdio.h>


static const char *type_repr[AT_COUNT] = {
    [AT_ERROR] = "Error",
    [AT_ARGUMENT] = "Argument",
    [AT_RAW_STRING] = "Raw String",
    [AT_FORMAT_STRING] = "Format String",
    [AT_REDIRECT_OUT] = "Redirect Out (> or >>)",
    [AT_REDIRECT_IN] = "Redirect In (<)",
    [AT_REDIRECT_HEREDOC] = "Heredoc (<<)",
    [AT_COMMAND] = "Command",
    [AT_COMPOUND] = "Compound (parenthesis)",
    [AT_OPERATION_AND] = "Operation AND (&&)",
    [AT_OPERATION_OR] = "Operation OR (||)",
    [AT_PIPELINE] = "Pipeline (|)",
    [AT_PROGRAM] = "Program",
};

static void print_indent(unsigned short indent_amount)
{
    if (indent_amount == 0)
        return;
    for (unsigned int i = 0; i < indent_amount; i++)
        fputs(" |  ", stdout);
    putchar('\n');
    for (unsigned int i = 0; i < (unsigned)indent_amount - 1; i++)
        fputs(" |  ", stdout);
    puts(" |- ");
}

static void print_operation(const ast_t *ast, unsigned short depth)
{
    ast_t **data = ast->data;

    ast_print_node(data[0], depth + 1);
    ast_print_node(data[1], depth + 1);
}

static void print_container(const ast_t *ast, unsigned short depth)
{
    ast_node_buffer_t *buffer = ast->data;

    for (size_t i = 0; i < buffer->count; i++)
        ast_print_node(buffer->nodes[i], depth + 1);
}

static void print_node_data(const ast_t *ast, unsigned short depth)
{
    switch (ast->type) {
    case AT_ARGUMENT:
    case AT_RAW_STRING:
    case AT_FORMAT_STRING:
        print_indent(depth);
        puts(ast->data);
        return;
    case AT_PIPELINE:
    case AT_PROGRAM:
    case AT_COMMAND:
        return print_container(ast, depth);
    case AT_OPERATION_AND:
    case AT_OPERATION_OR:
        return print_operation(ast, depth);
    default:
        return;
    }
}

void ast_print_node(const ast_t *ast, unsigned short depth)
{
    print_indent(depth);
    puts(type_repr[ast->type]);
    print_node_data(ast, depth);
}

/*
** Recursively print an ast.
*/
void ast_print(const ast_t *ast)
{
    ast_print_node(ast, 0);
    putchar('\n');
}
