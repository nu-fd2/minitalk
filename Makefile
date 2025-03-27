# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 16:55:57 by oel-mado          #+#    #+#              #
#    Updated: 2025/03/27 02:21:53 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror

NAME = client

SNAME = server

BNAME = client_bonus

BSNAME = server_bonus

SRC = src/client.c src/server.c src/utils.c

BSRC = bonus/client_bonus.c bonus/server_bonus.c bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all: $(NAME) $(SNAME)

bonus: $(BNAME) $(BSNAME)

$(NAME): $(OBJ) src/minitalk.h
	cc $(CFLAGS) src/client.o src/utils.o -o $(NAME)

$(SNAME): $(OBJ) src/minitalk.h
	cc $(CFLAGS) src/server.o src/utils.o -o $(SNAME)

$(BNAME): $(BOBJ) bonus/minitalk_bonus.h
	cc $(CFLAGS) bonus/client_bonus.o bonus/utils_bonus.o -o $(BNAME)

$(BSNAME): $(BOBJ) bonus/minitalk_bonus.h
	cc $(CFLAGS) bonus/server_bonus.o bonus/utils_bonus.o -o $(BSNAME)

%.o: src/%.c 
	cc $(CFLAGS) $< -c $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(SNAME)
	rm -f $(BNAME) $(BSNAME)

re: fclean all

.PHOMY: all clean fclean re bonus