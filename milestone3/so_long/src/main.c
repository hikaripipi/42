/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:39:52 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 19:19:09 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		ft_printf("Error: Failed to create window\n");
		return (0);
	}
	ft_printf("Window created successfully! Starting game loop...\n");
	return (1);
}

static int	load_and_validate_map(char *filename, t_game *game)
{
	if (!has_ber_extension(filename))
	{
		ft_printf("Error: Map file must have .ber extension\n");
		return (0);
	}
	game->map.grid = parse_map_file(filename, &game->map.width,
			&game->map.height);
	if (!game->map.grid)
	{
		ft_printf("Error: Failed to parse map file\n");
		return (0);
	}
	if (!finalize_loaded_map(game))
		return (0);
	return (1);
}

static void	start_game_loop(t_game *game)
{
	render_game(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error: Usage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	ft_printf("Map file: %s\n", argv[1]);
	if (!load_and_validate_map(argv[1], &game))
		return (1);
	game.moves = 0;
	if (!init_mlx_window(&game))
	{
		cleanup_game(&game);
		return (1);
	}
	if (!init_game_images(&game))
	{
		ft_printf("Error: Failed to initialize game images\n");
		cleanup_game(&game);
		return (1);
	}
	start_game_loop(&game);
	cleanup_game(&game);
	return (0);
}
