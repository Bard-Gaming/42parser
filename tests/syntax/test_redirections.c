/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for redirection
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
Test(test_redirections, redir_out_file)
{
    ast_t *ast;
    const char *input = "echo test > file arg\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_redirections, redir_out_fd)
{
    ast_t *ast;
    const char *input = "echo test >&1 arg\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_redirections, redir_append_file)
{
    ast_t *ast;
    const char *input = "echo test >> file arg\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_redirections, redir_input_file)
{
    ast_t *ast;
    const char *input = "cat < file arg";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_redirections, redir_input_fd)
{
    ast_t *ast;
    const char *input = "cat <&3 arg";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_redirections, heredoc_redir)
{
    ast_t *ast;
    const char *input = "cat << EOF";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_redirections, herestr_redir)
{
    ast_t *ast;
    const char *input = "cat <<< hello";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

//////////////////////////////////////////////////
//                                              //
//                 FAILING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_redirections, redir_null_command)
{
    ast_t *ast;
    const char *input = "2>&1\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NULL_COMMAND);
}

Test(test_redirections, redir_no_file)
{
    ast_t *ast;
    const char *input = "echo test >\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_MISSING_REDIRECT_NAME);
}

Test(test_redirections, redir_append_with_fd)
{
    ast_t *ast;
    const char *input = "echo test >>&2\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_REDIRECT_WITH_ILLEGAL_FD);
}

Test(test_redirections, heredoc_no_end)
{
    ast_t *ast;
    const char *input = "cat <<";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_EMPTY_HEREDOC);
}

Test(test_redirections, heredoc_illegal_fd)
{
    ast_t *ast;
    const char *input = "cat <<&2";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_REDIRECT_WITH_ILLEGAL_FD);
}

Test(test_redirections, herestr_no_end)
{
    ast_t *ast;
    const char *input = "cat <<<";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_EMPTY_HERESTR);
}

Test(test_redirections, herestr_illegal_fd)
{
    ast_t *ast;
    const char *input = "cat <<<&2";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_REDIRECT_WITH_ILLEGAL_FD);
}
