/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** ast_redirect_delete
*/

#include <42parser/ast.h>
#include <stdlib.h>


/*
** Deletes the data associated to
** a redirection node.
*/
void ast_redirect_delete(ast_redirect_t *redirect)
{
    if (redirect->is_path)
        free(redirect->new_fd.path);
    free(redirect);
}
