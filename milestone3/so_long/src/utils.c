/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:01:07 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 17:11:56 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Check if all characters in the map are valid game elements */
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
				ft_printf("Error: Invalid character '%c' found\n", map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/* Count the number of exits, collectibles, and players in the map */
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

int	has_ber_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}
