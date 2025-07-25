# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 18:44:08 by hikarimac         #+#    #+#              #
#    Updated: 2025/07/25 18:14:15 by hikarimac        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = src/main.c src/map_parser.c src/game.c src/utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

# libftの設定
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f *.o
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re