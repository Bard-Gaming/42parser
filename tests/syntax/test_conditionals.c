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
Test(test_conditionals, simple_conditional)
{
    ast_t *ast;
    const char *input =
        "if ( echo hi ) then\n"
        "    echo bob\n"
        "    echo test\n"
        "endif\n";

    ast = parse_input(input);
    cr_assert_neq(ast, NULL);
    cr_assert_eq(P_ERRNO, PE_NONE);
}
