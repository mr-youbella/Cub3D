/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifiers_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:08:18 by youbella          #+#    #+#             */
/*   Updated: 2025/10/06 14:39:25 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	f_color(t_map_data *map_data, char **line, char *identifier)
{
	size_t	i;

	i = 0;
	if (!ft_strncmp(&(*line)[i], "F ", 2)
		|| !ft_strncmp(&(*line)[i], "F\t", 2))
	{
		1 && (map_data->str_f_color
			= ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1),
				identifier[4] = 'X');
		allocfreecraft(0, map_data->str_f_color, 2);
		return (true);
	}
	return (false);
}

bool	identifiers_colors(t_map_data *map_data, char **line, char *identifier)
{
	size_t	i;

	i = 0;
	if ((*line)[i] == 'F' && identifier[4] == 'F')
	{
		if (f_color(map_data, line, identifier))
			return (true);
		return (false);
	}
	else if ((*line)[i] == 'C' && identifier[5] == 'C')
	{
		if (!ft_strncmp(&(*line)[i], "C ", 2)
			|| !ft_strncmp(&(*line)[i], "C\t", 2))
		{
			map_data->str_c_color
				= ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			allocfreecraft(0, map_data->str_c_color, 2);
			identifier[5] = 'X';
		}
		else
			return (false);
	}
	else
		return (false);
	return (true);
}
