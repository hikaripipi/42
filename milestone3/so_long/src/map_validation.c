/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/26 22:07:03 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 确认是不是指定的五个字符，是的话返回1，不是返回0
int	ft_isvalid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

// 地图必须包含1个出口、至少1个收集品和1个起始位置才有效
int	ft_isvalid_3comp(char **map, int width, int height)
{
	int	counts[3];

	ft_count_components(map, width, height, counts);
	return (counts[0] == 1 && counts[1] >= 1 && counts[2] == 1);
}

// 检查是否为矩形
int	ft_isvalid_rec(char **map, int width, int height)
{
	int	line_index;
	int	x;

	line_index = 0;
	x = 0;
	if (map == NULL)
		return (0);
	while (line_index < height)
	{
		x = ft_strlen(map[line_index]);
		if (width != x)
			return (0);
		line_index++;
	}
	return (1);
}

// 检查边界是否为墙
int	ft_isvalid_wall(char **map, int width, int height)
{
	int	i;

	if (map == NULL)
		return (0);
	// 检查上下边界
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	// 检查左右边界
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

// 统一验证函数
int	ft_isvalid(char **map, int width, int height)
{
	ft_printf("=== 开始地图验证 ===\n");
	if (!ft_check_all_chars(map, width, height))
		return (0);
	if (!ft_isvalid_rec(map, width, height))
	{
		ft_printf("错误：不是矩形\n");
		return (0);
	}
	if (!ft_isvalid_wall(map, width, height))
	{
		ft_printf("错误：边界不是墙壁\n");
		return (0);
	}
	if (!ft_isvalid_3comp(map, width, height))
	{
		ft_printf("错误：地图组件不正确\n");
		return (0);
	}
	ft_printf("=== 地图验证成功===\n");
	return (1);
}
