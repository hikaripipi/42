#ifndef SO_LONG_H
# define SO_LONG_H

/* ========== INCLUDES ========== */
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "printf/ft_printf.h"
# include <fcntl.h>  // open, close
# include <stdio.h>  // printf
# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // write, read

/* ========== FUNCTION PROTOTYPES ========== */

// map_file_io.c - 文件I/O操作
int		open_map_file(char *filename);
int		read_map_content(int fd, char *buffer, int max_size);
void	get_map_dimensions(char *buffer, int size, int *width, int *height);
char	**allocate_map_array(int width, int height);
void	fill_map_from_buffer(char **map, char *buffer, int size);

// map_validation.c - 地图基础验证
int		ft_isvalid_char(char c);
int		ft_isvalid_3comp(char **map, int width, int height);
int		ft_isvalid_rec(char **map, int width, int height);
int		ft_isvalid_wall(char **map, int width, int height);
int		ft_isvalid(char **map, int width, int height);

// map_pathfinding.c - 路径查找和验证
void	ft_find_player(char **map, int width, int height, int *player_x,
			int *player_y);
int		**ft_create_visited(int width, int height);
void	ft_free_visited(int **visited, int height);
void	ft_flood_fill(char **map, int **visited, int x, int y, int width,
			int height);
int		ft_check_reachable(char **map, int **visited, int width, int height);

// map_parser.c - 主要解析和验证函数
char	**parse_map_file(char *filename, int *width, int *height);
int		ft_isvalid_pass(char **map, int width, int height);
int		ft_validate_complete_map(char **map, int width, int height);

// map_utils.c - 工具函数
void	free_map_array(char **map, int allocated_rows);

// utils.c - 辅助函数
int		ft_check_all_chars(char **map, int width, int height);
void	ft_count_components(char **map, int width, int height, int *counts);

/* ========== DEFINES ========== */
# define TILE_SIZE 32 // 各タイルのピクセルサイズ

/* ========== MAP CHARACTERS ========== */
# define EMPTY '0' // 空きスペース
# define WALL '1' // 壁
# define COLLECTIBLE 'C' // コレクタブル
# define EXIT 'E' // 出口
# define PLAYER 'P' // プレイヤー開始位置

/* ========== STRUCTURES ========== */
// まず最小構成から始める
typedef struct s_map
{
	char **grid;      // マップの2次元配列
	int width;        // マップの幅
	int height;       // マップの高さ
	int collectibles; // コレクタブルの数
	int player_x;     // プレイヤーのX座標
	int player_y;     // プレイヤーのY座標
}		t_map;

typedef struct s_game
{
	void *mlx; // MLXポインタ
	void *win; // ウィンドウポインタ
	t_map map; // マップデータ
	int moves; // 移動回数
}		t_game;

/* ========== FUNCTION PROTOTYPES ========== */
// 今はまだ空でOK、後で関数を作ったら追加していく

#endif