/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for while loop
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
Test(test_while_loops, simple_while_loop)
{
    ast_t *ast;
    const char *input =
        "while (1)\n"
        "    echo bob\n"
        "end\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_while_loops, command_while_loop)
{
    ast_t *ast;
    const char *input =
        "while ({ command })\n"
        "    echo bob\n"
        "end\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_while_loops, while_no_args)
{
    ast_t *ast;
    const char *input = "while\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_WHILE_NO_ARGS);
}

Test(test_while_loops, missing_end)
{
    ast_t *ast;
    const char *input =
        "while (1)\n"
        "    echo bob\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_WHILE_MISSING_END);
}

Test(test_while_loops, unended_command_condition)
{
    ast_t *ast;
    const char *input =
        "while ({ echo hi )\n"
        "    echo bob\n"
        "end\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_WHILE_MISSING_BRACE);
}
