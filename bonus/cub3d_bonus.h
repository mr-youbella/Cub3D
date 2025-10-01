/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:54:51 by youbella          #+#    #+#             */
/*   Updated: 2025/10/02 00:27:36 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <math.h>
# include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../.MLX42.h"

# define WIDTH 1024
# define HEIGHT 640

typedef struct s_game
{
	mlx_t		*init;
	int			map_x;
	int			map_y;
	int			pos_mouse_x;
	int			pos_mouse_y;
	int			ex_pos_mouse_x;
	short		flag_key_m;
	mlx_image_t	*img;
	size_t		color;
}	t_game;

typedef struct s_donnee
{
	float		new_pos_x;
	float		new_pos_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			draw_x;
	int			draw_y;
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
	char	*str_f_color;
	char	*str_c_color;
	size_t	f_color;
	size_t	c_color;
}	t_map_data;

typedef struct s_walls
{
	short			side;
	short			step_x;
	short			step_y;
	short			map_x;
	short			map_y;
	int				columns;
	int				start;
	int				l_height;
	float			ray_dir_x;
	float			ray_dir_y;
	float			draw_end;
	float			perp_w_dist;
	mlx_texture_t	*no_img;
	mlx_texture_t	*so_img;
	mlx_texture_t	*we_img;
	mlx_texture_t	*ea_img;
}	t_walls;

typedef struct s_dragons
{
	mlx_texture_t	*dragon1;
	mlx_texture_t	*dragon2;
	mlx_texture_t	*dragon3;
	mlx_texture_t	*hand_knife;
	mlx_texture_t	*hand;
	int				height_dragon;
	short			key_knife;
	int				current_frame;
	int				frame_counter;
	int				frame_speed;
	int				x;
	int				y;
}	t_dragons;

typedef struct s_door
{
	float			pos_y;
	float			pos_x;
	short			is_open;
	mlx_texture_t	*door;
}	t_door;

typedef struct s_knife
{
	mlx_texture_t	*hand_knife;
	mlx_texture_t	*hand;
	mlx_texture_t	*knife_hand;
	short			key_knife;
	int				draw_x;
	int				draw_y;
	int				x;
	int				y;
}	t_knife;

typedef struct s_data
{
	float		pos_x;
	float		pos_y;
	float		plane_x;
	float		plane_y;
	float		dir_x;
	float		dir_y;
	int			wall;
	t_game		*game;
	t_walls		*walls;
	t_donnee	*donnee;
	t_map_data	*map_data;
	t_door		*door;
	t_dragons	*dragons;
	t_knife		*knife;
}	t_data;

t_data		*alloc_struct(t_door *door, t_dragons *dragons, t_knife *knife);
void		free_leaks(t_data *data, bool is_mlx);

// WKANNOUF
void		update(t_data *data, float camera_x);
void		check_key_moves(void *param);
void		rotate_key(void *arg);
void		destroy(void *arg);
void		close_window(void *arg);
void		rotate_mouse(void *arg);
void		draw_map(t_data *data);
short		is_blocked(t_data *data, float x, float y);
void		draw_floor_sky(t_data *data);

// YOUBELLA
void		player_position(t_data *player);
t_map_data	*ft_map_data(char *path);
char		*get_next_line(int fd);
void		draw_wall_door(t_game *game, t_data *player,
				t_walls *walls, short is_door);
void		draw_dragons(t_game *game, t_dragons *dragons, t_knife *knife);
void		key_door(t_data *data);
void		key_knife(mouse_key_t button, action_t action,
				modifier_key_t mods, void *arg);
void		draw_hand_knife(t_game *game, t_knife *knife);
void		draw_wall_door(t_game *game, t_data *data,
				t_walls *walls, short is_door);
void		move_dragon(t_data *data);
bool		get_hexa_colors(t_map_data *map_data);
bool		get_identifiers(int fd, char **line, t_map_data *map_data);
bool		identifiers(t_map_data *map_data,
				char **line, char *identifier, size_t i);
bool		is_valid_map(char **map, size_t i, size_t j);
bool		check_map(t_map_data *map_data);
bool		identifiers_colors(t_map_data *map_data,
				char **line, char *identifier, size_t i);
bool		is_empty(char *line);
void		draw_map_terminal(char **map, int pos_y, int pos_x, int j);

#endif
