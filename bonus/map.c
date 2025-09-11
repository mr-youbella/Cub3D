/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 03:18:52 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/11 07:17:33 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	for (int angle = 0; angle < 360; angle++)
	{
		float rad = angle * M_PI / 180.0;
		draw_x = center_x + demi_rayon * cos(rad);
		draw_y = center_y + demi_rayon * sin(rad);
		mlx_put_pixel(data->game->img, draw_x, draw_y, 0xFFFFFFFF);
	}
	while (data->map_data->map[y])
	{
		x = 0;
		while (data->map_data->map[y][x])
		{
			res_x = x - data->pos_x;
			res_y = y - data->pos_y;

			dist = sqrt(res_x * res_x + res_y * res_y);
			if (dist * scale_box < demi_rayon)
			{
				draw_x = center_x + (res_x * scale_box);
				draw_y = center_y + (res_y * scale_box);
				// int wallHeight = (int)(HEIGHT / distanceWall);
				if (data->map_data->map[y][x] == '1')
					mlx_put_pixel(data->game->img, draw_x, draw_y, 0xD42525FF);
				else if (data->map_data->map[y][x] == 'D')
					mlx_put_pixel(data->game->img, draw_x, draw_y, 0x0000FFFF);
				else
					mlx_put_pixel(data->game->img, draw_x, draw_y, 0x000000FF);
			}
			x++;
		}
		y++;
	}
	mlx_put_pixel(data->game->img, center_x, center_y, 0x00FF00FF);
}
