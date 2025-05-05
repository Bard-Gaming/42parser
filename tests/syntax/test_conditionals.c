/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** Unit tests for conditional
** syntax.
*/

#include <criterion/criterion.h>
#include <42parser/parser.h>
#include <42parser/error.h>


//////////////////////////////////////////////////
//                                              //
//                 PASSING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_conditionals, simple_test_conditional)
{
    ast_t *ast;
    const char *input =
        "if ( a == a ) then\n"
        "    echo bob\n"
        "    echo test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_conditionals, simple_command_conditional)
{
    ast_t *ast;
    const char *input =
        "if echo hi; then\n"
        "    echo bob\n"
        "    echo test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_conditionals, unmatched_test_paren)
{
    ast_t *ast;
    const char *input =
        "if ( a == b then\n"
        "    echo bob\n"
        "    echo test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_RPAREN);
}

Test(test_conditionals, unended_command_condition)
{
    ast_t *ast;
    const char *input =
        "if echo hi then\n"
        "    echo bob\n"
        "    echo test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_MISSING_THEN_ENDIF);
}

Test(test_conditionals, missing_endif)
{
    ast_t *ast;
    const char *input =
        "if ( a == a ) then\n"
        "    echo bob\n"
        "    echo test\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_MISSING_THEN_ENDIF);
}
