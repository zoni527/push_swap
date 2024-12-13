# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:58:04 by jvarila           #+#    #+#              #
#    Updated: 2024/12/13 16:10:30 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./

SRC =	$(NAME).c
HF =	$(NAME).h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HF) ./libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) -L./libft/ -l:libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

./libft/libft.a: phony
	@make -C ./libft/

clean:
	@make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

phony:

.PHONY: clean fclean re bonus phony
