##
## Makefile for minishell in /home/chaix_a/Work/PSU_2015_minishell1
## 
## Made by Adrien Chaix
## email <adrien.chaix@epitech.eu>
## 
## Started on  Mon Feb  1 16:12:13 2016 Adrien Chaix
## Last update Fri Mar 11 15:15:32 2016 Adrien Chaix
##

CC		=	gcc

NAME_LIB	=	libsdloop.a

CFLAGS		=	-g -Wall -Werror -W -Wextra -I./include/ \
			-lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

SRC_LIB		=	main_loop_sdl.c \
			line.c \
			new_pixelarray.c \
			text.c \
			new_window.c \
			blit_size.c \
			pixel.c \
			init.c \

OBJS_LIB	=	$(SRC_LIB:.c=.o)

all:		$(NAME_LIB)

$(NAME_LIB):	$(OBJS_LIB)
		@rm -f $(NAME_LIB)
		@ar rc $(NAME_LIB) $(OBJS_LIB)
		@ranlib $(NAME_LIB)
		@cp $(NAME_LIB) ~/.froot/lib/
		@cp include/* ~/.froot/include

clean:
		@rm -f $(OBJS_LIB)

fclean:		clean
		@rm -f $(NAME_LIB)

re:		fclean all
