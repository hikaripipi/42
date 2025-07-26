/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:02:12 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/26 22:03:48 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 路径有效性检查（使用洪水填充算法）
int	ft_isvalid_pass(char **map, int width, int height)
{
	int	**visited;
	int	result;

	int player_x, player_y;
	// 创建visited数组
	visited = ft_create_visited(width, height);
	if (!visited)
		return (0);
	// 找到玩家位置
	ft_find_player(map, width, height, &player_x, &player_y);
	ft_printf("玩家位置: (%d, %d)\n", player_x, player_y);
	// 从玩家位置开始洪水填充
	ft_flood_fill(map, visited, player_x, player_y, width, height);
	// 检查所有C和E是否可达
	result = ft_check_reachable(map, visited, width, height);
	// 释放内存
	ft_free_visited(visited, height);
	if (result)
		ft_printf("所有位置都可达！\n");
	else
		ft_printf("有位置无法到达！\n");
	return (result);
}

// 完整地图验证（包含基本验证和路径验证）
int	ft_validate_complete_map(char **map, int width, int height)
{
	ft_printf("=== 开始完整地图验证 ===\n");
	// 先进行基本验证
	if (!ft_isvalid(map, width, height))
	{
		ft_printf("错误：基本验证失败\n");
		return (0);
	}
	// 然后进行路径验证
	if (!ft_isvalid_pass(map, width, height))
	{
		ft_printf("错误：路径验证失败\n");
		return (0);
	}
	ft_printf("=== 地图验证完全成功 ===\n");
	return (1);
}

// 6. 解析文件函数 把地图变成二维数组
char	**parse_map_file(char *filename, int *width, int *height)
{
	int		fd;
	int		bytes_read;
	char	buffer[1000];
	char	**map;

	fd = open_map_file(filename);
	if (fd < 0)
		return (NULL);
	bytes_read = read_map_content(fd, buffer, 999);
	if (bytes_read < 0)
	{
		close(fd);
		return (NULL);
	}
	get_map_dimensions(buffer, bytes_read, width, height);
	map = allocate_map_array(*width, *height);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	fill_map_from_buffer(map, buffer, bytes_read);
	close(fd);
	return (map);
}
