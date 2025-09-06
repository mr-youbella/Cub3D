#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 1080
#define HEIGHT 610
#include <math.h>
#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "MLX42.h"

typedef struct	s_walls
{
	short			side;
	short			step_x;
	short			step_y;
	short			map_x;
	short			map_y;
	int				columns;
	float			ray_dir_x;
	float			ray_dir_y;
	mlx_texture_t	*no_img;
	mlx_texture_t	*so_img;
	mlx_texture_t	*we_img;
	mlx_texture_t	*ea_img;
} t_walls;

typedef struct s_game
{
	void *window;
	mlx_t *init;
	int map_x;
	int map_y;
	int a;
	int w;
	int d;
	int s;
	int x;
	int y;
	mlx_image_t *img;
} t_game;

typedef struct s_player_map
{
	char	**map;
	float	pos_x;
	float	pos_y;
	float	plane_x;
	float	plane_y;
	float	dir_x;
	float	dir_y;
	t_game	*game;
	t_walls	*walls;
} t_player_map;

void	update(t_game *game, t_player_map *player);
void	check_key_moves(void *param);
void	check_fleche_key(void *arg);
void	destroy(void *arg);
void	close_window(void *arg);

// YOUBELLA
void	player_position(t_player_map *player);
char	**get_map(char *path);
char	*get_next_line(int fd);
void	image_wall(t_game *game, t_player_map *player, t_walls *walls);

#endif