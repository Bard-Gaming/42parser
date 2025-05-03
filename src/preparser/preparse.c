/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** preparse
*/

#include <42parser/preparser.h>


static bool should_end(const preparser_t *preparser)
{
    return
        preparser->current->type == TT_EOF ||
        preparser->current->type == TT_ERROR;
}

static void preparse_input(preparser_t *preparser)
{
    while (should_end(preparser)) {
        preparser_next(preparser);
    }
}

/*
** TODO:
** - substitute fnc
** - state idk
*/

/*
** Preparses a given input into an expanded
** one. The resulting buffer needs to be passed
** to free() by the user.
*/
char *preparse(const char *input)
{
    preparser_t preparser = { 0 };

    preparser_init(&preparser, input);
    preparse_input();
    preparser_term(&preparser);
    return preparser.output;
}
