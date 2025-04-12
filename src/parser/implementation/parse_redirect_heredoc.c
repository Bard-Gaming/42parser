/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** parse_redirect_heredoc
*/

#include <42parser/parser.h>
#include <42parser/ast.h>
#include <42parser/error.h>
#include <stdlib.h>


static int get_file_descriptor(const char *src)
{
    int fd = 0;

    while ('0' <= *src && *src <= '9') {
        fd *= 10;
        fd += *src - '0';
        src++;
    }
    return fd;
}

static void create_redirect_new_file(parser_t *parser,
    ast_redirect_t *redirect)
{
    parser_next(parser);
    redirect->type = RT_HEREDOC_END;
    redirect->new_fd.path = parse_subatom(parser);
}

/*
** Parses a heredoc redirection.
*/
ast_t *parse_redirect_heredoc(parser_t *parser)
{
    ast_t *node = ast_create(AT_REDIRECT);
    ast_redirect_t *redirect;

    if (!IS_ARGUMENT(parser->next->type)) {
        parser_errno_set(PE_EMPTY_HEREDOC);
        node->type = AT_ERROR;
        return node;
    }
    redirect = malloc(sizeof(ast_redirect_t));
    node->data = redirect;
    redirect->old_fd = *parser->current->start == '<' ?
        0 : get_file_descriptor(parser->current->start);
    create_redirect_new_file(parser, redirect);
    return node;
}
