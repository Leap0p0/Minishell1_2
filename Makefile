##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRCS	=	src/special.c 	\
			src/array.c 	\
			src/cmd_bin.c 	\
			src/free.c		\
			src/set_env.c	\
			src/search_env.c\
			src/separator.c \
			src/utils_separator.c\
			src/build_cd.c  \
			src/utils.c 	\
			src/pwd.c 		\
			src/start.c 	\
			src/main.c		\


OBJS	=	$(SRCS:.c=.o)

NAME	=	mysh

RM	=	rm -f

INC 	=	-Iinclude

LIB	=	-L lib -lmy

CC	=	gcc

CFLAGS	=	$(INC) -W -Wall -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

clean:
		make clean -C ./lib/my/
		$(RM) $(OBJS)

fclean:		clean
		make fclean -C ./lib/my/
		$(RM) $(NAME)

re:		fclean all
