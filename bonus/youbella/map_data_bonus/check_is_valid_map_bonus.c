/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:58:47 by youbella          #+#    #+#             */
/*   Updated: 2025/10/09 20:22:03 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static short	is_valid_map2(char **map, size_t i, size_t j)
{
	static int	identifier_count;

	if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W'
		|| map[i][j] == 'D' || map[i][j] == '0')
	{
		if (!i || !j || !map[i + 1] || !map[i][j + 1])
			return (-1);
		if (map[i][j] == 'D')
		{
			if (!((map[i - 1][j] == '1' && map[i + 1][j] == '1')
				|| (map[i][j - 1] == '1' && map[i][j + 1] == '1')))
				return (-1);
		}
		if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == 'W')
			identifier_count++;
		if (identifier_count > 1)
			return (-1);
		if (map[i + 1][j] == ' ' || map[i][j + 1] == ' '
			|| map[i - 1][j] == ' ' || map[i][j - 1] == ' ')
			return (-1);
	}
	return (identifier_count);
}

bool	is_valid_map(char **map, size_t i, size_t j)
{
	int	identifier_count;

	if (!(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
		|| map[i][j] == 'W' || map[i][j] == '0' || map[i][j] == '1'
		|| map[i][j] == ' ' || map[i][j] == 'D'))
		return (false);
	identifier_count = is_valid_map2(map, i, j);
	if (identifier_count == -1)
		return (false);
	if (!map[i + 1] && !map[i][j + 1])
	{
		if (!identifier_count)
			return (false);
	}
	return (true);
}

bool	check_map(t_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (!is_valid_map(map_data->map, i, j))
			{
				ft_putstr_fd("Error\nInvalid Map\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
