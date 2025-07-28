/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 17:25:16 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Check if a character is a valid map element */
int	ft_isvalid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

/* Validate that map contains exactly 1 exit, 1 player,
	and at least 1 collectible */
int	ft_isvalid_3comp(char **map, int width, int height)
{
	int	counts[3];

	ft_count_components(map, width, height, counts);
	return (counts[0] == 1 && counts[1] >= 1 && counts[2] == 1);
}

/* Check if the map is rectangular */
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

/* Check if the map is surrounded by walls */
int	ft_isvalid_wall(char **map, int width, int height)
{
	int	i;

	if (map == NULL)
		return (0);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/* Perform complete map validation */
int	ft_isvalid(char **map, int width, int height)
{
	ft_printf("=== Starting map validation ===\n");
	if (!ft_check_all_chars(map, width, height))
		return (0);
	if (!ft_isvalid_rec(map, width, height))
	{
		ft_printf("Error: Map is not rectangular\n");
		return (0);
	}
	if (!ft_isvalid_wall(map, width, height))
	{
		ft_printf("Error: Map is not surrounded by walls\n");
		return (0);
	}
	if (!ft_isvalid_3comp(map, width, height))
	{
		ft_printf("Error: Invalid map components\n");
		return (0);
	}
	ft_printf("=== Map validation successful ===\n");
	return (1);
}
