/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:51:26 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 17:11:59 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ========== INCLUDES ========== */
# include "include/ft_printf/ft_printf.h"
# include "include/libft/libft.h"
# include "include/mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ========== DEFINES ========== */
# define TILE_SIZE 32
# define SPRITE_SIZE 16

/* ========== MAP CHARACTERS ========== */
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* ========== STRUCTURES ========== */
typedef struct s_flood_params
{
	int		x;
	int		y;
	int		width;
	int		height;
}			t_flood_params;

typedef struct s_tiles
{
	void	*background_img;
	void	*wall_img;
	void	*empty_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
}			t_tiles;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_tiles	tiles;
	int		moves;
}			t_game;

/* ========== FUNCTION PROTOTYPES ========== */

// map_file_io.c
int			open_map_file(char *filename);
int			read_map_content(int fd, char *buffer, int max_size);
void		get_map_dimensions(char *buffer, int size, int *width, int *height);
char		**allocate_map_array(int width, int height);
void		fill_map_from_buffer(char **map, char *buffer, int size);

// map_validation.c
int			ft_isvalid_char(char c);
int			ft_isvalid_3comp(char **map, int width, int height);
int			ft_isvalid_rec(char **map, int width, int height);
int			ft_isvalid_wall(char **map, int width, int height);
int			ft_isvalid(char **map, int width, int height);

// map_pathfinding.c
void		ft_find_player(char **map, int width, int height, int *player_pos);
int			**ft_create_visited(int width, int height);
void		ft_free_visited(int **visited, int height);
void		ft_flood_fill(char **map, int **visited, t_flood_params params);
int			ft_check_reachable(char **map, int **visited, int width,
				int height);

// map_parser.c
char		**parse_map_file(char *filename, int *width, int *height);
int			ft_isvalid_pass(char **map, int width, int height);
int			ft_validate_complete_map(char **map, int width, int height);

// map_utils.c
void		cleanup_partial_allocation(char **map, int allocated_rows);
void		free_map_array(char **map, int allocated_rows);
char		**create_map_from_buffer(char *buffer, int bytes_read, int *width,
				int *height);
int			finalize_loaded_map(t_game *game);

// utils.c
int			ft_check_all_chars(char **map, int width, int height);
void		ft_count_components(char **map, int width, int height, int *counts);
int			has_ber_extension(const char *filename);

// game.c
int			init_game_images(t_game *game);
void		render_game(t_game *game);
void		cleanup_game(t_game *game);

// player_movement.c
int			move_player_direction(t_game *game, int new_x, int new_y);

// player_controls.c
int			player_move_up(t_game *game);
int			player_move_down(t_game *game);
int			player_move_left(t_game *game);
int			player_move_right(t_game *game);

// game_events.c
int			handle_keypress(int keycode, t_game *game);
int			close_game(t_game *game);
int			has_collectibles(t_game *game);

#endif