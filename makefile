# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filferna <filferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 14:33:29 by filferna          #+#    #+#              #
#    Updated: 2024/08/05 18:10:05 by filferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c push_utils.c push_moves.c more_utils.c small_sort.c

OBJS = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

PRINT = ./ft_printf/libftprintf.a

FLAGS = -Werror -Wall -Wextra

COMPILER = cc

all: LIB $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(FLAGS) $(SRC) $(LIBFT) $(PRINT) -o $(NAME) -g

LIB:
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf

re: fclean all

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf

fclean:
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	rm push_swap
