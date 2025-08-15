/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:02:12 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 17:11:54 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_file_size_and_rewind(int fd, off_t *file_size)
{
	*file_size = lseek(fd, 0, SEEK_END);
	if (*file_size < 0)
		return (0);
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (0);
	return (1);
}

static char	*read_entire_file(int fd, int *bytes_read)
{
	off_t	file_size;
	char	*buffer;

	if (!get_file_size_and_rewind(fd, &file_size))
		return (NULL);
	if (file_size == 0)
	{
		ft_printf("Error: Empty map file\n");
		return (NULL);
	}
	buffer = (char *)ft_calloc((size_t)file_size + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	*bytes_read = read_map_content(fd, buffer, (int)file_size);
	if (*bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

int	ft_isvalid_pass(char **map, int width, int height)
{
	int				**visited;
	int				result;
	int				player_pos[2];
	t_flood_params	params;

	visited = ft_create_visited(width, height);
	if (!visited)
		return (0);
	ft_find_player(map, width, height, player_pos);
	ft_printf("Player position: (%d, %d)\n", player_pos[0], player_pos[1]);
	params.x = player_pos[0];
	params.y = player_pos[1];
	params.width = width;
	params.height = height;
	ft_flood_fill(map, visited, params);
	result = ft_check_reachable(map, visited, width, height);
	ft_free_visited(visited, height);
	if (result)
		ft_printf("All positions are reachable!\n");
	else
		ft_printf("Some positions are unreachable!\n");
	return (result);
}

int	ft_validate_complete_map(char **map, int width, int height)
{
	ft_printf("=== Starting complete map validation ===\n");
	if (!ft_isvalid(map, width, height))
	{
		ft_printf("Error: Basic validation failed\n");
		return (0);
	}
	if (!ft_isvalid_pass(map, width, height))
	{
		ft_printf("Error: Path validation failed\n");
		return (0);
	}
	ft_printf("=== Map validation completely successful ===\n");
	return (1);
}

char	**parse_map_file(char *filename, int *width, int *height)
{
	int		fd;
	int		bytes_read;
	char	*buffer;
	char	**map;

	fd = open_map_file(filename);
	if (fd < 0)
		return (NULL);
	buffer = read_entire_file(fd, &bytes_read);
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}
	map = create_map_from_buffer(buffer, bytes_read, width, height);
	free(buffer);
	close(fd);
	return (map);
}
