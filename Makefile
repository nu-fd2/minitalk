# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:55:57 by oel-mado          #+#    #+#              #
#    Updated: 2025/03/14 12:37:21 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LB = libft/libft.a

msg:
	@echo "do make server or make client or make cs for both"

$(LB):
	make -C libft re
	make -C libft clean

server: $(LB)
	cc server.c $(LB) -o server

client: $(LB)
	cc client.c $(LB) -o client

cs:fclean client server

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f server client

.PHONY: msg s c cs clean fclean
