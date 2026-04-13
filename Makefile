##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

NAME    = my_world

CC      = clang
CFLAGS  = -Wall -Wextra -I include

SRC     = src/main.c    \
          src/draw.c    \
          src/toolbar.c \
          src/events.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

tests_run:
	echo "No tests"
