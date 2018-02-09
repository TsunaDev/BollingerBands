##
## EPITECH PROJECT, 2018
## Bollinger
## File description:
## Bollinger's makefile
##

SRC		=	src/Main.cpp		\
			src/Bollinger.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Werror -Iinclude -ggdb3

NAME		=	bollinger

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
