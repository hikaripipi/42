/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:01:07 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/24 00:24:56 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
