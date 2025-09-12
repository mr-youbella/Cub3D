/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:58:47 by youbella          #+#    #+#             */
/*   Updated: 2025/09/12 14:13:35 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

short	check_map(t_map_data *map_data)
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
				ft_putstr_fd("Invalid Map\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static short	is_valid_map2(char **map, size_t i, size_t j)
{
	static int	identifier_count;

	if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W'
		|| map[i][j] == 'D' || map[i][j] == '0')
	{
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
		if (!i || !j || !map[i + 1] || !map[i][j + 1])
			return (0);
		if (map[i + 1][j] == ' ' || map[i][j + 1] == ' '
			|| map[i - 1][j] == ' ' || map[i][j - 1] == ' ')
			return (-1);
	}
	return (identifier_count);
}

short	is_valid_map(char **map, size_t i, size_t j)
{
	int	identifier_count;

	if (!(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
		|| map[i][j] == 'W' || map[i][j] == '0' || map[i][j] == '1'
		|| map[i][j] == ' ' || map[i][j] == 'D'))
		return (0);
	identifier_count = is_valid_map2(map, i, j);
	if (identifier_count == -1)
		return (0);
	if (!map[i + 1] && !map[i][j + 1])
	{
		if (!identifier_count)
			return (0);
	}
	return (1);
}
