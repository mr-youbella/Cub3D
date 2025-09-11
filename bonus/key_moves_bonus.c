/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:01:25 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/11 14:20:39 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	key_w(t_data *data)
{
	data->donnee->new_pos_x = data->pos_x + (data->dir_x * 0.05);
	data->donnee->new_pos_y = data->pos_y + (data->dir_y * 0.05);
	if (!is_blocked(data, data->donnee->new_pos_x + 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x - 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y + 0.15)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y - 0.15))
		data->pos_x = data->donnee->new_pos_x;
	if (!is_blocked(data, data->pos_x, data->donnee->new_pos_y + 0.15)
		&& !is_blocked(data, data->pos_x, data->donnee->new_pos_y - 0.15)
		&& !is_blocked(data, data->pos_x + 0.15, data->donnee->new_pos_y)
		&& !is_blocked(data, data->pos_x - 0.15, data->donnee->new_pos_y))
		data->pos_y = data->donnee->new_pos_y;
}

static void	key_s(t_data *data)
{
	data->donnee->new_pos_x = data->pos_x - (data->dir_x * 0.05);
	data->donnee->new_pos_y = data->pos_y - (data->dir_y * 0.05);
	if (!is_blocked(data, data->donnee->new_pos_x + 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x - 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y + 0.15)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y - 0.15))
		data->pos_x = data->donnee->new_pos_x;
	if (!is_blocked(data, data->pos_x, data->donnee->new_pos_y + 0.15)
		&& !is_blocked(data, data->pos_x, data->donnee->new_pos_y - 0.15)
		&& !is_blocked(data, data->pos_x + 0.15, data->donnee->new_pos_y)
		&& !is_blocked(data, data->pos_x - 0.15, data->donnee->new_pos_y))
		data->pos_y = data->donnee->new_pos_y;
}

static void	key_a(t_data *data)
{
	data->donnee->new_pos_x = data->pos_x - (data->plane_x * 0.05);
	data->donnee->new_pos_y = data->pos_y - (data->plane_y * 0.05);
	if (!is_blocked(data, data->donnee->new_pos_x + 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x - 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y + 0.15)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y - 0.15))
		data->pos_x = data->donnee->new_pos_x;
	if (!is_blocked(data, data->pos_x, data->donnee->new_pos_y + 0.15)
		&& !is_blocked(data, data->pos_x, data->donnee->new_pos_y - 0.15)
		&& !is_blocked(data, data->pos_x + 0.15, data->donnee->new_pos_y)
		&& !is_blocked(data, data->pos_x - 0.15, data->donnee->new_pos_y))
		data->pos_y = data->donnee->new_pos_y;
}

static void	key_d(t_data *data)
{
	data->donnee->new_pos_x = data->pos_x + (data->plane_x * 0.05);
	data->donnee->new_pos_y = data->pos_y + (data->plane_y * 0.05);
	if (!is_blocked(data, data->donnee->new_pos_x + 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x - 0.15, data->pos_y)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y + 0.15)
		&& !is_blocked(data, data->donnee->new_pos_x, data->pos_y - 0.15))
		data->pos_x = data->donnee->new_pos_x;
	if (!is_blocked(data, data->pos_x, data->donnee->new_pos_y + 0.15)
		&& !is_blocked(data, data->pos_x, data->donnee->new_pos_y - 0.15)
		&& !is_blocked(data, data->pos_x + 0.15, data->donnee->new_pos_y)
		&& !is_blocked(data, data->pos_x - 0.15, data->donnee->new_pos_y))
		data->pos_y = data->donnee->new_pos_y;
}

void	check_key_moves(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (mlx_is_key_down(data->game->init, MLX_KEY_W))
		key_w(data);
	else if (mlx_is_key_down(data->game->init, MLX_KEY_S))
		key_s(data);
	else if (mlx_is_key_down(data->game->init, MLX_KEY_D))
		key_d(data);
	else if (mlx_is_key_down(data->game->init, MLX_KEY_A))
		key_a(data);
	key_door(data);
	update(data->game, data);
}
