# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psousa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 08:53:47 by psousa          #+#    #+#              #
#    Updated: 2023/01/05 08:53:48 by psousa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SERVER = server
CLIENT = client

SERVER_BNS = server_bonus
CLIENT_BNS = client_bonus

SRC_SERVER_BNS = server_bonus.c
OBJ_SERVER_BNS = $(SRC_SERVER_BNS:.c=.o)

SRC_CLIENT_BNS = client_bonus.c
OBJ_CLIENT_BNS = $(SRC_CLIENT_BNS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft

$(SERVER):	$(OBJ_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o server

$(CLIENT):	$(OBJ_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o client

$(SERVER_BNS):	$(OBJ_SERVER_BNS) $(LIBFT)
		$(CC) $(CFLAGS) $(SRC_SERVER_BNS) $(LIBFT) -o server_bonus

$(CLIENT_BNS):	$(OBJ_CLIENT_BNS) $(LIBFT)
		$(CC) $(CFLAGS) $(SRC_CLIENT_BNS) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)
	rm -rf $(OBJ_SERVER_BNS) $(OBJ_CLIENT_BNS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVER) $(CLIENT)
	rm -rf $(SERVER_BNS) $(CLIENT_BNS)

re:	fclean	all

bonus:	$(SERVER_BNS) $(CLIENT_BNS) 
