/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for variable
** syntax
*/

#include <criterion/criterion.h>
#include <42parser/parser.h>
#include <42parser/error.h>


//////////////////////////////////////////////////
//                                              //
//                 PASSING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_variables, simple_variable)
{
    ast_t *ast;
    const char *input = "echo $var";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_variables, composed_variable)
{
    ast_t *ast;
    const char *input = "echo path/$file";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_variables, composed_variable_str)
{
    ast_t *ast;
    const char *input = "echo \"path hehe $file \"";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_variables, bracket_variable)
{
    ast_t *ast;
    const char *input = "echo \"path hehe ${file} e \"";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}
