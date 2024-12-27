# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:58:04 by jvarila           #+#    #+#              #
#    Updated: 2024/12/16 17:29:35 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = ./

SRCDIR = ./
SRC =	$(SRCDIR)push_swap.c \
	$(SRCDIR)stack.c \
	$(SRCDIR)push_operations.c \
	$(SRCDIR)swap_operations.c \
	$(SRCDIR)rotate_operations.c \
	$(SRCDIR)reverse_rotate_operations.c \
	$(SRCDIR)input_validation.c \
	$(SRCDIR)input_parsing.c \
	$(SRCDIR)sort_stack.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

LIBDIR = ./libft/
LIB = libft.a

all: push_swap

push_swap: $(OBJ) $(LIBDIR)libft.h
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(LIBDIR) $(OBJ) -L$(LIBDIR) -l:$(LIB) -o $@ -g

%.o: %.c
	$(CC) -c $< -o $@ -g

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) ./push_swap

re: fclean all

.PHONY: clean fclean re all
