/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for command
** substitutions
*/

#include <criterion/criterion.h>
#include <42parser/parser.h>
#include <42parser/error.h>


//////////////////////////////////////////////////
//                                              //
//                 PASSING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_substitutions, simple_substitution)
{
    ast_t *ast;
    const char *input = "echo `ls`";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_substitutions, multi_arg_substitution)
{
    ast_t *ast;
    const char *input = "echo `ls -ld .`";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_substitutions, simple_str_substitution)
{
    ast_t *ast;
    const char *input = "echo \"`ls`\"";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_substitutions, unmatched_backtick)
{
    ast_t *ast;
    const char *input = "echo \"`ls\"";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_BACKTICK);
}
