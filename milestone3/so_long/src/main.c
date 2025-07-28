/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:11:42 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 17:12:01 by hikarimac        ###   ########.fr       */
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
	// 初始化玩家位置
	ft_find_player(game.map.grid, game.map.width, game.map.height,
		&game.map.player_x, &game.map.player_y);
	ft_printf("玩家初始位置: (%d, %d)\n", game.map.player_x, game.map.player_y);
	// 初始化游戏数据
	game.moves = 0;
	//-----------------------------------
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
	// 画像を初期化
	if (!init_game_images(&game))
	{
		ft_printf("Error: Failed to initialize game images\n");
		free_map_array(game.map.grid, game.map.height);
		return (1);
	}
	// 初始渲染游戏画面
	render_game(&game);
	// 设置事件处理函数
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game); // 只监听按键按下事件
	mlx_hook(game.win, 17, 0, close_game, &game);           // 处理窗口关闭事件
	// 启动游戏主循环（这很重要！）
	mlx_loop(game.mlx);
	// 释放内存（通常不会执行到这里）
	//----------------------------------
	free_map_array(game.map.grid, game.map.height);
	return (0);
}
