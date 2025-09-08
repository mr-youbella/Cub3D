#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 1024
#define HEIGHT 640
#include <math.h>
#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "MLX42.h"

typedef struct s_game
{
	void *window;
	mlx_t *init;
	int map_x;
	int map_y;
	mlx_image_t *img;
} t_game;

// YOUBELLA
typedef struct	s_map_data
{
	char	**map;
	char	*no_img;
	char	*so_img;
	char	*we_img;
	char	*ea_img;
	size_t 	f_color;
	size_t 	c_color;
}	t_map_data;


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


typedef struct s_data
{
	float		pos_x;
	float		pos_y;
	float		plane_x;
	float		plane_y;
	float		dir_x;
	float		dir_y;
	t_game		*game;
	t_walls		*walls;
	t_map_data	*map_data;
} t_data;

// WKANNOUF
void	update(t_game *game, t_data *player);
void	check_key_moves(void *param);
void	check_fleche_key(void *arg);
void	destroy(void *arg);
void	close_window(void *arg);

// YOUBELLA
void		player_position(t_data *player);
t_map_data	*ft_map_data(char *path);
char		*get_next_line(int fd);
void		image_wall(t_game *game, t_data *player, t_walls *walls);

#endif