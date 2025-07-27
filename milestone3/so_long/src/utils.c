/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:01:07 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/26 23:09:12 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 检查地图中所有字符是否有效
int	ft_check_all_chars(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (!ft_isvalid_char(map[i][j]))
			{
				ft_printf("错误：发现无效字符 '%c'\n", map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// 计算地图中各组件的数量
void	ft_count_components(char **map, int width, int height, int *counts)
{
	int	i;
	int	j;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E')
				counts[0]++;
			else if (map[i][j] == 'C')
				counts[1]++;
			else if (map[i][j] == 'P')
				counts[2]++;
			j++;
		}
		i++;
	}
}
