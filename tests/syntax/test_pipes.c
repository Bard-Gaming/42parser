/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for pipe
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
Test(test_pipes, simple_pipe)
{
    ast_t *ast;
    const char *input = "echo bob | cat";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_pipes, simple_pipeline)
{
    ast_t *ast;
    const char *input = "echo bob | sort | cat | cat | column";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_pipes, pipeline_compound)
{
    ast_t *ast;
    const char *input = "(echo zfile | ls -t | echo haha) | sort";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_redirections, only_pipe)
{
    ast_t *ast;
    const char *input = "|";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}

Test(test_redirections, pipe_no_right)
{
    ast_t *ast;
    const char *input = "ls |";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}

Test(test_redirections, pipe_no_left)
{
    ast_t *ast;
    const char *input = "| cat";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}
