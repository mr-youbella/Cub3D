/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_mouse_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:30:33 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/10 22:45:35 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void rotate_mouse(void *arg)
{
	float old_dir_x;
	float old_plane_x;
	float delta_x;

	t_data *data = (t_data *)arg;
	if (data->game->flag_key_m || mlx_is_key_down(data->game->init, MLX_KEY_M))
	{
		data->game->flag_key_m = 1;
		mlx_get_mouse_pos(data->game->init, &data->game->pos_mouse_x, &data->game->pos_mouse_y);
		delta_x = data->game->pos_mouse_x - data->game->ex_pos_mouse_x;
		data->game->ex_pos_mouse_x = data->game->pos_mouse_x;
		if (delta_x > 0)
		{
			old_dir_x = data->dir_x;
			data->dir_x = data->dir_x * cos(0.1) - data->dir_y * sin(0.1);
			data->dir_y = old_dir_x * sin(0.1) + data->dir_y * cos(0.1);

			old_plane_x = data->plane_x;
			data->plane_x = data->plane_x * cos(0.1) - data->plane_y * sin(0.1);
			data->plane_y = old_plane_x * sin(0.1) + data->plane_y * cos(0.1);
		}
		else if (delta_x < 0)
		{
			old_dir_x = data->dir_x;
			data->dir_x = data->dir_x * cos(-0.1) - data->dir_y * sin(-0.1);
			data->dir_y = old_dir_x * sin(-0.1) + data->dir_y * cos(-0.1);

			old_plane_x = data->plane_x;
			data->plane_x = data->plane_x * cos(-0.1) - data->plane_y * sin(-0.1);
			data->plane_y = old_plane_x * sin(-0.1) + data->plane_y * cos(-0.1);
		}
		update(data->game, data);
	}
}
