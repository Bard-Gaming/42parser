/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** parse_command
*/

#include "42parser/ast.h"
#include <42parser/parser.h>
#include <42parser/token.h>
#include <42parser/error.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>


static ast_t *null_command_err(ast_t *node)
{
    parser_errno_set(PE_NULL_COMMAND);
    ast_delete(node);
    return ast_create(AT_ERROR);
}

static ast_t *propagate_err(ast_t *command_node, ast_t *subnode)
{
    ast_delete(command_node);
    return subnode;
}

/*
** Parse a command.
** Returns an error node on error.
*/
ast_t *parse_command(parser_t *parser)
{
    ast_t *node = ast_create(AT_COMMAND);
    ast_node_buffer_t *buffer = ast_node_buffer_create();
    ast_t *subnode;
    bool has_arguments = false;

    node->data = buffer;
    while (IS_COMMAND_NODE(parser->current->type)) {
        if (IS_ARGUMENT(parser->current->type))
            has_arguments = true;
        subnode = parse_subatom(parser);
        if (subnode->type == AT_ERROR)
            return propagate_err(node, subnode);
        ast_node_buffer_append(buffer, subnode);
    }
    if (!has_arguments)
        return null_command_err(node);
    return node;
}
