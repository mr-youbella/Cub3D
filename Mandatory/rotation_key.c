/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:05:13 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/11 12:02:28 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_fleche_key(void *arg)
{
	t_data	*data;
	float	old_dir_x;
	float	old_plane_x;

	data = (t_data *)arg;
	if (mlx_is_key_down(data->game->init, MLX_KEY_RIGHT))
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(0.05) - data->dir_y * sin(0.05);
		data->dir_y = old_dir_x * sin (0.05) + data->dir_y * cos(0.05);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(0.05) - data->plane_y * sin(0.05);
		data->plane_y = old_plane_x * sin(0.05) + data->plane_y * cos(0.05);
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_LEFT))
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-0.05) - data->dir_y * sin(-0.05);
		data->dir_y = old_dir_x * sin (-0.05) + data->dir_y * cos(-0.05);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-0.05) - data->plane_y * sin(-0.05);
		data->plane_y = old_plane_x * sin(-0.05) + data->plane_y * cos(-0.05);
	}
	update(data);
}
