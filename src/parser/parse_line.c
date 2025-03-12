/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** parse_line
*/

#include <42parser/parser.h>
#include <42parser/lexer.h>


static bool is_operation(const ast_t *ast)
{
    return
        AT_COMMAND_CHAIN <= ast->type && ast->type <= AT_OPERATION_OR;
}

static bool has_error(const ast_t *ast)
{
    ast_command_t *data;

    if (ast->type == AT_ERROR)
        return true;
    if (is_operation(ast))
        return
            has_error(((ast_t **)ast->data)[0]) ||
            has_error(((ast_t **)ast->data)[1]);
    return false;
}

/*
** Parses a line into an abstract syntax
** tree.
** Returns NULL if a syntax error was caught.
** The given ast should be deleted with
** ast_delete once it isn't needed anymore.
*/
ast_t *parse_line(const char *line)
{
    ast_t *result;
    parser_t parser;

    lexer_load_src(line);
    parser_init(&parser);
    result = parse_statement(&parser);
    parser_term(&parser);
    if (!has_error(result))
        return result;
    ast_delete(result);
    return NULL;
}
