# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:55:57 by oel-mado          #+#    #+#              #
#    Updated: 2025/02/04 19:42:50 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



msg:
	@echo "do make s or make c"

pf:
	make -C ft_printf re

lb:
	make -C libft re

s: pf
	cc server.c ft_printf/libftprintf.a -o server

c: lb pf
	cc client.c libft/libft.a ft_printf/libftprintf.a -o client

clean:
	make -C ft_printf clean
	make -C libft clean

fclean:
	make -C ft_printf fclean
	make -C libft fclean
	rm -f server client





