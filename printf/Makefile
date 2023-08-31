# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:52:59 by jquil             #+#    #+#              #
#    Updated: 2022/12/05 15:43:52 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_itoa.c		\
				ft_strlen.c		\
				ft_printf.c		\
				ft_putnbr_hexa.c \
				ft_putnbr_unsign.c \
				ft_unsigned_itoa.c \
				ft_varg.c \

OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

all:	$(NAME)

$(NAME):  $(OBJ)
	cc -c $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
