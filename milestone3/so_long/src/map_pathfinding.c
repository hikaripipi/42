/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/28 17:41:54 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_find_player(char **map, int width, int height, int *player_pos)
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
				player_pos[0] = j;
				player_pos[1] = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

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
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

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

void	ft_flood_fill(char **map, int **visited, t_flood_params params)
{
	if (params.x < 0 || params.x >= params.width || params.y < 0
		|| params.y >= params.height)
		return ;
	if (visited[params.y][params.x] == 1)
		return ;
	if (map[params.y][params.x] == '1')
		return ;
	visited[params.y][params.x] = 1;
	params.x++;
	ft_flood_fill(map, visited, params);
	params.x -= 2;
	ft_flood_fill(map, visited, params);
	params.x++;
	params.y++;
	ft_flood_fill(map, visited, params);
	params.y -= 2;
	ft_flood_fill(map, visited, params);
}

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
			if ((map[i][j] == 'C' || map[i][j] == 'E') && visited[i][j] != 1)
			{
				ft_printf("Unreachable position: (%d, %d) = '%c'\n", j, i,
					map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
