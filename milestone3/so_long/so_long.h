#ifndef SO_LONG_H
# define SO_LONG_H

/* ========== INCLUDES ========== */
# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free, exit
# include <unistd.h>    // write, read
# include <fcntl.h>     // open, close
# include "libft/libft.h"

/* ========== FUNCTION PROTOTYPES ========== */
// Map parsing functions
int		open_map_file(char *filename);
int		read_map_content(int fd, char *buffer, int max_size);
void	get_map_dimensions(char *buffer, int size, int *width, int *height);
char	**allocate_map_array(int width, int height);
void	fill_map_from_buffer(char **map, char *buffer, int size);
char	**parse_map_file(char *filename, int *width, int *height);
int ft_isvalid(char **map, int width, int height);

// Utility functions  
void	free_map_array(char **map, int allocated_rows);

/* ========== DEFINES ========== */
# define TILE_SIZE 32   // 各タイルのピクセルサイズ

/* ========== MAP CHARACTERS ========== */
# define EMPTY '0'      // 空きスペース
# define WALL '1'       // 壁
# define COLLECTIBLE 'C' // コレクタブル
# define EXIT 'E'       // 出口
# define PLAYER 'P'     // プレイヤー開始位置

/* ========== STRUCTURES ========== */
// まず最小構成から始める
typedef struct s_map
{
	char	**grid;     // マップの2次元配列
	int		width;      // マップの幅
	int		height;     // マップの高さ
	int		collectibles; // コレクタブルの数
	int		player_x;   // プレイヤーのX座標
	int		player_y;   // プレイヤーのY座標
}	t_map;

typedef struct s_game
{
	t_map	map;        // マップデータ
	int		moves;      // 移動回数
}	t_game;

/* ========== FUNCTION PROTOTYPES ========== */
// 今はまだ空でOK、後で関数を作ったら追加していく

#endif