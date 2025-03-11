/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** parse_operation
*/

#include <42parser/parser.h>
#include <42parser/ast.h>
#include <42parser/token.h>
#include <stdbool.h>
#include <stdlib.h>


static ast_type_t get_operation_type(parser_t *parser)
{
    switch (parser->current->type) {
    case TT_SEMICOLON:
        return AT_COMMAND_CHAIN;
    default:
        return AT_ERROR;
    }
}

static ast_t *make_operation(ast_t *left, ast_t *right, ast_type_t type)
{
    ast_t *operation_node = ast_create(type);
    ast_t **data = malloc(2 * sizeof(ast_t *));

    data[0] = left;
    data[1] = right;
    operation_node->data = data;
    return operation_node;
}

ast_t *parse_operation(parser_t *parser)
{
    ast_t *left_operand = parse_atom(parser);
    ast_t *right_operand;
    ast_type_t operation_type = get_operation_type(parser);

    while (operation_type != AT_ERROR) {
        parser_next(parser);
        right_operand = parse_atom(parser);
        left_operand = make_operation(
            left_operand,
            right_operand,
            operation_type
        );
        operation_type = get_operation_type(parser);
    }
    return left_operand;
}
