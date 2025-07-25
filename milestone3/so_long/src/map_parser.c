/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:02:12 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/25 18:14:41 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// 1. 打开文件（5-8行）
int open_map_file(char *filename)
{
    int fd;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Cannot open file %s\n", filename);
        return (-1);  // 返回-1表示错误
    }
    
    printf("File opened successfully: %s\n", filename);
    return (fd);  // 返回有效的文件描述符
}

// 2. 读取内容（8-10行）
int read_map_content(int fd, char *buffer, int max_size)
{
    int bytes_read;
    
    bytes_read = read(fd, buffer, max_size);
    if (bytes_read < 0)
    {
        printf("Error: Failed to read file\n");
        return (-1);
    }
    
    buffer[bytes_read] = '\0';  // 字符串结束符
    return (bytes_read);        // 返回读取的字节数
}
// 3. 统计尺寸（15-20行）
void get_map_dimensions(char *buffer, int size, int *width, int *height)
{
    int i;
    
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


// 4. 分配内存（10-15行）
char **allocate_map_array(int width, int height)
{
    char **map;
    int j;
    
    map = malloc(height * sizeof(char*));
    if (!map)
        return (NULL);
    
    j = 0;
    while (j < height)
    {
        map[j] = malloc((width + 1) * sizeof(char));
        if (!map[j])
        {
            free_map_array(map, j);  // 使用辅助函数
            return (NULL);
        }
        j++;
    }
    
    return (map);
}

    
// 5. 填充数据（20-25行）
void fill_map_from_buffer(char **map, char *buffer, int size)
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


//确认是不是指定的五个字符，不是的话返回-1
int	ft_isvalid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

//地图必须包含1个出口、至少1个收集品和1个起始位置才有效。如果地图包含重复字符（出口/起始位置），你应该显示错误消息。
int	ft_isvalid_3comp(char **map, int size)
{
    int count_e = 0;
    int count_c = 0;
    int count_p = 0;
    int i = 0;

    while (i < size)
    {
        if (*map[i]  == 'E')
        {
            count_e++;
        }
        else if (*map[i] == 'C')
        {
            count_c++;
        }
        else if (*map[i]  == 'P')
        {
            count_p++;
        }
        i++;
    }
    return (count_e == 1 && count_c >= 1 && count_p == 1);
}


int ft_isvalid_rec(char **map, int *width, int *height)
{
    int line_index = 0;
    int x = 0;
    
    if (width == NULL || height == NULL || map == NULL)
        return (-1);
        
    while (line_index < *height)
    {
        x = ft_strlen(map[line_index]);
        if (*width != x)
            return (-1);
        line_index++;
    }
    return (0);
}

// int isvalid(char **map)
// {
    
// }

// 6. 解析文件函数 把地图变成二维数组
char **parse_map_file(char *filename, int *width, int *height)
{
    int fd;
    int bytes_read;
    char buffer[1000];
    char **map;
    
    fd = open_map_file(filename);
    if (fd < 0)
        return (NULL);
    bytes_read = read_map_content(fd, buffer, 999);
    if (bytes_read < 0)
    {
        close(fd);
        return (NULL);
    }
    get_map_dimensions(buffer, bytes_read, width, height);
    map = allocate_map_array(*width, *height);
    if (!map)
    {
        close(fd);
        return (NULL);
    }
    fill_map_from_buffer(map, buffer, bytes_read);
    close(fd);
    return (map);
}

