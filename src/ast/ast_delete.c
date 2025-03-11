/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** ast_delete
*/

#include <42parser/ast.h>
#include <stdlib.h>


static void delete_data(ast_t *ast)
{
    static const ast_delete_fnc_t delete_fnc[AT_COUNT] = {
        NULL,
        (ast_delete_fnc_t)ast_command_delete,
        NULL, NULL, NULL,
    };

    if (delete_fnc[ast->type] != NULL)
        delete_fnc[ast->type](ast->data);
}

/*
** Recursively delete the ast node
** and all of its children.
*/
void ast_delete(ast_t *ast)
{
    delete_data(ast);
    free(ast);
}
