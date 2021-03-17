##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

CC = gcc
FLAGS = -Wall -Wextra
SRC	= main.c main_more.c another_one.c
OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)
NAME = mysh
LIB_FOLDER = ./lib/my
LIB_NAME = my

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_FOLDER)
		$(CC) $(FLAGS) -o $(NAME) $(SRC) -L$(LIB_FOLDER) -l$(LIB_NAME) -g3

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TEST)
		cd $(LIB_FOLDER) && make clean
		rm -f *~
		rm -f *#

fclean:		clean
		cd $(LIB_FOLDER) && make fclean
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

re:		fclean all
		cd $(LIB_FOLDER) && make re

auteur:
		echo $(USER) > auteur

.PHONY: 	all clean fclean re tests_run
