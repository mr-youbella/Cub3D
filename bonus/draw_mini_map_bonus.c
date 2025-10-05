/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 03:18:52 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/05 18:18:33 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_square(mlx_image_t *img, int x, int y, size_t color)
{
	int		i;
	int		j;
	float	size;

	i = 0;
	size = 7.5;
	if (color == 0x800000FF || color == 0xF5DEB3FF || color == 0x3e3e42FF)
		size = 4;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_out_of_map(t_data *data)
{
	int	demi_rayon;
	int	y;
	int	x;

	demi_rayon = 100;
	y = -demi_rayon;
	while (y < demi_rayon)
	{
		x = -demi_rayon;
		while (x < demi_rayon)
		{
			if ((x * x) + (y * y) <= demi_rayon * demi_rayon)
				mlx_put_pixel(data->game->img, demi_rayon + x,
					demi_rayon + y, 0x800000FF);
			x++;
		}
		y++;
	}
}

static void	draw_border(t_data *data, int demi_rayon)
{
	float	rad;
	int		angle;
	int		center_x;
	int		center_y;

	center_x = demi_rayon;
	center_y = demi_rayon;
	angle = 0;
	while (angle < 360)
	{
		rad = angle * M_PI / 180.0;
		data->donneee->draw_x = center_x + demi_rayon * cos(rad);
		data->donneee->draw_y = center_y + demi_rayon * sin(rad);
		draw_square(data->game->img, data->donneee->draw_x,
			data->donneee->draw_y, 0x3e3e42FF);
		angle++;
	}
}

static void	draw_walls_doors_vide(t_data *data, int demi_rayon, int x, int y)
{
	int		center_x;
	int		center_y;
	float	res_x;
	float	res_y;
	float	dist;

	center_x = demi_rayon;
	center_y = demi_rayon;
	res_x = (x + 0.5) - data->pos_x;
	res_y = (y + 0.5) - data->pos_y;
	dist = sqrt(res_x * res_x + res_y * res_y);
	if (dist * 8 < demi_rayon)
	{
		data->donneee->draw_x = center_x + (res_x * 7.5);
		data->donneee->draw_y = center_y + (res_y * 7.5);
		if (data->map_data->map[y][x] == '1')
			draw_square(data->game->img, data->donneee->draw_x,
				data->donneee->draw_y, 0xD42525FF);
		else if (data->map_data->map[y][x] == 'D')
			draw_square(data->game->img, data->donneee->draw_x,
				data->donneee->draw_y, 0x000000FF);
		else
			draw_square(data->game->img, data->donneee->draw_x,
				data->donneee->draw_y, 0x696969FF);
	}
}

void	draw_map(t_data *data)
{
	int	demi_rayon;
	int	center_x;
	int	center_y;
	int	y;
	int	x;

	demi_rayon = 100;
	center_x = demi_rayon;
	center_y = demi_rayon;
	y = 0;
	draw_out_of_map(data);
	draw_border(data, demi_rayon);
	while (data->map_data->map[y])
	{
		x = 0;
		while (data->map_data->map[y][x])
		{
			draw_walls_doors_vide(data, demi_rayon, x, y);
			x++;
		}
		y++;
	}
	draw_square(data->game->img, center_x, center_y, 0xF5DEB3FF);
}
