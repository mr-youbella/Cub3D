/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:15:13 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/06 16:02:59 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1024
# define HEIGHT 640
# include <math.h>
# include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../.MLX42.h"
# include "../AllocFreeCraft/allocfreecraft.h"

typedef struct s_game
{
	mlx_t		*init;
	int			map_x;
	int			map_y;
	mlx_image_t	*img;
}	t_game;

typedef struct s_donnee
{
	float		new_pos_x;
	float		new_pos_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			wall;
}	t_donnee;

// YOUBELLA
typedef struct s_map_data
{
	char	**map;
	char	*no_img;
	char	*so_img;
	char	*we_img;
	char	*ea_img;
	size_t	f_color;
	size_t	c_color;
	char	*str_f_color;
	char	*str_c_color;
}	t_map_data;

typedef struct s_walls
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
	float			perp_w_dist;
	float			draw_end;
	float			tex_x;
	int				l_height;
	float			draw_start;
}	t_walls;

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
	t_donnee	*donnee;
}	t_data;

// WKANNOUF
void		update(t_data *data);
void		draw_floor_sky(t_data *data);
void		check_key_moves(void *param);
void		check_fleche_key(void *arg);
void		destroy(void *arg);
void		close_window(void *arg);

// YOUBELLA
void		player_position(t_data *player);
char		*get_next_line(int fd);
void		draw_wall_door(t_data *data, t_walls *walls);
t_map_data	*ft_map_data(char *path);
bool		get_hexa_colors(t_map_data *map_data);
bool		get_identifiers(int fd, char **line, t_map_data *map_data);
bool		identifiers(t_map_data *map_data,
				char **line, char *identifier, size_t i);
bool		is_valid_map(char **map, size_t i, size_t j);
bool		check_map(t_map_data *map_data);
bool		identifiers_colors(t_map_data *map_data,
				char **line, char *identifier);
bool		is_empty(char *line);

#endif
