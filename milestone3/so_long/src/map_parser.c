/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:02:12 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/25 22:28:19 by hikarimac        ###   ########.fr       */
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

//确认是不是指定的五个字符，是的话返回1，不是返回0
int	ft_isvalid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

//地图必须包含1个出口、至少1个收集品和1个起始位置才有效
int	ft_isvalid_3comp(char **map, int width, int height)
{
    int count_e = 0;
    int count_c = 0;
    int count_p = 0;
    int i = 0;
    int j = 0;

    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'E')
                count_e++;
            else if (map[i][j] == 'C')
                count_c++;
            else if (map[i][j] == 'P')
                count_p++;
            j++;
        }
        i++;
    }
    return (count_e == 1 && count_c >= 1 && count_p == 1);
}

int ft_isvalid_rec(char **map, int width, int height)
{
    int line_index = 0;
    int x = 0;
    
    if (map == NULL)
        return (0);
        
    while (line_index < height)
    {
        x = ft_strlen(map[line_index]);
        if (width != x)
            return (0);  // 不是矩形，返回0
        line_index++;
    }
    return (1);  // 是矩形，返回1
}

int ft_isvalid_wall(char **map, int width, int height)
{
    int i;
    
    if (map == NULL)
        return (0);
    
    // 检查上下边界
    i = 0;
    while (i < width)
    {
        if (map[0][i] != '1' || map[height - 1][i] != '1')
            return (0);  // 边界不是墙，返回0
        i++;
    }
    
    // 检查左右边界
    i = 0;
    while (i < height)
    {
        if (map[i][0] != '1' || map[i][width - 1] != '1')
            return (0);  // 边界不是墙，返回0
        i++;
    }
    return (1);  // 所有边界都是墙，返回1
}

void ft_find_player(char **map, int width, int height, int *player_x, int *player_y)
{
    int i = 0;
    int j = 0;
    
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'P')
            {
                *player_x = j;  // x是列
                *player_y = i;  // y是行
                return;
            }
            j++;
        }
        i++;
    }
    
}

int **ft_create_visited(int width, int height)
{
    int **visited;
    int i = 0;
    
    visited = (int **)ft_calloc(height, sizeof(int *));
    if (!visited)
        return (NULL);
        
    while (i < height)
    {
        visited[i] = (int *)ft_calloc(width, sizeof(int));
        if (!visited[i])
        {
            // 如果分配失败，释放已分配的内存
            // 这里需要释放之前分配的行
            return (NULL);
        }
        i++;
    }
    return (visited);
}

void ft_free_visited(int **visited, int height)
{
    int i = 0;
    
    if (!visited)
        return;
        
    while (i < height)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}



// 洪水填充递归函数
void ft_flood_fill(char **map, int **visited, int x, int y, int width, int height)
{
    // 边界检查：超出地图范围
    if (x < 0 || x >= width || y < 0 || y >= height)
        return;
    
    // 如果已经访问过
    if (visited[y][x] == 1)
        return;
        
    // 如果是墙壁，不能通过
    if (map[y][x] == '1')
        return;
    
    // 标记为已访问
    visited[y][x] = 1;
    
    // 递归访问四个方向
    ft_flood_fill(map, visited, x + 1, y, width, height);  // 右
    ft_flood_fill(map, visited, x - 1, y, width, height);  // 左
    ft_flood_fill(map, visited, x, y + 1, width, height);  // 下
    ft_flood_fill(map, visited, x, y - 1, width, height);  // 上
}


// 检查所有收集品和出口是否可达
int ft_check_reachable(char **map, int **visited, int width, int height)
{
    int i = 0;
    int j = 0;
    
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            // 如果是C或E，但没有被访问到
            if ((map[i][j] == 'C' || map[i][j] == 'E') && visited[i][j] != 1)
            {
                printf("无法到达的位置: (%d, %d) = '%c'\n", j, i, map[i][j]);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int ft_isvalid_pass(char **map, int width, int height)
{
    int **visited;
    int player_x, player_y;
    int result;
    
    // 创建visited数组
    visited = ft_create_visited(width, height);
    if (!visited)
        return (0);
    
    // 找到玩家位置
    ft_find_player(map, width, height, &player_x, &player_y);
    printf("玩家位置: (%d, %d)\n", player_x, player_y);
    
    // 从玩家位置开始洪水填充
    ft_flood_fill(map, visited, player_x, player_y, width, height);
    
    // 检查所有C和E是否可达
    result = ft_check_reachable(map, visited, width, height);
    
    // 释放内存
    ft_free_visited(visited, height);
    
    if (result)
        printf("所有位置都可达！\n");
    else
        printf("有位置无法到达！\n");
    
    return (result);
}






























// 统一验证函数
int ft_isvalid(char **map, int width, int height)
{
    printf("=== 开始地图验证 ===\n");
    
    // 检查字符有效性
    int i = 0, j = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (!ft_isvalid_char(map[i][j]))
            {
                printf("错误：发现无效字符 '%c'\n", map[i][j]);
                return (0);
            }
            j++;
        }
        i++;
    }

    // 检查矩形
    if (!ft_isvalid_rec(map, width, height))
    {
        printf("错误：不是矩形\n");
        return (0);
    }
    
    // 检查墙壁
    if (!ft_isvalid_wall(map, width, height))
    {
        printf("错误：边界不是墙壁\n");
        return (0);
    }
    
    // 检查组件（1个E，1个P，至少1个C）
    if (!ft_isvalid_3comp(map, width, height))
    {
        printf("错误：地图组件不正确\n");
        return (0);
    }
    
    // 检查路径
    if (!ft_isvalid_pass(map, width, height))
    {
        printf("错误：路径验证失败\n");
        return (0);
    }
    
    printf("=== 地图验证成功 ===\n");
    return (1);
}



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

