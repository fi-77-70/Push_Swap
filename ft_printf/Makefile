# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filferna <filferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 19:11:35 by filferna          #+#    #+#              #
#    Updated: 2024/05/01 21:17:13 by filferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c  ft_putchar.c  ft_puthexx.c  ft_putptr.c  ft_putudten.c\
	  ft_puthex.c   ft_putnbr.c	 ft_putstr.c\


OBJS = $(SRC:.c=.o)

COMPILER = cc
FLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): 
		$(COMPILER) $(FLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJS)
#		$(COMPILER) $(FLAGS) ft_printf.c $(NAME) -g

re:		fclean $(NAME)

clean: 
		rm -f $(OBJS)

fclean:
		rm -f $(NAME)
