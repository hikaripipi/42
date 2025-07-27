/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:08:16 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/27 17:10:35 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 初始化游戏图像
int	init_game_images(t_game *game)
{
	int img_width, img_height;
	// 加载各种纹理文件
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
	void	*current_tile;

	int x, y;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			// 根据地图字符选择纹理
			if (game->map.grid[y][x] == WALL)
				current_tile = game->tiles.wall_img;
			else if (game->map.grid[y][x] == COLLECTIBLE)
				current_tile = game->tiles.collectible_img;
			else if (game->map.grid[y][x] == EXIT)
				current_tile = game->tiles.exit_img;
			else if (game->map.grid[y][x] == PLAYER)
				current_tile = game->tiles.player_img;
			else
				current_tile = game->tiles.empty_img;
			// 绘制纹理
			mlx_put_image_to_window(game->mlx, game->win, current_tile, x
				* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

// 处理按键输入
int	handle_keypress(int keycode, t_game *game)
{
	ft_printf("按键按下：%d\n", keycode);
	// ESC键退出游戏
	if (keycode == 53) // macOS上的ESC键
		close_game(game);
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
