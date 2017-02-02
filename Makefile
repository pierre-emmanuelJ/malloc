##
## Makefile for  in /home/jacqui_p/rendu/PSU_2016_malloc/
##
## Made by Pierre-Emmanuel Jacquier
## Login   <jacqui_p@epitech.eu>
##
## Started on  Mon Jan 30 10:56:43 2017 Pierre-Emmanuel Jacquier
## Last update Thu Feb  2 12:04:00 2017 Pierre-Emmanuel Jacquier
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I. -fPIC -Wall -Wextra

NAME	= libmy_malloc.so

SRCS	= malloc.c \
				realloc.c \
				free.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
