/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 17:32:30 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup_partial_allocation(char **map, int allocated_rows)
{
	int	i;

	i = 0;
	while (i < allocated_rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_array(char **map, int allocated_rows)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < allocated_rows)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
