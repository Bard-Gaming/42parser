/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for command
** compound syntax.
*/

#include <criterion/criterion.h>
#include <42parser/parser.h>
#include <42parser/error.h>


//////////////////////////////////////////////////
//                                              //
//                 PASSING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_compounds, simple_compound)
{
    ast_t *ast;
    const char *input = "(command_a; command_b;;; command_c)";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_compounds, unmatched_parenthesis_missing)
{
    ast_t *ast;
    const char *input = "(command_a; command_b;;;";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_LPAREN);
}

Test(test_compounds, unmatched_parenthesis_newline)
{
    ast_t *ast;
    const char *input =
        "(command_a\n"
        "command_b;;; command_c)";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_LPAREN);
}

Test(test_compounds, unmatched_right_parenthesis)
{
    ast_t *ast;
    const char *input = "); ls";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_RPAREN);
}
