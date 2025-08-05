# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 19:04:38 by hikarimac         #+#    #+#              #
#    Updated: 2025/08/05 14:55:34 by hikarimac        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER_NAME = server
CLIENT_NAME = client

SERVER = src/server.c src/utils.c
CLIENT = src/client.c src/utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

# libftの設定
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

# ft_printfの設定
PRINTF_DIR = include/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(SERVER_NAME): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -o $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -o $(CLIENT_NAME)

clean:
	rm -f *.o
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re