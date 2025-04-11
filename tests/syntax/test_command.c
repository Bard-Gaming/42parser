/*
** EPITECH PROJECT, 2025
** Project - 42sh
** File description:
** Unit tests for command
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
Test(test_command, simple_command)
{
    ast_t *ast;
    const char *input = "echo bob";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_command, multiple_commands_nl)
{
    ast_t *ast;
    const char *input =
        "echo bob\n"
        "echo command_2";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}


Test(test_command, multiple_commands_sc)
{
    ast_t *ast;
    const char *input =
        "echo bob;;;;"
        "echo command_2;;";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_command, raw_string)
{
    ast_t *ast;
    const char *input = "echo 'hewwo :3'";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_command, format_string)
{
    ast_t *ast;
    const char *input = "echo \"hewwo :3\"";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_command, unmatched_raw_string)
{
    ast_t *ast;
    const char *input = "echo 'hello\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_RAW_STRING);
}

Test(test_command, unmatched_format_string)
{
    ast_t *ast;
    const char *input = "echo \"hello";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_UNMATCHED_FORMAT_STRING);
}
