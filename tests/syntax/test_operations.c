/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for operation
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
Test(test_operations, simple_operation_and)
{
    ast_t *ast;
    const char *input = "echo a && echo b";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_operations, simple_operation_or)
{
    ast_t *ast;
    const char *input = "echo a || echo b";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_operations, multiple_operations)
{
    ast_t *ast;
    const char *input = "echo a && echo b || echo c && echo d";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_operations, missing_lhs)
{
    ast_t *ast;
    const char *input = "|| echo b\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}

Test(test_operations, missing_rhs)
{
    ast_t *ast;
    const char *input = "echo a ||\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}

Test(test_operations, only_operator)
{
    ast_t *ast;
    const char *input = "&&\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}

Test(test_operations, missing_middle)
{
    ast_t *ast;
    const char *input = "echo a && || echo c\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}
