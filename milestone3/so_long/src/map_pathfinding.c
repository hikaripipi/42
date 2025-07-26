/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/26 22:04:21 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 找到玩家位置
void	ft_find_player(char **map, int width, int height, int *player_x,
		int *player_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

// 创建访问数组
int	**ft_create_visited(int width, int height)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)ft_calloc(height, sizeof(int *));
	if (!visited)
		return (NULL);
	while (i < height)
	{
		visited[i] = (int *)ft_calloc(width, sizeof(int));
		if (!visited[i])
		{
			return (NULL);
		}
		i++;
	}
	return (visited);
}

// 释放访问数组
void	ft_free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	if (!visited)
		return ;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

// 洪水填充递归函数
void	ft_flood_fill(char **map, int **visited, int x, int y, int width,
		int height)
{
	// 边界检查：超出地图范围
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	// 如果已经访问过
	if (visited[y][x] == 1)
		return ;
	// 如果是墙壁，不能通过
	if (map[y][x] == '1')
		return ;
	// 标记为已访问
	visited[y][x] = 1;
	// 递归访问四个方向
	ft_flood_fill(map, visited, x + 1, y, width, height);
	ft_flood_fill(map, visited, x - 1, y, width, height);
	ft_flood_fill(map, visited, x, y + 1, width, height);
	ft_flood_fill(map, visited, x, y - 1, width, height);
}

// 检查所有收集品和出口是否可达
int	ft_check_reachable(char **map, int **visited, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			// 如果是C或E，但没有被访问到
			if ((map[i][j] == 'C' || map[i][j] == 'E') && visited[i][j] != 1)
			{
				ft_printf("无法到达的位置: (%d, %d) = '%c'\n", j, i, map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
