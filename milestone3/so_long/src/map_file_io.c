/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:37:58 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/28 19:41:42 by hshinaga         ###   ########.fr       */
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

	*height = 0;
	*width = 0;
	i = 0;
	
	// 高さを計算（改行の数 + 1）
	while (i < size && buffer[i])
	{
		if (buffer[i] == '\n')
			(*height)++;
		i++;
	}
	if (i > 0 && buffer[i - 1] != '\n')
		(*height)++;
	
	// 幅を計算（最初の行の文字数）
	i = 0;
	while (i < size && buffer[i] && buffer[i] != '\n')
	{
		(*width)++;
		i++;
	}
	
	// 安全性チェック
	if (*width <= 0 || *height <= 0)
	{
		*width = 0;
		*height = 0;
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
	int	width;

	i = 0;
	row = 0;
	col = 0;
	width = 0;
	// 最初の行の幅を取得
	while (i < size && buffer[i] != '\n')
	{
		width++;
		i++;
	}
	i = 0;
	row = 0;
	col = 0;
	while (i < size && buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (col < width)
				map[row][col] = '\0';
			row++;
			col = 0;
		}
		else
		{
			if (col < width)
			{
				map[row][col] = buffer[i];
				col++;
			}
		}
		i++;
	}
	if (row < 100 && col < width)  // 安全な境界内であることを確認
		map[row][col] = '\0';
}
