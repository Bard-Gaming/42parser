/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** General and basic
** syntax tests
*/

#include <criterion/criterion.h>
#include <42parser/parser.h>
#include <42parser/error.h>


//////////////////////////////////////////////////
//                                              //
//                 PASSING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_basic, empty_input)
{
    ast_t *ast;
    const char *input = "";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_basic, whitespace_input)
{
    ast_t *ast;
    const char *input = "   \t\n   \t";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}
