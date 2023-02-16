SOURCES 	=		main.cpp Zombie.cpp zombieHorde.cpp

NAME		=		horde

CC			=		c++
CFLAGS		=		-Wall -Wextra -Werror -std=c++98

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
