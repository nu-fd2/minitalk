# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 02:37:11 by oel-mado          #+#    #+#              #
#    Updated: 2024/11/26 19:20:03 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c src/ft_prints.c src/ft_putadr.c\
		src/ft_putchar.c src/ft_puthex.c\
		src/ft_putnbr.c src/ft_putstr.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c src/ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
