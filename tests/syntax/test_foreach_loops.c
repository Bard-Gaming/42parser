/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Unit tests for foreach
** loop syntax
*/

#include <criterion/criterion.h>
#include <42parser/parser.h>
#include <42parser/error.h>


//////////////////////////////////////////////////
//                                              //
//                 PASSING TESTS                //
//                                              //
//////////////////////////////////////////////////
Test(test_foreach_loops, simple_foreach_loop)
{
    ast_t *ast;
    const char *input =
        "foreach x ( a b c )\n"
        "    echo $x\n"
        "end\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_foreach_loops, string_var_foreach_loop)
{
    ast_t *ast;
    const char *input =
        "foreach 'x' ( a b c )\n"
        "    echo $x\n"
        "end\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}

Test(test_foreach_loops, foreach_loop_no_list)
{
    ast_t *ast;
    const char *input =
        "foreach x ()\n"
        "    echo $x\n"
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
Test(test_foreach_loops, foreach_no_args)
{
    ast_t *ast;
    const char *input = "foreach\n";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_FOREACH_NO_ARGS);
}

Test(test_foreach_loops, foreach_missing_end)
{
    ast_t *ast;
    const char *input =
        "foreach x ( a b c )\n"
        "    echo $x";

    ast = parse_input(input);
    cr_assert_eq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_FOREACH_MISSING_END);
}
