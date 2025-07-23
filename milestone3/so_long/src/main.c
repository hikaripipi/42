/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:45:09 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/24 00:22:02 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    // 引数チェック
    if (argc != 2)
    {
        printf("Error: Usage: %s <map.ber>\n", argv[0]);
        return (1);
    }

    printf("Map file: %s\n", argv[1]);
    
    // マップを解析
    game.map.grid = parse_map_file(argv[1], &game.map.width, &game.map.height);
    if (!game.map.grid)
    {
        printf("Error: Failed to parse map file\n");
        return (1);
    }
    
    // 成功メッセージ
    printf("Map loaded successfully!\n");
    printf("Map dimensions: %d x %d\n", game.map.width, game.map.height);
    
    // テスト用：マップを表示
    printf("Map content:\n");
    for (int i = 0; i < game.map.height; i++)
    {
        printf("%s\n", game.map.grid[i]);
    }
    
    // メモリを解放
    free_map_array(game.map.grid, game.map.height);
    
    return (0);
}
