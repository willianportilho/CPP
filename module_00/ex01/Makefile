SOURCES 	=		main.cpp PhoneBook.cpp Contact.cpp

NAME		=		cell_phone

CC			=		c++
CFLAGS		=		-g3 Wall -Wextra -Werror -std=c++98

SRC_PATH 	=		./
SRCS		=		${addprefix ${SRC_PATH}, ${SOURCES}}

OBJ_PATH	=		obj/
OBJS		=		$(addprefix $(OBJ_PATH), $(SOURCES:.cpp=.o))

RM			=		rm -rf
	
all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

${OBJ_PATH}%.o:		$(SRC_PATH)%.cpp
					@mkdir -p obj
					@${CC} ${FLAGS} -c $< -o $@

clean:
					$(RM) $(OBJ_PATH)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
