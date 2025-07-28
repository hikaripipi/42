/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:08:16 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 17:29:16 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_game_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->tiles.background_img = mlx_xpm_file_to_image(game->mlx,
			"image/textures/bg.xpm", &img_width, &img_height);
	game->tiles.empty_img = mlx_xpm_file_to_image(game->mlx,
			"image/textures/floor.xpm", &img_width, &img_height);
	game->tiles.wall_img = mlx_xpm_file_to_image(game->mlx,
			"image/textures/wall.xpm", &img_width, &img_height);
	game->tiles.collectible_img = mlx_xpm_file_to_image(game->mlx,
			"image/textures/collectible.xpm", &img_width, &img_height);
	game->tiles.exit_img = mlx_xpm_file_to_image(game->mlx,
			"image/textures/exit.xpm", &img_width, &img_height);
	game->tiles.player_img = mlx_xpm_file_to_image(game->mlx,
			"image/textures/player.xpm", &img_width, &img_height);
	if (!game->tiles.empty_img || !game->tiles.wall_img
		|| !game->tiles.collectible_img || !game->tiles.exit_img
		|| !game->tiles.player_img)
	{
		ft_printf("Error: Failed to load game textures\n");
		return (0);
	}
	ft_printf("Game textures loaded successfully!\n");
	return (1);
}

static void	*get_tile_image(t_game *game, char tile_char)
{
	if (tile_char == WALL)
		return (game->tiles.wall_img);
	else if (tile_char == COLLECTIBLE)
		return (game->tiles.collectible_img);
	else if (tile_char == EXIT)
		return (game->tiles.exit_img);
	else if (tile_char == PLAYER)
		return (game->tiles.player_img);
	else
		return (game->tiles.empty_img);
}

void	render_game(t_game *game)
{
	void	*top_tile;
	int		x;
	int		y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->tiles.background_img, x * TILE_SIZE, y * TILE_SIZE);
			top_tile = get_tile_image(game, game->map.grid[y][x]);
			mlx_put_image_to_window(game->mlx, game->win, top_tile, x
				* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	cleanup_game(t_game *game)
{
	if (game->tiles.wall_img)
		mlx_destroy_image(game->mlx, game->tiles.wall_img);
	if (game->tiles.empty_img)
		mlx_destroy_image(game->mlx, game->tiles.empty_img);
	if (game->tiles.collectible_img)
		mlx_destroy_image(game->mlx, game->tiles.collectible_img);
	if (game->tiles.exit_img)
		mlx_destroy_image(game->mlx, game->tiles.exit_img);
	if (game->tiles.player_img)
		mlx_destroy_image(game->mlx, game->tiles.player_img);
	if (game->map.grid)
		free_map_array(game->map.grid, game->map.height);
}
