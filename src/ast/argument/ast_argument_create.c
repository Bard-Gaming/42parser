/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** ast_argument_create
*/

#include <42parser/ast.h>
#include <42parser/error.h>
#include <stdlib.h>


/*
** Creates an argument buffer
** with default values.
*/
ast_argument_t *ast_argument_create(void)
{
    ast_argument_t *data = calloc(1, sizeof(ast_argument_t));

    if (data == NULL)
        parser_critical_error();
    return data;
}
