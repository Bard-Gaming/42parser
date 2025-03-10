##
## EPITECH PROJECT, 2024
## Project - 42parser
## File description:
## Makefile used to help
## and facilitate the
## compilation of the
## 42parser library
##

CC = gcc
CFLAGS =

NAME = libparse.a

INCLUDE_DIR = include/

SRC_FILES =	src/ast/ast_create.c			\

OBJ_FILES = $(SRC_FILES:.c=.o)

.PHONY = all debug clean fclean re

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -I./$(INCLUDE_DIR) $(CFLAGS) -o $@

$(NAME): $(OBJ_FILES)
	@ar rc $(NAME) $(OBJ_FILES)

debug: CFLAGS += -ggdb -Wall -Wextra
debug: fclean $(NAME)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
