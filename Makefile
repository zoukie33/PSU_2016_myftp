##
## Makefile for h in /home/zoukie/epitech/PSU_2016_myftp
## 
## Made by zoukie
## Login   <romain.gadrat@epitech.eu>
## 
## Started on  Thu May  4 17:14:30 2017 zoukie
## Last update Mon May 22 02:47:11 2017 
##

CC	=	gcc

NAME	=	server

SRC	=	src/my_ftp.c	\
		src/init_ftp.c	\
		src/my_funcs.c	\
		src/gest_cmds.c	\
		src/cmds/liste_cmds1.c	\
		src/cmds/liste_cmds2.c	\
		src/cmds/liste_cmds3.c	\
		src/cmds/active.c	\
		src/my_str_to_wordtab.c	\
		src/cmds/my_ls.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./inc -W -Wall -Wextra -Werror -pedantic

RM	=	rm -fr

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

