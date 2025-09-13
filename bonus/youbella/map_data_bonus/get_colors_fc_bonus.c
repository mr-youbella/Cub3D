/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_fc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:50:08 by youbella          #+#    #+#             */
/*   Updated: 2025/09/12 20:17:50 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

short	identifiers_colors(t_map_data *map_data,
							char **line, char *identifier, size_t i)
{
	if ((*line)[i] == 'F' && identifier[4] == 'F')
	{
		if (!ft_strncmp(&(*line)[i], "F ", 2)
			|| !ft_strncmp(&(*line)[i], "F\t", 2))
			1 && (map_data->str_f_color
				= ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1),
					identifier[4] = 'X');
		else
			return (0);
	}
	else if ((*line)[i] == 'C' && identifier[5] == 'C')
	{
		if (!ft_strncmp(&(*line)[i], "C ", 2)
			|| !ft_strncmp(&(*line)[i], "C\t", 2))
		{
			map_data->str_c_color
				= ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			identifier[5] = 'X';
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

static short	check_colors_is_found(t_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map_data->str_f_color[i] == ' ' || map_data->str_f_color[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->str_f_color[i]))
		return (ft_putstr_fd("Error\nF color not found.\n", 2), 0);
	j = ft_strlen(map_data->str_f_color) - 1;
	while (map_data->str_f_color[j] == ' ' || map_data->str_f_color[j] == '\t')
		j--;
	map_data->str_f_color = ft_substr(map_data->str_f_color, i, j - i + 1);
	i = 1;
	while (map_data->str_c_color[i] == ' ' || map_data->str_c_color[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->str_c_color[i]))
		return (ft_putstr_fd("Error\nC color not found.\n", 2), 0);
	j = ft_strlen(map_data->str_c_color) - 1;
	while (map_data->str_c_color[j] == ' ' || map_data->str_c_color[j] == '\t')
		j--;
	map_data->str_c_color = ft_substr(map_data->str_c_color, i, j - i + 1);
	return (1);
}

static short	check_syntax_f_color(t_map_data *map_data,
								size_t i, size_t j, char **split)
{
	int		rgba[3];

	split = ft_split(map_data->str_f_color, ',');
	if (!split)
		return (ft_putstr_fd("Error\nF color not found.\n", 2), 0);
	while (split[i])
	{
		if (i == 3)
			return (ft_putstr_fd("Error\nSyntax error in F color\n", 2), 0);
		j = 0;
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
				return (ft_putstr_fd("Error\nSyntax error in F color\n", 2), 0);
			j++;
		}
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (ft_putstr_fd("Error\nSyntax error in F color\n", 2), 0);
		rgba[i] = ft_atoi(split[i]);
		i++;
	}
	if (i != 3)
		return (ft_putstr_fd("Error\nSyntax error in F color\n", 2), 0);
	map_data->f_color = rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | 255;
	return (1);
}

static short	check_syntax_c_color(t_map_data *map_data,
								size_t i, size_t j, char **split)
{
	int		rgba[3];

	split = ft_split(map_data->str_c_color, ',');
	if (!split)
		return (ft_putstr_fd("Error\nC color not found.\n", 2), 0);
	while (split[i])
	{
		if (i == 3)
			return (ft_putstr_fd("Syntax error in C color\n", 2), 0);
		j = 0;
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
				return (ft_putstr_fd("Error\nSyntax error in C color\n", 2), 0);
			j++;
		}
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (ft_putstr_fd("Error\nSyntax error in C color\n", 2), 0);
		rgba[i] = ft_atoi(split[i]);
		i++;
	}
	if (i != 3)
		return (ft_putstr_fd("Error\nSyntax error in C color\n", 2), 0);
	map_data->c_color = rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | 255;
	return (1);
}

short	get_hexa_colors(t_map_data *map_data)
{
	if (!check_colors_is_found(map_data))
		return (0);
	if (!check_syntax_f_color(map_data, 0, 0, NULL))
		return (0);
	if (!check_syntax_c_color(map_data, 0, 0, NULL))
		return (0);
	return (1);
}
