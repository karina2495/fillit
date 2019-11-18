# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eidaho <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 11:33:40 by eidaho            #+#    #+#              #
#    Updated: 2019/10/28 11:33:52 by eidaho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = main.c free.c map.c valid.c solver.c check.c

OBJ = $(SRC:.c=.o)

LIB = libft.a

all: $(NAME)

$(NAME): $(LIB)
	gcc $(FLAGS) $(SRC) -I libft/libft.h $(LIB) -o $(NAME)

$(LIB):
	make -C libft

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all lib clean fclean re
