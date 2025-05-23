/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** ast_strtype
*/

#include <42parser/ast.h>


static const char *type_repr[AT_COUNT] = {
    [AT_ERROR] = "Error",
    [AT_VARIABLE] = "Variable",
    [AT_SUBSTITUTION] = "Command Substitution",
    [AT_RAW_ARGUMENT] = "Raw Argument",
    [AT_ARGUMENT_STR] = "Format Argument String",
    [AT_ARGUMENT] = "Format Argument",
    [AT_REDIRECT] = "Redirect (> or >> or <)",
    [AT_COMMAND] = "Command",
    [AT_COMPOUND] = "Compound (parenthesis)",
    [AT_OPERATION_AND] = "Operation AND (&&)",
    [AT_OPERATION_OR] = "Operation OR (||)",
    [AT_PIPELINE] = "Pipeline (|)",
    [AT_IF_STATEMENT] = "If Statement",
    [AT_WHILE_LOOP] = "While Loop",
    [AT_FOREACH_LOOP] = "Foreach Loop",
    [AT_PROGRAM] = "Program",
};


/*
** Returns the type representation
** of the given node.
*/
const char *ast_strtype(const ast_t *node)
{
    return type_repr[node->type];
}
