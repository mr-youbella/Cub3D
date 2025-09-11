/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 03:18:52 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/11 10:36:39 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void draw_square(mlx_image_t *img, int x, int y, float size, size_t color)
{
	int i = 0;
	int j;
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

void draw_map(t_data *data)
{
	int demi_rayon = 100;
	int center_x = demi_rayon;
	int center_y = demi_rayon;
	float scale_box = 8;
	int y = 0;
	int x = 0;
	float res_x;
	float res_y;
	float dist;
	int draw_x;
	int draw_y;
	int angle = 0;
	y = -demi_rayon;
	while (y < demi_rayon)
	{
		x = -demi_rayon;
		while (x < demi_rayon)
		{
			if ((x * x) + (y * y) <= demi_rayon * demi_rayon)
				mlx_put_pixel(data->game->img, demi_rayon + x, demi_rayon + y, 0x800000FF);
			x++;
		}
		y++;
	}
	y = 0;
	while (angle < 360)
	{
		float rad = angle * M_PI / 180.0;
		draw_x = center_x + demi_rayon * cos(rad);
		draw_y = center_y + demi_rayon * sin(rad);
		draw_square(data->game->img, draw_x, draw_y, 4, 0x696969);
		angle++;
	}
	while (data->map_data->map[y])
	{
		x = 0;
		while (data->map_data->map[y][x])
		{
			res_x = x - (int)data->pos_x;
			res_y = y - (int)data->pos_y;
			dist = sqrt(res_x * res_x + res_y * res_y);
			if (dist * scale_box < demi_rayon)
			{
				draw_x = center_x + (res_x * 7.5);
				draw_y = center_y + (res_y * 7.5);
				if (data->map_data->map[y][x] == '1')
					draw_square(data->game->img, draw_x, draw_y, 7.5, 0xD42525FF);
				else if (data->map_data->map[y][x] == 'D')
					draw_square(data->game->img, draw_x, draw_y, 7.5, 0x000000FF);
				else
					draw_square(data->game->img, draw_x, draw_y, 7.5, 0x696969FF);
			}
			x++;
		}
		y++;
	}
	draw_square(data->game->img, center_x, center_y, 4, 0xF5DEB3FF);
}
