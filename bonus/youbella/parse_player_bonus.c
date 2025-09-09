/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:25:00 by youbella          #+#    #+#             */
/*   Updated: 2025/09/09 16:05:58 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	check_pos(char c, t_data *data)
{
	if (c == 'N')
	{
		data->dir_x = (float)cos((3 * M_PI) / 2);
		data->dir_y = (float)sin((3 * M_PI) / 2);
	}
	else if (c == 'S')
	{
		data->dir_x = (float)cos(M_PI / 2);
		data->dir_y = (float)sin(M_PI / 2);
	}
	else if (c == 'E')
	{
		data->dir_x = (float)cos(0);
		data->dir_y = (float)sin(0);
	}
	else if (c == 'W')
	{
		data->dir_x = (float)cos(M_PI);
		data->dir_y = (float)sin(M_PI);
	}
}

void	player_position(t_data *player)
{
	int	i;	
	int	j;

	i = 0;
	while (player->map_data->map[i])
	{
		j = 0;
		while (player->map_data->map[i][j])
		{
			if (player->map_data->map[i][j] == 'N' || player->map_data->map[i][j] == 'S'
				|| player->map_data->map[i][j] == 'E' || player->map_data->map[i][j] == 'W')
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				check_pos(player->map_data->map[i][j], player);
				player->plane_x = -player->dir_y * 0.66;
				player->plane_y = player->dir_x * 0.66;
				return ;
			}
			j++;
		}
		i++;
	}
}
