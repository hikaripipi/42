# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 19:04:38 by hikarimac         #+#    #+#              #
#    Updated: 2025/07/29 19:08:03 by hikarimac        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SOURCES = src/server.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

# libftの設定
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

# ft_printfの設定
PRINTF_DIR = include/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# OS自動検出
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# macOS
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	# Linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f *.o
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re