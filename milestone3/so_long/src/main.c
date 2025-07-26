/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:45:09 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/26 22:20:46 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	// 引数チェック
	if (argc != 2)
	{
		ft_printf("Error: Usage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	ft_printf("Map file: %s\n", argv[1]);
	// マップを解析
	game.map.grid = parse_map_file(argv[1], &game.map.width, &game.map.height);
	if (!game.map.grid)
	{
		ft_printf("Error: Failed to parse map file\n");
		return (1);
	}
	// 成功メッセージ
	ft_printf("Map loaded successfully!\n");
	ft_printf("Map dimensions: %d x %d\n", game.map.width, game.map.height);
	// テスト用：マップを表示
	ft_printf("Map content:\n");
	for (int i = 0; i < game.map.height; i++)
	{
		ft_printf("%s\n", game.map.grid[i]);
	}
	ft_isvalid(game.map.grid, game.map.width, game.map.height);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		free_map_array(game.map.grid, game.map.height);
		return (1);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * TILE_SIZE,
			game.map.height * TILE_SIZE, "so_long");
	if (!game.win)
	{
		ft_printf("Error: Failed to create window\n");
		free_map_array(game.map.grid, game.map.height);
		return (1);
	}
	ft_printf("Window created successfully! Starting game loop...\n");
	// ゲームループを開始（これが重要！）
	mlx_loop(game.mlx);
	// メモリを解放（通常ここには到達しない）
	free_map_array(game.map.grid, game.map.height);
	return (0);
}
