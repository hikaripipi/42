/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:37:08 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/22 18:15:14 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_background_and_floor(t_game *game, int x, int y,
		char tile_char)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.background_img, x
		* TILE_SIZE, y * TILE_SIZE);
	if (tile_char == COLLECTIBLE || tile_char == PLAYER || tile_char == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win, game->tiles.empty_img, x
			* TILE_SIZE, y * TILE_SIZE);
}

static void	render_tile_content(t_game *game, int x, int y, char tile_char)
{
	if (tile_char == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile_char == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tiles.collectible_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile_char == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->tiles.exit_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile_char == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->tiles.player_img, x
			* TILE_SIZE, y * TILE_SIZE);
}

static void	render_tile_at_position(t_game *game, int x, int y)
{
	char	tile_char;

	tile_char = game->map.grid[y][x];
	render_background_and_floor(game, x, y, tile_char);
	render_tile_content(game, x, y, tile_char);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile_at_position(game, x, y);
			if (x == game->map.player_x && y == game->map.player_y)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->tiles.player_img, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
