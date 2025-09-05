/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:25:00 by youbella          #+#    #+#             */
/*   Updated: 2025/09/01 17:50:22 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_pos(char c, t_player_map *player)
{
	if (c == 'N')
	{
		1 && (player->dir_x = (float)cos((3 * M_PI) / 2), player->dir_y = (float)sin((3 * M_PI) / 2));
		player->plane_x = -player->dir_y * 0.66; 
		player->plane_y = player->dir_x * 0.66;
	}
	else if (c == 'S')
	{
		1 && (player->dir_x = (float)cos(M_PI / 2), player->dir_y = (float)sin(M_PI / 2));
		player->plane_x = -player->dir_y * 0.66; 
		player->plane_y = player->dir_x * 0.66;
	}
	else if (c == 'E')
	{
		1 && (player->dir_x = (float)cos(0), player->dir_y = (float)sin(0));
		player->plane_x = -player->dir_y * 0.66;
		player->plane_y = player->dir_x * 0.66;
	}
	else if (c == 'W')
	{
		1 && (player->dir_x = (float)cos(M_PI), player->dir_y = (float)sin(M_PI));
		player->plane_x = -player->dir_y * 0.66;
		player->plane_y = player->dir_x * 0.66;
	}
}

void	player_position(t_player_map *player)
{
	int	i;	
	int	j;

	i = 0;
	while (player->map[i])
	{
		j = 0;
		while (player->map[i][j])
		{
			if (player->map[i][j] == 'N' || player->map[i][j] == 'S'
				|| player->map[i][j] == 'E' || player->map[i][j] == 'W')
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				check_pos(player->map[i][j], player);
				return ;
			}
			j++;
		}
		i++;
	}
}
