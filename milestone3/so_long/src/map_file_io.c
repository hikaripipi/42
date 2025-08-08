/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:37:58 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/08 21:00:27 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Cannot open file %s\n", filename);
		return (-1);
	}
	ft_printf("File opened successfully: %s\n", filename);
	return (fd);
}

int	read_map_content(int fd, char *buffer, int max_size)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, max_size);
	if (bytes_read < 0)
	{
		ft_printf("Error: Failed to read file\n");
		return (-1);
	}
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

void	get_map_dimensions(char *buffer, int size, int *width, int *height)
{
	int	i;

	*height = 1;
	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			(*height)++;
		i++;
	}
	*width = 0;
	i = 0;
	while (i < size && buffer[i] != '\n')
	{
		(*width)++;
		i++;
	}
}

char	**allocate_map_array(int width, int height)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc(height, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = (char *)ft_calloc(width + 1, sizeof(char));
		if (!map[i])
		{
			cleanup_partial_allocation(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

void	fill_map_from_buffer(char **map, char *buffer, int size)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
		{
			map[row][col] = '\0';
			row++;
			col = 0;
		}
		else
		{
			map[row][col] = buffer[i];
			col++;
		}
		i++;
	}
	map[row][col] = '\0';
}
