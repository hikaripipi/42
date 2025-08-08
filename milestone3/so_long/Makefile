# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 18:44:08 by hikarimac         #+#    #+#              #
#    Updated: 2025/08/08 20:35:03 by hikarimac        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = src/main.c src/map_parser.c src/map_file_io.c src/map_validation.c src/map_pathfinding.c src/map_utils.c src/game.c src/game_render.c src/player_movement.c src/player_controls.c src/game_events.c src/utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

# libftの設定
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

# ft_printfの設定
PRINTF_DIR = include/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# MiniLibXの設定
MLX_DIR = include/mlx

MLX = $(MLX_DIR)/libmlx.a

# MLXリンクフラグ (macOS)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# インクルードパス
CFLAGS += -I$(MLX_DIR)

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