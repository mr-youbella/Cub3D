/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:49:49 by youbella          #+#    #+#             */
/*   Updated: 2025/09/12 20:20:54 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

short	is_empty(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static size_t	ft_long_row(char **map)
{
	size_t	i;
	size_t	len_row;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		len_row = ft_strlen(map[i]);
		if (len_row >= max_len)
			max_len = len_row;
		i++;
	}
	return (max_len);
}

static short	add_spaces_in_map(t_map_data *map_data,
									size_t j, size_t k, size_t i)
{
	size_t	len_row;
	size_t	long_row;
	char	*new_row;

	long_row = ft_long_row(map_data->map);
	while (map_data->map[i])
	{
		1 && (j = 0, k = 0);
		len_row = ft_strlen(map_data->map[i]);
		if (len_row < long_row)
		{
			new_row = malloc(len_row + (long_row - len_row) + 1);
			if (!new_row)
				return (0);
			while (map_data->map[i][j])
				new_row[k++] = map_data->map[i][j++];
			j = 0;
			while (j < long_row - len_row)
				1 && (new_row[k++] = ' ', j++);
			1 && (new_row[k] = 0, map_data->map[i] = new_row);
		}
		i++;
	}
	return (1);
}

static short	get_lines_map(t_map_data *map_data, char **line, int fd)
{
	char	*join_line;
	char	**split;

	join_line = NULL;
	while (*line)
	{
		while (*line && ((*line)[0] == '\n' || is_empty(*line)))
		{
			*line = get_next_line(fd);
			if (*line && !is_empty(*line))
			{
				ft_putstr_fd("Error\nError: Empty line in map!\n", 2);
				return (0);
			}
		}
		join_line = ft_strjoin(join_line, *line);
		*line = get_next_line(fd);
	}
	split = ft_split(join_line, '\n');
	if (!split)
		return (ft_putstr_fd("Error\nMap no found\n", 2), 0);
	map_data->map = split;
	return (1);
}

t_map_data	*ft_map_data(char *path)
{
	t_map_data	*map_data;
	char		*line;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nFile not open!\n", 2), NULL);
	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
		return (NULL);
	ft_memset(map_data, 0, sizeof(t_map_data));
	if (!get_identifiers(fd, &line, map_data))
		return (free(map_data), NULL);
	while (line)
	{
		if (line[0] != '\n' && !is_empty(line))
			break ;
		line = get_next_line(fd);
	}
	if (!get_lines_map(map_data, &line, fd))
		return (free(map_data), NULL);
	if (!add_spaces_in_map(map_data, 0, 0, 0) || !check_map(map_data))
		return (free(map_data), NULL);
	return (map_data);
}
