/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/26 21:25:42 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 释放地图数组的内存
void free_map_array(char **map, int allocated_rows)
{
    int i;
    
    if (!map)
        return;
    
    i = 0;
    while (i < allocated_rows)
    {
        if (map[i])
            free(map[i]);
        i++;
    }
    free(map);
} 
