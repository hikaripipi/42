/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/28 17:42:30 by hshinaga         ###   ########.fr       */
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

char	**create_map_from_buffer(char *buffer, int bytes_read, int *width,
		int *height)
{
	char	**map;

	get_map_dimensions(buffer, bytes_read, width, height);
	map = allocate_map_array(*width, *height);
	if (!map)
		return (NULL);
	fill_map_from_buffer(map, buffer, bytes_read);
	return (map);
}

int	finalize_loaded_map(t_game *game)
{
	int	player_pos[2];
	int	counts[3];

	if (!ft_validate_complete_map(game->map.grid, game->map.width,
			game->map.height))
	{
		ft_printf("Error: Map validation failed\n");
		free_map_array(game->map.grid, game->map.height);
		return (0);
	}
	ft_find_player(game->map.grid, game->map.width, game->map.height,
		player_pos);
	game->map.player_x = player_pos[0];
	game->map.player_y = player_pos[1];
	ft_count_components(game->map.grid, game->map.width, game->map.height,
		counts);
	game->map.collectibles = counts[1];
	return (1);
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
