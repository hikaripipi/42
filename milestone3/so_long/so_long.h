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
int			open_map_file(char *filename);
int			read_map_content(int fd, char *buffer, int max_size);
void		get_map_dimensions(char *buffer, int size, int *width, int *height);
char		**allocate_map_array(int width, int height);
void		fill_map_from_buffer(char **map, char *buffer, int size);

// map_validation.c - 地图基础验证
int			ft_isvalid_char(char c);
int			ft_isvalid_3comp(char **map, int width, int height);
int			ft_isvalid_rec(char **map, int width, int height);
int			ft_isvalid_wall(char **map, int width, int height);
int			ft_isvalid(char **map, int width, int height);

// map_pathfinding.c - 路径查找和验证
void		ft_find_player(char **map, int width, int height, int *player_x,
				int *player_y);
int			**ft_create_visited(int width, int height);
void		ft_free_visited(int **visited, int height);
void		ft_flood_fill(char **map, int **visited, int x, int y, int width,
				int height);
int			ft_check_reachable(char **map, int **visited, int width,
				int height);

// map_parser.c - 主要解析和验证函数
char		**parse_map_file(char *filename, int *width, int *height);
int			ft_isvalid_pass(char **map, int width, int height);
int			ft_validate_complete_map(char **map, int width, int height);

// map_utils.c - 工具函数
void		free_map_array(char **map, int allocated_rows);

// utils.c - 辅助函数
int			ft_check_all_chars(char **map, int width, int height);
void		ft_count_components(char **map, int width, int height, int *counts);

/* ========== 定义 ========== */
# define TILE_SIZE 32 // 每个瓦片的像素大小
# define SPRITE_SIZE 16 // 精灵表中每个瓦片的大小

/* ========== 地图字符 ========== */
# define EMPTY '0' // 空地
# define WALL '1' // 墙壁
# define COLLECTIBLE 'C' // 收集品
# define EXIT 'E' // 出口
# define PLAYER 'P' // 玩家起始位置

/* ========== 结构体 ========== */
// 瓦片图像数据
typedef struct s_tiles
{
	void *background_img; // 新增：背景底色
	void	*wall_img;
	void	*empty_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
}			t_tiles;

// 地图结构体
typedef struct s_map
{
	char **grid;      // 地图的二维数组
	int width;        // 地图宽度
	int height;       // 地图高度
	int collectibles; // 收集品数量
	int player_x;     // 玩家X坐标
	int player_y;     // 玩家Y坐标
}			t_map;

typedef struct s_game
{
	void *mlx;     // MLX指针
	void *win;     // 窗口指针
	t_map map;     // 地图数据
	t_tiles tiles; // 瓦片图像数据
	int moves;     // 移动次数
}			t_game;

/* ========== 函数原型 ========== */
// game.c - 游戏相关功能
int			init_game_images(t_game *game);
void		render_game(t_game *game);
void		cleanup_game(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			close_game(t_game *game);
int			player_move_up(t_game *game);
int			player_move_down(t_game *game);
int			player_move_left(t_game *game);
int			player_move_right(t_game *game);

#endif