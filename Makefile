# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:55:57 by oel-mado          #+#    #+#              #
#    Updated: 2025/03/19 23:57:05 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: client server

bonus: client_bonus server_bonus

$(LB):
	make -C libft re
	make -C libft clean

server: mndtr/server.c $(LB)
	cc $(CFLAGS) mndtr/server.c $(LB) -o server

client: mndtr/client.c $(LB)
	cc $(CFLAGS) mndtr/client.c $(LB) -o client

client_bonus: bonus/client_bonus.c $(LB)
	cc $(CFLAGS) bonus/client_bonus.c $(LB) -o client_bonus

server_bonus: bonus/server_bonus.c $(LB)
	cc $(CFLAGS) bonus/server_bonus.c $(LB) -o server_bonus

re: fclean all

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f server client
	rm -f server_bonus client_bonus

.PHONY: re all clean fclean bonus
