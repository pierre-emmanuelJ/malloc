##
## Makefile for  in /home/jacqui_p/rendu/PSU_2016_malloc/
##
## Made by Pierre-Emmanuel Jacquier
## Login   <jacqui_p@epitech.eu>
##
## Started on  Mon Jan 30 10:56:43 2017 Pierre-Emmanuel Jacquier
## Last update Mon Jan 30 11:11:38 2017 Pierre-Emmanuel Jacquier
##

CC	= cc

RM	= rm -f

CFLAGS	+= -I.

NAME	= libmy_malloc.so

SRCS	= malloc.c \
				realloc.c \
				free.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
