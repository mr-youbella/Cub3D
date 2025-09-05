#ifndef CUB3D_H
# define CUB3D_H

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

#include <math.h>
#include <libc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MLX42.h"

typedef struct s_game
{
	void	*window;
	mlx_t	*init;
	int		map_x;
	int		map_y;
	int		a;
	int		w;
	int		d;
	int		s;
	int		x;
	int		y;
	mlx_image_t *img;
}	t_game;


typedef struct s_player_map
{
	char	**map;
	float	pos_x;
	float	pos_y;
	float	plane_x;
	float	plane_y;
	float	dir_x;
	float	dir_y;
	t_game *game;
}	t_player_map;


void	player_position(t_player_map *player);
void	update(t_game *game, t_player_map *player);
void	check_key_moves(void *param);
void	check_fleche_key(void *arg);
void	destroy(void *arg);
void	close_window(void *arg);

#endif