/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:08:16 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 18:37:25 by hikarimac        ###   ########.fr       */
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
	if (!game->tiles.background_img || !game->tiles.empty_img
		|| !game->tiles.wall_img || !game->tiles.collectible_img
		|| !game->tiles.exit_img || !game->tiles.player_img)
	{
		ft_printf("Error: Failed to load game textures\n");
		return (0);
	}
	ft_printf("Game textures loaded successfully!\n");
	return (1);
}

void	cleanup_game(t_game *game)
{
	if (game->tiles.background_img)
		mlx_destroy_image(game->mlx, game->tiles.background_img);
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
