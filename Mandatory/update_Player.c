/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_Player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:09:15 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/02 00:05:27 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_floor_sky(t_data *data)
{
	int	y;

	data->walls->columns = 0;
	while (data->walls->columns < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
			mlx_put_pixel(data->game->img, data->walls->columns,
				y++, data->map_data->c_color);
		while (y < HEIGHT - 1)
			mlx_put_pixel(data->game->img, data->walls->columns,
				y++, data->map_data->f_color);
		data->walls->columns++;
	}
}

static void	start_dda_and_dir_step_of_ray(t_data *data)
{
	if (data->walls->ray_dir_x < 0)
	{
		data->walls->step_x = -1;
		data->donne->side_dist_x = (data->pos_x - data->walls->map_x)
			* data->donne->delta_dist_x;
	}
	else
	{
		data->walls->step_x = 1;
		data->donne->side_dist_x = (data->walls->map_x + 1 - data->pos_x)
			* data->donne->delta_dist_x;
	}
	if (data->walls->ray_dir_y < 0)
	{
		data->walls->step_y = -1;
		data->donne->side_dist_y = (data->pos_y - data->walls->map_y)
			* data->donne->delta_dist_y;
	}
	else
	{
		data->walls->step_y = 1;
		data->donne->side_dist_y = (data->walls->map_y + 1 - data->pos_y)
			* data->donne->delta_dist_y;
	}
}

static void	dda(t_data *data)
{
	while (data->donne->wall == 48)
	{
		if (data->donne->side_dist_x < data->donne->side_dist_y)
		{
			data->donne->side_dist_x += data->donne->delta_dist_x;
			data->walls->map_x += data->walls->step_x;
			data->walls->side = 0;
		}
		else
		{
			data->donne->side_dist_y += data->donne->delta_dist_y;
			data->walls->map_y += data->walls->step_y;
			data->walls->side = 1;
		}
		if (data->map_data->map[data->walls->map_y][data->walls->map_x] == '1')
			data->donne->wall = 49;
	}
}

void	update(t_data *data)
{
	float	camera_x;

	draw_floor_sky(data);
	data->walls->columns = 0;
	while (data->walls->columns < WIDTH)
	{
		data->walls->map_x = (int)data->pos_x;
		data->walls->map_y = (int)data->pos_y;
		data->walls->side = -1;
		data->donne->wall = 48;
		camera_x = 2 * ((double)data->walls->columns / WIDTH) - 1;
		data->walls->ray_dir_x = data->dir_x + (data->plane_x * camera_x);
		data->walls->ray_dir_y = data->dir_y + (data->plane_y * camera_x);
		if (data->walls->ray_dir_x)
			data->donne->delta_dist_x = fabs(1 / data->walls->ray_dir_x);
		if (data->walls->ray_dir_y)
			data->donne->delta_dist_y = fabs(1 / data->walls->ray_dir_y);
		start_dda_and_dir_step_of_ray(data);
		dda(data);
		draw_wall_door(data, data->walls);
		data->walls->columns++;
	}
}
