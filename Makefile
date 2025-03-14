# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:55:57 by oel-mado          #+#    #+#              #
#    Updated: 2025/03/14 16:16:02 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

cs: client server

$(LB):
	make -C libft re
	make -C libft clean

server: server.c $(LB)
	cc $(CFLAGS) server.c $(LB) -o server

client: client.c $(LB)
	cc $(CFLAGS) client.c $(LB) -o client

re: fclean cs

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f server client

.PHONY: re cs clean fclean
