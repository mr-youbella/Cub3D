/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_sky.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 03:36:35 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/02 03:38:53 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
