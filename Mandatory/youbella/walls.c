/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:32:07 by youbella          #+#    #+#             */
/*   Updated: 2025/09/09 20:54:50 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixels(float draw_end, mlx_texture_t *texture, int l_height, int tex_x, t_data *data, int start);

void	image_wall(t_data *data, t_walls *walls)
{
	mlx_texture_t	*texture;
	float			perp_w_dist;
	float			draw_start;
	float			draw_end;
	float			wall_x;
	int				l_height;
	int				start;
	int				tex_x;

	perp_w_dist = 0;
	texture = ft_texture(walls);
	if (walls->side == 0 && walls->ray_dir_x != 0)
		perp_w_dist = (walls->map_x - data->pos_x
				+ (1 - walls->step_x) / 2) / walls->ray_dir_x;
	else if (walls->side == 1 && walls->ray_dir_y != 0)
		perp_w_dist = (walls->map_y - data->pos_y
				+ (1 - walls->step_y) / 2) / walls->ray_dir_y;
	l_height = (int)(HEIGHT / perp_w_dist);
	draw_start = -l_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (l_height / 2) + (HEIGHT / 2);
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	start = draw_start;
	if (walls->side == 0)
		wall_x = data->pos_y + perp_w_dist * walls->ray_dir_y;
	else
		wall_x = data->pos_x + perp_w_dist * walls->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)texture->width);
	put_pixels(draw_end, texture, l_height, tex_x, data, start);
}

void	put_pixels(float draw_end, mlx_texture_t *texture, int l_height, int tex_x, t_data *data, int start)
{
	int				d;
	size_t			r;
	size_t			g;
	size_t			b;
	size_t			a;
	int				index;
	size_t			color;
	int				tex_y;

	if ((data->walls->side == 0 && data->walls->ray_dir_x > 0)
		|| (data->walls->side == 1 && data->walls->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	while (start < draw_end)
	{
		d = (start * 256 - HEIGHT * 128 + l_height * 128);
		tex_y = ((d * texture->height) / l_height) / 256;
		index = (tex_y * texture->width + tex_x) * 4;
		r = texture->pixels[index + 0];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		color = (r << 24) | (g << 16) | (b << 8) | a;
		mlx_put_pixel(data->game->img, data->walls->columns, start, color);
		start++;
	}
}

mlx_texture_t	*ft_texture(t_walls *walls)
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
