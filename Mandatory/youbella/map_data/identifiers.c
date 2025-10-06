/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:53:26 by youbella          #+#    #+#             */
/*   Updated: 2025/10/06 14:37:12 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	identifiers_ws(t_map_data *map_data,
						char **line, char *identifier, size_t i)
{
	if ((*line)[i] == 'W' && identifier[2] == 'W')
	{
		if (!ft_strncmp(&(*line)[i], "WE ", 3)
			|| !ft_strncmp(&(*line)[i], "WE\t", 3))
		{
			map_data->we_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			1 && (allocfreecraft(0, map_data->we_img, 2), identifier[2] = 'X');
		}
		else
			return (false);
	}
	else if ((*line)[i] == 'E' && identifier[3] == 'E')
	{
		if (!ft_strncmp(&(*line)[i], "EA ", 3)
			|| !ft_strncmp(&(*line)[i], "EA\t", 3))
		{
			map_data->ea_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			1 && (allocfreecraft(0, map_data->ea_img, 2), identifier[3] = 'X');
		}
		else
			return (false);
	}
	return (true);
}

static bool	identifiers_news(t_map_data *map_data,
							char **line, char *identifier, size_t i)
{
	if ((*line)[i] == 'N' && identifier[0] == 'N')
	{
		if (!ft_strncmp(&(*line)[i], "NO ", 3)
			|| !ft_strncmp(&(*line)[i], "NO\t", 3))
		{
			map_data->no_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			1 && (allocfreecraft(0, map_data->no_img, 2), identifier[0] = 'X');
		}
		else
			return (false);
	}
	else if ((*line)[i] == 'S' && identifier[1] == 'S')
	{
		if (!ft_strncmp(&(*line)[i], "SO ", 3)
			|| !ft_strncmp(&(*line)[i], "SO\t", 3))
		{
			map_data->so_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			1 && (allocfreecraft(0, map_data->so_img, 2), identifier[1] = 'X');
		}
		else
			return (false);
	}
	if (!identifiers_ws(map_data, line, identifier, i))
		return (false);
	return (true);
}

bool	identifiers(t_map_data *map_data,
						char **line, char *identifier, size_t i)
{
	if (((*line)[i] == 'N' && identifier[0] == 'N')
		|| ((*line)[i] == 'S' && identifier[1] == 'S')
		|| ((*line)[i] == 'W' && identifier[2] == 'W')
		|| ((*line)[i] == 'E' && identifier[3] == 'E'))
	{
		if (!identifiers_news(map_data, line, identifier, i))
			return (false);
	}
	else if (!identifiers_colors(map_data, line, identifier))
		return (false);
	return (true);
}
