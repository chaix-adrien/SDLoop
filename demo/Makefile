##
## Makefile for minishell in /home/chaix_a/Work/PSU_2015_minishell1
## 
## Made by Adrien Chaix
## email <adrien.chaix@epitech.eu>
## 
## Started on  Mon Feb  1 16:12:13 2016 Adrien Chaix
## Last update Fri Mar 11 15:11:49 2016 Adrien Chaix
##

CC		=	gcc

NAME		=	demo


CFLAGS		=	-g -W -Wall -I./include \
			-L/home/${USER}/.froot/lib \
			-I/home/${USER}/.froot/include \
			-lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lsdloop

SRC		=	main.c \

OBJS		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
