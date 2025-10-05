/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_floor_for_update.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:06:35 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/02 00:05:42 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_floor_sky(t_data *data)
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
