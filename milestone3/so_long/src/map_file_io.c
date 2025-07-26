/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/26 22:03:15 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 1. 打开文件
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

// 2. 读取内容
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

// 3. 统计尺寸
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

// 4. 分配内存
char	**allocate_map_array(int width, int height)
{
	char	**map;
	int		j;

	map = ft_calloc(height, sizeof(char *));
	if (!map)
		return (NULL);
	j = 0;
	while (j < height)
	{
		map[j] = ft_calloc((width + 1), sizeof(char));
		if (!map[j])
		{
			free_map_array(map, j);
			return (NULL);
		}
		j++;
	}
	return (map);
}

// 5. 填充数据
void	fill_map_from_buffer(char **map, char *buffer, int size)
{
	int i;
	int line_index;
	int letter_count;

	i = 0;
	line_index = 0;
	letter_count = 0;
	while (i < size)
	{
		if (buffer[i] != '\n')
		{
			map[line_index][letter_count] = buffer[i];
			letter_count++;
		}
		else
		{
			map[line_index][letter_count] = '\0';
			line_index++;
			letter_count = 0;
		}
		i++;
	}
	if (letter_count > 0)
		map[line_index][letter_count] = '\0';
}