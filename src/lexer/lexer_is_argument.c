/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** lexer_is_argument
*/

#include <42parser/lexer.h>
#include <42parser/token.h>
#include <stdbool.h>


/*
** Determines whether or not
** a given char is a valid
** argument char or not.
*/
bool lexer_is_argument_char(char c)
{
    const char *reserved_chars = RESERVED_CHARS;

    while (*reserved_chars != '\0') {
        if (c == *reserved_chars)
            return false;
        reserved_chars++;
    }
    return true;
}
