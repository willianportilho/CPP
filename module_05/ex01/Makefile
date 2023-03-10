# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:26:19 by wportilh          #+#    #+#              #
#    Updated: 2023/03/09 21:25:54 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES 	=		main.cpp		\
					Bureaucrat.cpp	\
					Form.cpp

NAME		=		form_up

CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -g3

SRC_PATH 	=		./
SRCS		=		$(addprefix $(SRC_PATH), $(SOURCES))

OBJ_PATH	=		obj/
OBJS		=		$(addprefix $(OBJ_PATH), $(SOURCES:.cpp=.o))

RM			=		rm -rf
VAL			=		valgrind --leak-check=full --show-leak-kinds=all --quiet
	
all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.cpp
					@mkdir -p obj
					@$(CC) $(FLAGS) -c $< -o $@

run:				$(NAME)
					@$(VAL) ./$(NAME)

clean:
					$(RM) $(OBJ_PATH)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
