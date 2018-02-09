##
## EPITECH PROJECT, 2018
## Bollinger
## File description:
## Bollinger's makefile
##

SRC		=	src/Main.cpp		\
			src/Bollinger.cpp	\
			src/Display.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Werror -Iinclude

NAME		=	bollinger

all:	$(NAME)

debug:	CXXFLAGS += -ggdb3
debug:	fclean all

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
