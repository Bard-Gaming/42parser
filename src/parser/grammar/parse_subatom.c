/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** parse_subatom
*/

#include "42parser/token.h"
#include <42parser/parser.h>
#include <42parser/ast.h>
#include <42parser/error.h>


/*
** Parses a subatom.
** Subatoms should be reserved as the
** nodes that are contained within a command.
** These nodes are:
** - Arguments
** - Raw strings
** - Format strings
** - Redirections (all kinds)
*/
ast_t *parse_subatom(parser_t *parser)
{
    switch (parser->current->type) {
    case TT_RAW_STRING:
    case TT_FORMAT_STRING:
    case TT_ARGUMENT:
        return parse_argument(parser);
    case TT_REDIRECT_OUT:
        return parse_redirect_out(parser);
    case TT_REDIRECT_APPEND:
        return parse_redirect_append(parser);
    case TT_REDIRECT_IN:
        return parse_redirect_in(parser);
    case TT_EOF:
        return ast_create(AT_ERROR);
    default:
        parser_errno_set(PE_NULL_COMMAND);
        return ast_create(AT_ERROR);
    }
}
