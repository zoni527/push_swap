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
	$(SRCDIR)reverse_rotate_operations.c

OBJ = $(SRC:.c=.o)

LIBDIR = ./libft/
LIB = libft.a

all: push_swap

push_swap: $(SRC) $(LIBDIR)libft.h
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(LIBDIR) $(SRC) -L$(LIBDIR) -l:$(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(LIBDIR) $< -L$(LIBDIR) -L:$(LIB) -o $@

clean:

fclean: clean
	rm -f ./push_swap_test_01

re: fclean all

.PHONY: clean fclean re all
