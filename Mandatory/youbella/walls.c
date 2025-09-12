/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:32:07 by youbella          #+#    #+#             */
/*   Updated: 2025/09/12 14:10:39 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	put_pixels(mlx_texture_t *texture,
						t_data *data, int start, int index)
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
	mlx_put_pixel(data->game->img, data->walls->columns, start, color);
}

static void	get_pixels(mlx_texture_t *texture,
					int l_height, t_data *data, int start)
{
	int	d;
	int	index;
	int	tex_y;

	if ((data->walls->side == 0 && data->walls->ray_dir_x > 0)
		|| (data->walls->side == 1 && data->walls->ray_dir_y < 0))
		data->walls->tex_x = texture->width - data->walls->tex_x - 1;
	while (start < data->walls->draw_end)
	{
		d = (start * 256 - HEIGHT * 128 + l_height * 128);
		tex_y = ((d * texture->height) / l_height) / 256;
		index = (tex_y * texture->width + data->walls->tex_x) * 4;
		put_pixels(texture, data, start, index);
		start++;
	}
}

static mlx_texture_t	*ft_texture(t_walls *walls)
{
	if (walls->side == 0)
	{
		if (walls->step_x == -1)
			return (walls->ea_img);
		else
			return (walls->we_img);
	}
	if (walls->step_y == -1)
		return (walls->no_img);
	return (walls->so_img);
}

static void	prep_value(t_data *data, t_walls *walls)
{
	if (walls->side == 0 && walls->ray_dir_x != 0)
		walls->perp_w_dist = (walls->map_x - data->pos_x
				+ (1 - walls->step_x) / 2) / walls->ray_dir_x;
	else if (walls->side == 1 && walls->ray_dir_y != 0)
		walls->perp_w_dist = (walls->map_y - data->pos_y
				+ (1 - walls->step_y) / 2) / walls->ray_dir_y;
}

void	draw_wall_door(t_data *data, t_walls *walls)
{
	mlx_texture_t	*texture;
	float			draw_start;
	int				l_height;
	int				start;

	walls->perp_w_dist = 0;
	texture = ft_texture(walls);
	prep_value(data, walls);
	l_height = (int)(HEIGHT / walls->perp_w_dist);
	draw_start = -l_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	walls->draw_end = (l_height / 2) + (HEIGHT / 2);
	if (walls->draw_end >= HEIGHT)
		walls->draw_end = HEIGHT - 1;
	start = draw_start;
	if (walls->side == 0)
		walls->wall_x = data->pos_y + walls->perp_w_dist * walls->ray_dir_y;
	else
		walls->wall_x = data->pos_x + walls->perp_w_dist * walls->ray_dir_x;
	walls->wall_x -= floor(walls->wall_x);
	walls->tex_x = (int)(walls->wall_x * (float)texture->width);
	get_pixels(texture, l_height, data, start);
}
