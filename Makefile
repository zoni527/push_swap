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

SRCDIR = ./src/
INCDIR = ./include/

SRC =	$(SRCDIR)push_swap.c \
	$(SRCDIR)input_parsing.c \
	$(SRCDIR)input_validation.c \
	$(SRCDIR)sort_stack.c \
	$(SRCDIR)sort_three.c \
	$(SRCDIR)insertion_sort_01.c \
	$(SRCDIR)insertion_sort_02.c \
	$(SRCDIR)element_index_helpers.c \
	$(SRCDIR)element_value_helpers_01.c \
	$(SRCDIR)element_value_helpers_02.c \
	$(SRCDIR)node_helpers.c \
	$(SRCDIR)cleanup_and_exit.c \
	$(SRCDIR)swap_operations.c \
	$(SRCDIR)push_operations.c \
	$(SRCDIR)rotate_operations.c \
	$(SRCDIR)rotate_n_operations.c \
	$(SRCDIR)reverse_rotate_operations.c \
	$(SRCDIR)reverse_rotate_n_operations.c \
	$(SRCDIR)stack.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

LIBDIR = ./libft/
LIB = libft.a
LIBH = libft.h

all: push_swap

push_swap: $(OBJ) $(LIBDIR)$(LIBH) $(LIBDIR)$(LIB)
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(LIBDIR) $(OBJ) -L$(LIBDIR) -l:$(LIB) -o $@ -g

$(LIBDIR)$(LIB):
	make libft.a -C ./libft/

%.o: %.c
	$(CC) -c $< -o $@ -g

clean:
	make clean -C ./libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft/
	$(RM) ./push_swap

re: fclean all

.PHONY: clean fclean re all phony
