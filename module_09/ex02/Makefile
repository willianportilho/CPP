# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:26:19 by wportilh          #+#    #+#              #
#    Updated: 2023/04/14 00:27:52 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES 	=		main.cpp		\
					PmergeMe.cpp	\
					Exceptions.cpp

NAME		=		PmergeMe

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -MMD -MP -std=c++98 -g3

SRC_PATH 	=		./
SRCS		=		$(addprefix $(SRC_PATH), $(SOURCES))

OBJ_PATH	=		obj/
OBJS		=		$(addprefix $(OBJ_PATH), $(SOURCES:.cpp=.o))
DEP			=		$(addprefix $(OBJ_PATH), $(OBJS:.o=.d))

RM			=		rm -rf
VAL			=		valgrind --leak-check=full --show-leak-kinds=all --quiet

-include			$(DEP)

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.cpp
					@mkdir -p obj
					@$(CC) $(FLAGS) -c $< -o $@

run:				$(NAME)
					@ARG=$$(seq 3000 | shuf); $(VAL) ./$(NAME) $$ARG

clean:
					$(RM) $(OBJ_PATH)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
