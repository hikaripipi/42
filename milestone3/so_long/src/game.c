/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:08:16 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 17:09:53 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 初始化游戏图像
int	init_game_images(t_game *game)
{
	int img_width, img_height;
	// 加载各种纹理文件
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
	// 检查加载是否成功
	if (!game->tiles.empty_img || !game->tiles.wall_img
		|| !game->tiles.collectible_img || !game->tiles.exit_img
		|| !game->tiles.player_img)
	{
		ft_printf("错误：无法加载游戏纹理文件\n");
		return (0);
	}
	ft_printf("游戏纹理加载成功！\n");
	return (1);
}

// 渲染游戏画面
void	render_game(t_game *game)
{
	void	*top_tile;

	int x, y;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->tiles.background_img, x * TILE_SIZE, y * TILE_SIZE);
			// 根据地图字符选择纹理
			if (game->map.grid[y][x] == WALL)
				top_tile = game->tiles.wall_img;
			else if (game->map.grid[y][x] == COLLECTIBLE)
				top_tile = game->tiles.collectible_img;
			else if (game->map.grid[y][x] == EXIT)
				top_tile = game->tiles.exit_img;
			else if (game->map.grid[y][x] == PLAYER)
				top_tile = game->tiles.player_img;
			else
				top_tile = game->tiles.empty_img;
			// 绘制纹理
			mlx_put_image_to_window(game->mlx, game->win, top_tile, x
				* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

// 检查地图上是否还有收集品
static int	has_collectibles(t_game *game)
{
	int x, y;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == COLLECTIBLE)
				return (1); // 还有收集品
			x++;
		}
		y++;
	}
	return (0); // 没有收集品了
}

// 处理移动到新位置的逻辑
static int	handle_move_to_position(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map.grid[new_y][new_x];
	// 检查是否撞墙
	if (target == WALL)
		return (0); // 不移动，不计数
	// 处理收集品
	if (target == COLLECTIBLE)
	{
		ft_printf("收集到物品！\n");
		game->map.grid[new_y][new_x] = EMPTY; // 移除收集品
	}
	// 处理出口
	if (target == EXIT)
	{
		if (!has_collectibles(game))
		{
			ft_printf("恭喜！你赢了！总移动次数: %d\n", game->moves + 1);
			close_game(game);
		}
		// 允许站在出口上，但不修改地图
	}
	// 清除原位置的玩家（如果不是出口）
	if (game->map.grid[game->map.player_y][game->map.player_x] != EXIT)
		game->map.grid[game->map.player_y][game->map.player_x] = EMPTY;
	// 更新玩家位置
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	// 在新位置放置玩家（如果不是出口）
	if (target != EXIT)
		game->map.grid[new_y][new_x] = PLAYER;
	// 增加移动计数并显示
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	// 重新渲染游戏
	render_game(game);
	return (1);
}

// 玩家向上移动
int	player_move_up(t_game *game)
{
	int	new_y;

	new_y = game->map.player_y - 1;
	// 检查边界
	if (new_y >= 0)
		handle_move_to_position(game, game->map.player_x, new_y);
	return (0);
}

// 玩家向下移动
int	player_move_down(t_game *game)
{
	int	new_y;

	new_y = game->map.player_y + 1;
	// 检查边界
	if (new_y < game->map.height)
		handle_move_to_position(game, game->map.player_x, new_y);
	return (0);
}

// 玩家向左移动
int	player_move_left(t_game *game)
{
	int	new_x;

	new_x = game->map.player_x - 1;
	// 检查边界
	if (new_x >= 0)
		handle_move_to_position(game, new_x, game->map.player_y);
	return (0);
}

// 玩家向右移动
int	player_move_right(t_game *game)
{
	int	new_x;

	new_x = game->map.player_x + 1;
	// 检查边界
	if (new_x < game->map.width)
		handle_move_to_position(game, new_x, game->map.player_y);
	return (0);
}

// 处理按键输入
int	handle_keypress(int keycode, t_game *game)
{
	ft_printf("按键按下：%d\n", keycode);
	// ESC键退出游戏
	if (keycode == 53) // macOS上的ESC键
		close_game(game);
	// 玩家移动 (WASD键)
	if (keycode == 13) // W键 - 向上
		player_move_up(game);
	else if (keycode == 1) // S键 - 向下
		player_move_down(game);
	else if (keycode == 0) // A键 - 向左
		player_move_left(game);
	else if (keycode == 2) // D键 - 向右
		player_move_right(game);
	return (0);
}

// 关闭游戏
int	close_game(t_game *game)
{
	ft_printf("正在关闭游戏...\n");
	cleanup_game(game);
	exit(0);
	return (0);
}

// 清理游戏资源
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
