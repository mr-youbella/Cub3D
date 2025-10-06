/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_door_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:35 by youbella          #+#    #+#             */
/*   Updated: 2025/10/06 16:11:23 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	key_knife(mouse_key_t button, action_t action,
					modifier_key_t mods, void *arg)
{
	t_data	*data;

	(void)mods;
	data = (t_data *)arg;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		data->knife->key_knife = !data->knife->key_knife;
}

static void	close_door(t_data *data)
{
	float	x;
	float	y;

	if (data->door->is_open)
	{
		x = data->pos_x - data->door->pos_x;
		y = data->pos_y - data->door->pos_y;
		if (x * x + y * y > 4)
		{
			data->map_data->map[(int)data->door->pos_y][(int)data->door->pos_x]
				= 'D';
			data->door->is_open = 0;
		}
	}
}

static void	check_x_door(t_data *data)
{
	if (data->map_data->map[(int)(data->pos_y)][(int)(data->pos_x - 1)] == 'D')
	{
		data->map_data->map[(int)(data->pos_y)][(int)(data->pos_x - 1)] = 'O';
		data->door->pos_y = data->pos_y;
		data->door->pos_x = data->pos_x - 1;
	}
	else if (data->map_data->map[(int)(data->pos_y)]
				[(int)(data->pos_x + 1)] == 'D')
	{
		data->map_data->map[(int)(data->pos_y)][(int)(data->pos_x + 1)] = 'O';
		data->door->pos_y = data->pos_y;
		data->door->pos_x = data->pos_x + 1;
	}
}

void	key_door(t_data *data)
{
	if (mlx_is_key_down(data->game->init, MLX_KEY_O) && !data->door->is_open)
	{
		if (data->map_data->map[(int)(data->pos_y - 1)]
			[(int)(data->pos_x)] == 'D')
		{
			data->map_data->map[(int)(data->pos_y - 1)][(int)(data->pos_x)]
				= 'O';
			data->door->pos_y = data->pos_y - 1;
			data->door->pos_x = data->pos_x;
		}
		else if (data->map_data->map[(int)(data->pos_y + 1)]
					[(int)(data->pos_x)] == 'D')
		{
			data->map_data->map[(int)(data->pos_y + 1)][(int)(data->pos_x)]
				= 'O';
			data->door->pos_y = data->pos_y + 1;
			data->door->pos_x = data->pos_x;
		}
		check_x_door(data);
		data->door->is_open = 1;
	}
	close_door(data);
}
