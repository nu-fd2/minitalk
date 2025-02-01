# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:55:57 by oel-mado          #+#    #+#              #
#    Updated: 2025/02/01 21:00:55 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



msg:
	@echo "do make s or make c"

pf:
	make -f ft_printf/Makefile all

lb:
	make -f libft/Makefile all

s: pf
	cc server.c ft_printf/libftprintf.a -o server

c: lb pf
	cc client.c libft/libft.a ft_printf/libftprintf.a -o client

clean:
	make -f ft_printf/Makefile clean
	make -f libft/Makefile clean

fclean: clean
	make -f ft_printf/Makefile fclean
	make -f libft/Makefile fclean
	rm -f server client





