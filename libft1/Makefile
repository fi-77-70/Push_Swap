# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filferna <filferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 19:58:05 by filferna          #+#    #+#              #
#    Updated: 2024/04/29 19:58:21 by filferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE =  ft_memcmp.c	  ft_strdup.c	 ft_strtrim.c\
			ft_atoi.c     ft_memcpy.c	  ft_striteri.c  ft_substr.c\
			ft_bzero.c  ft_memmove.c	  ft_strjoin.c	 ft_tolower.c\
			ft_calloc.c   ft_memset.c	  ft_strlcat.c	 ft_toupper.c\
			ft_isalnum.c  ft_putchar_fd.c  ft_strlcpy.c\
			ft_isalpha.c  ft_putendl_fd.c  ft_strlen.c\
			ft_isascii.c  ft_putnbr_fd.c   ft_strmapi.c\
			ft_isdigit.c  ft_putstr_fd.c   ft_strncmp.c\
			ft_isprint.c  ft_split.c	  ft_strnstr.c\
			ft_itoa.c     ft_memchr.c	 ft_strchr.c ft_strrchr.c\

BONUS_SRC = ft_lstclear.c ft_lstsize.c ft_lstiter.c ft_lstmap.c ft_lstlast.c ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c\

OBJ = $(SOURCE:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
COMPILER = cc

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAG) -c $(SOURCE)
		ar rc $(NAME) $(OBJ)

bonus: $(NAME)
		$(COMPILER) $(FLAG) -c $(BONUS_SRC)
		ar rc $(NAME) $(BONUS_OBJ)

re:	fclean $(NAME)

clean:	
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
