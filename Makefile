##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRCS	=	src/built_in/special.c 	\
			src/env/array.c 	\
			src/cmd_bin.c 	\
			src/utils/free.c		\
			src/env/set_env.c	\
			src/env/search_env.c\
			src/separator.c \
			src/utils/utils_separator.c\
			src/signal/pipe.c 		\
			src/signal/redi_of_pipe.c\
			src/utils/utils_pipe.c\
			src/signal/signal.c  	\
			src/utils/my_malloc.c\
			src/signal/redirection.c\
			src/built_in/build_cd.c  \
			src/utils/utils.c 	\
			src/built_in/pwd.c 		\
			src/utils/utils_redirection.c\
			src/check_file.c\
			src/signal/start.c 	\
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
