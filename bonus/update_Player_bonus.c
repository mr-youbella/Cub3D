/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_Player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:02:45 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/13 05:25:06 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	start_dda_and_dir_step_of_ray(t_data *data)
{
	if (data->walls->ray_dir_x < 0)
	{
		data->walls->step_x = -1;
		data->donnee->side_dist_x = (data->pos_x - data->walls->map_x)
			* data->donnee->delta_dist_x;
	}
	else
	{
		data->walls->step_x = 1;
		data->donnee->side_dist_x = (data->walls->map_x + 1 - data->pos_x)
			* data->donnee->delta_dist_x;
	}
	if (data->walls->ray_dir_y < 0)
	{
		data->walls->step_y = -1;
		data->donnee->side_dist_y = (data->pos_y - data->walls->map_y)
			* data->donnee->delta_dist_y;
	}
	else
	{
		data->walls->step_y = 1;
		data->donnee->side_dist_y = (data->walls->map_y + 1 - data->pos_y)
			* data->donnee->delta_dist_y;
	}
}

static void	dda(t_data *data)
{
	while (data->donnee->wall == 48)
	{
		if (data->donnee->side_dist_x < data->donnee->side_dist_y)
		{
			data->donnee->side_dist_x += data->donnee->delta_dist_x;
			data->walls->map_x += data->walls->step_x;
			data->walls->side = 0;
		}
		else
		{
			data->donnee->side_dist_y += data->donnee->delta_dist_y;
			data->walls->map_y += data->walls->step_y;
			data->walls->side = 1;
		}
		if (data->map_data->map[data->walls->map_y][data->walls->map_x] == '1')
			data->donnee->wall = 49;
		else if (data->map_data->map[data->walls->map_y]
			[data->walls->map_x] == 'D')
			data->donnee->wall = 'D';
	}
}

static void	perp_wall_dist_line_height(t_data *data)
{
	if (data->walls->side == 0 && data->walls->ray_dir_x != 0)
		data->walls->perp_w_dist = (data->walls->map_x - data->pos_x
				+ (1 - data->walls->step_x) / 2) / data->walls->ray_dir_x;
	else if (data->walls->side == 1 && data->walls->ray_dir_y != 0)
		data->walls->perp_w_dist = (data->walls->map_y - data->pos_y
				+ (1 - data->walls->step_y) / 2) / data->walls->ray_dir_y;
	data->walls->l_height = (int)(HEIGHT / data->walls->perp_w_dist);
}

static void	drawing_columns(t_data *data)
{
	float	draw_start;

	draw_start = -data->walls->l_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	data->walls->draw_end = (data->walls->l_height / 2) + (HEIGHT / 2);
	if (data->walls->draw_end >= HEIGHT)
		data->walls->draw_end = HEIGHT - 1;
	data->walls->start = draw_start;
	if (data->donnee->wall == 49)
		draw_wall_door(data->game, data, data->walls, 0);
	else if (data->donnee->wall == 'D')
		draw_wall_door(data->game, data, data->walls, 1);
}

void	draw_map_terminal(char **map, int pos_y, int pos_x)
{
	int	i;
	int	j;

	printf("\033[H\033[J");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'E')
				map[i][j] = '0';
			printf("\033[1m");
			if (map[i][j] == '1')
				printf("\033[31m");
			if (map[i][j] == 'D')
				printf("\033[33m");
			if (map[i][j] == 'O')
				printf("\033[32m");
			if (i == pos_y && j == pos_x)
				printf("\033[34mP");
			else
				printf("%c", map[i][j]);
			printf("\033[0m");
			j++;
		}
		printf("\n");
		i++;
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
		data->donnee->wall = 48;
		camera_x = 2 * ((double)data->walls->columns / WIDTH) - 1;
		data->walls->ray_dir_x = data->dir_x + (data->plane_x * camera_x);
		data->walls->ray_dir_y = data->dir_y + (data->plane_y * camera_x);
		if (data->walls->ray_dir_x)
			data->donnee->delta_dist_x = fabs(1 / data->walls->ray_dir_x);
		if (data->walls->ray_dir_y)
			data->donnee->delta_dist_y = fabs(1 / data->walls->ray_dir_y);
		start_dda_and_dir_step_of_ray(data);
		dda(data);
		perp_wall_dist_line_height(data);
		drawing_columns(data);
		data->walls->columns++;
	}
	draw_dragons(data->game, data->dragons, data->knife);
	draw_map(data);
	draw_map_terminal(data->map_data->map, (int)data->pos_y, (int)data->pos_x);
}
