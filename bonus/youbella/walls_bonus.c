/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:32:07 by youbella          #+#    #+#             */
/*   Updated: 2025/09/13 05:35:21 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_map_terminal(char **map, int pos_y, int pos_x, int j)
{
	int	i;

	1 && (printf("\033[H\033[J"), i = 0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'E')
				map[i][j] = '0';
			if (map[i][j] == '1')
				printf("\033[1;31m");
			if (map[i][j] == 'D')
				printf("\033[1;33m");
			if (map[i][j] == 'O')
				printf("\033[1;32m");
			if (i == pos_y && j == pos_x)
				printf("\033[1;34mP");
			else
				printf("%c", map[i][j]);
			1 && (printf("\033[0m"), j++);
		}
		1 && (printf("\n"), i++);
	}
}

static size_t	get_rgba_walls_door(mlx_texture_t *texture, int index)
{
	size_t	r;
	size_t	g;
	size_t	b;
	size_t	a;
	size_t	color;

	r = texture->pixels[index + 0];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	a = texture->pixels[index + 3];
	color = (r << 24) | (g << 16) | (b << 8) | a;
	return (color);
}

static void	put_pixels_walls_door(t_game *game, t_walls *walls,
									mlx_texture_t *texture, int tex_x)
{
	size_t	color;
	int		d;
	int		index;
	int		tex_y;

	while (walls->start < walls->draw_end)
	{
		d = (walls->start * 256 - HEIGHT * 128 + walls->l_height * 128);
		tex_y = ((d * texture->height) / walls->l_height) / 256;
		index = (tex_y * texture->width + tex_x) * 4;
		color = get_rgba_walls_door(texture, index);
		mlx_put_pixel(game->img, walls->columns, walls->start, color);
		walls->start++;
	}
}

static mlx_texture_t	*get_texture(t_data *data,
										t_walls *walls, short is_door)
{
	mlx_texture_t	*texture;

	if (is_door)
		texture = data->door->door;
	else if (walls->side == 0)
	{
		if (walls->step_x == -1)
			texture = walls->we_img;
		else
			texture = walls->ea_img;
	}
	else
	{
		if (walls->step_y == -1)
			texture = walls->no_img;
		else
			texture = walls->so_img;
	}
	return (texture);
}

void	draw_wall_door(t_game *game, t_data *data,
							t_walls *walls, short is_door)
{
	mlx_texture_t	*texture;
	float			wall_x;
	int				tex_x;

	texture = get_texture(data, walls, is_door);
	if (walls->side == 0)
		wall_x = data->pos_y + walls->perp_w_dist * walls->ray_dir_y;
	else
		wall_x = data->pos_x + walls->perp_w_dist * walls->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)texture->width);
	if ((walls->side == 0 && walls->ray_dir_x > 0)
		|| (walls->side == 1 && walls->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	put_pixels_walls_door(game, walls, texture, tex_x);
}
