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

Test(test_conditionals, test_conditional_else)
{
    ast_t *ast;
    const char *input =
        "if ( a == a ) then\n"
        "    echo bob\n"
        "    echo test\n"
        "else\n"
        "    echo not bob\n"
        "    echo not test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_conditionals, inline_if_stmnt)
{
    ast_t *ast;
    const char *input =
        "if ( a == b ) echo hi\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_conditionals, inline_and_multiline_if_stmnt)
{
    ast_t *ast;
    const char *input =
        "if ( a == b ) then\n"
        "    echo hi\n"
        "else if (a == a) echo hi";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_conditionals, complex_test_conditional)
{
    ast_t *ast;
    const char *input =
        "if ( b == a ) then\n"
        "    echo 1\n"
        "else if ( b == b ) then\n"
        "    echo 2\n"
        "else if ( b == c ) then\n"
        "    echo 3\n"
        "else\n"
        "    echo 4\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_conditionals, simple_command_conditional)
{
    ast_t *ast;
    const char *input =
        "if ({ echo hi }) then\n"
        "    echo bob\n"
        "    echo test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_conditionals, complex_command_conditional)
{
    ast_t *ast;
    const char *input =
        "if ({ echo hi }) then\n"
        "    echo bob\n"
        "    echo test\n"
        "else if ({ echo not hi }) then\n"
        "    echo bob2\n"
        "    echo test2\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_conditionals, if_stmnt_else_end)
{
    ast_t *ast;
    const char *input =
        "if ( a == a ) then\n"
        "    echo bob\n"
        "    echo test\n"
        "else\n";  // this is valid syntax apparently. ask TCSH idk

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
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_LPAREN);
}

Test(test_conditionals, unended_command_condition)
{
    ast_t *ast;
    const char *input =
        "if ({ echo hi ) then\n"
        "    echo bob\n"
        "    echo test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_IF_MISSING_BRACE);
}

Test(test_conditionals, empty_if)
{
    ast_t *ast;
    const char *input = "if (a == b)\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_IF_EMPTY_BODY);
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
