/*
** EPITECH PROJECT, 2025
** Project - 42parser
** File description:
** Implementation for
** parse_line
*/

#include <42parser/parser.h>
#include <42parser/lexer.h>


ast_t *parse_line(const char *line)
{
    parser_t parser;

    lexer_load_src(line);
    parser.current = lexer_scan();
    parser.next = lexer_scan();
    return parse_statement(&parser);
}
