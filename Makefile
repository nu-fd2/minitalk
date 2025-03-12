# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:55:57 by oel-mado          #+#    #+#              #
#    Updated: 2025/03/12 17:12:40 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PF = ft_printf/libftprintf.a
LB = libft/libft.a

msg:
	@echo "do make s or make c"

$(PF):
	make -C ft_printf re
	make -C ft_printf clean

$(LB):
	make -C libft re
	make -C libft clean

s: $(LB) $(PF)
	cc server.c $(LB) $(PF) -o server

c: $(LB) $(PF)
	cc client.c $(LB) $(PF) -o client

cs:fclean c s

clean:
	make -C ft_printf clean
	make -C libft clean

fclean:
	make -C ft_printf fclean
	make -C libft fclean
	rm -f server client





