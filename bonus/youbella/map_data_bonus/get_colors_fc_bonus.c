/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_fc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:50:08 by youbella          #+#    #+#             */
/*   Updated: 2025/10/06 14:08:24 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static bool	check_comma(char *str)
{
	size_t	i;
	short	comma;

	i = 0;
	comma = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			comma++;
		if (comma > 2)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_colors_is_found(t_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map_data->str_f_color[i] == ' ' || map_data->str_f_color[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->str_f_color[i]))
		return (ft_putstr_fd("Error\nF color not found.\n", 2), false);
	j = ft_strlen(map_data->str_f_color) - 1;
	while (map_data->str_f_color[j] == ' ' || map_data->str_f_color[j] == '\t')
		j--;
	map_data->str_f_color = ft_substr(map_data->str_f_color, i, j - i + 1);
	allocfreecraft(0, map_data->str_f_color, 2);
	i = 1;
	while (map_data->str_c_color[i] == ' ' || map_data->str_c_color[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->str_c_color[i]))
		return (ft_putstr_fd("Error\nC color not found.\n", 2), false);
	j = ft_strlen(map_data->str_c_color) - 1;
	while (map_data->str_c_color[j] == ' ' || map_data->str_c_color[j] == '\t')
		j--;
	map_data->str_c_color = ft_substr(map_data->str_c_color, i, j - i + 1);
	allocfreecraft(0, map_data->str_c_color, 2);
	return (true);
}

static bool	check_syntax_f_color(t_map_data *map_data,
								size_t i, size_t j, char **split)
{
	split = ft_split(map_data->str_f_color, ',');
	if (!split)
		return (ft_putstr_fd("Error\nF color not found.\n", 2), 0);
	allocfreecraft(0, split, 3);
	while (split[i])
	{
		if (!check_comma(map_data->str_f_color) || i == 3)
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
		i++;
	}
	if (i != 3)
		return (ft_putstr_fd("Error\nSyntax error in F color\n", 2), 0);
	map_data->f_color = ft_atoi(split[0]) << 24
		| ft_atoi(split[1]) << 16 | ft_atoi(split[2]) << 8 | 255;
	return (1);
}

static bool	check_syntax_c_color(t_map_data *map_data,
								size_t i, size_t j, char **split)
{
	split = ft_split(map_data->str_c_color, ',');
	if (!split)
		return (ft_putstr_fd("Error\nC color not found.\n", 2), 0);
	allocfreecraft(0, split, 3);
	while (split[i])
	{
		if (!check_comma(map_data->str_c_color) || i == 3)
			return (ft_putstr_fd("Error\nSyntax error in C color\n", 2), 0);
		j = 0;
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
				return (ft_putstr_fd("Error\nSyntax error in C color\n", 2), 0);
			j++;
		}
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (ft_putstr_fd("Error\nSyntax error in C color\n", 2), 0);
		i++;
	}
	if (i != 3)
		return (ft_putstr_fd("Error\nSyntax error in C color\n", 2), 0);
	map_data->c_color = ft_atoi(split[0]) << 24
		| ft_atoi(split[1]) << 16 | ft_atoi(split[2]) << 8 | 255;
	return (1);
}

bool	get_hexa_colors(t_map_data *map_data)
{
	if (!check_colors_is_found(map_data))
		return (0);
	if (!check_syntax_f_color(map_data, 0, 0, NULL))
		return (0);
	if (!check_syntax_c_color(map_data, 0, 0, NULL))
		return (0);
	return (1);
}
