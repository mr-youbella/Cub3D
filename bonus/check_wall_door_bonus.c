/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:14:57 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/11 14:16:16 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

short	is_blocked(t_data *data, float x, float y)
{
	char	block;

	block = data->map_data->map[(int)y][(int)x];
	if (block == '1' || block == 'D')
		return (1);
	return (0);
}
