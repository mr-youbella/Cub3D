/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:49:49 by youbella          #+#    #+#             */
/*   Updated: 2025/09/11 17:49:34 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

short	identifiers_ws(t_map_data *map_data,
						char **line, char *identifier, size_t i)
{
	if ((*line)[i] == 'W' && identifier[2] == 'W')
	{
		if (!ft_strncmp(&(*line)[i], "WE ", 3)
			|| !ft_strncmp(&(*line)[i], "WE\t", 3))
		{
			map_data->we_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			identifier[2] = 'X';
		}
		else
			return (0);
	}
	else if ((*line)[i] == 'E' && identifier[3] == 'E')
	{
		if (!ft_strncmp(&(*line)[i], "EA ", 3)
			|| !ft_strncmp(&(*line)[i], "EA\t", 3))
		{
			map_data->ea_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			identifier[3] = 'X';
		}
		else
			return (0);
	}
	return (1);
}

short	identifiers_news(t_map_data *map_data,
							char **line, char *identifier, size_t i)
{
	if ((*line)[i] == 'N' && identifier[0] == 'N')
	{
		if (!ft_strncmp(&(*line)[i], "NO ", 3)
			|| !ft_strncmp(&(*line)[i], "NO\t", 3))
		{
			map_data->no_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			identifier[0] = 'X';
		}
		else
			return (0);
	}
	else if ((*line)[i] == 'S' && identifier[1] == 'S')
	{
		if (!ft_strncmp(&(*line)[i], "SO ", 3)
			|| !ft_strncmp(&(*line)[i], "SO\t", 3))
		{
			map_data->so_img = ft_substr(*line, i, ft_strlen(&(*line)[i]) - 1);
			identifier[1] = 'X';
		}
		else
			return (0);
	}
	if (!identifiers_ws(map_data, line, identifier, i))
		return (0);
	return (1);
}

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

short	identifiers(t_map_data *map_data,
						char **line, char *identifier, size_t i)
{
	if (((*line)[i] == 'N' && identifier[0] == 'N')
		|| ((*line)[i] == 'S' && identifier[1] == 'S')
		|| ((*line)[i] == 'W' && identifier[2] == 'W')
		|| ((*line)[i] == 'E' && identifier[3] == 'E'))
	{
		if (!identifiers_news(map_data, line, identifier, i))
			return (0);
	}
	else if (!identifiers_colors(map_data, line, identifier, i))
		return (0);
	return (1);
}

short	mark_identifiers(char *identifier)
{
	size_t	i;

	i = 0;
	while (identifier[i])
	{
		if (identifier[i] != 'X')
			break ;
		i++;
	}
	if (i == 6)
		return (1);
	return (0);
}

short	identifiers_cub(t_map_data *map_data, int fd, char **line)
{
	size_t	i;
	char	*identifier;

	identifier = ft_strdup("NSWEFC");
	while (*line)
	{
		if (*line[0] == '\n' || is_empty(*line))
		{
			*line = get_next_line(fd);
			continue ;
		}
		i = 0;
		while ((*line)[i] == ' ' || (*line)[i] == '\t')
			i++;
		if (!identifiers(map_data, line, identifier, i))
			return (0);
		*line = get_next_line(fd);
		if (mark_identifiers(identifier))
			break ;
	}
	if (!*line)
		return (0);
	return (1);
}

short	get_we_ea_image(t_map_data *map_data, size_t i, size_t j)
{
	i = 2;
	while (map_data->we_img[i] == ' ' || map_data->we_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->we_img[i]))
	{
		ft_putstr_fd("WE Image not found.\n", 2);
		return (0);
	}
	j = ft_strlen(map_data->we_img) - 1;
	while (map_data->we_img[j] == ' ' || map_data->we_img[j] == '\t')
		j--;
	map_data->we_img = ft_substr(map_data->we_img, i, j - i + 1);
	i = 2;
	while (map_data->ea_img[i] == ' ' || map_data->ea_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->ea_img[i]))
	{
		ft_putstr_fd("EA Image not found.\n", 2);
		return (0);
	}
	j = ft_strlen(map_data->ea_img) - 1;
	while (map_data->ea_img[j] == ' ' || map_data->ea_img[j] == '\t')
		j--;
	map_data->ea_img = ft_substr(map_data->ea_img, i, j - i + 1);
	return (1);
}

short	get_name_images(t_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 2;
	while (map_data->no_img[i] == ' ' || map_data->no_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->no_img[i]))
		return (ft_putstr_fd("NO Image not found.\n", 2), 0);
	j = ft_strlen(map_data->no_img) - 1;
	while (map_data->no_img[j] == ' ' || map_data->no_img[j] == '\t')
		j--;
	map_data->no_img = ft_substr(map_data->no_img, i, j - i + 1);
	i = 2;
	while (map_data->so_img[i] == ' ' || map_data->so_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->so_img[i]))
		return (ft_putstr_fd("SO Image not found.\n", 2), 0);
	j = ft_strlen(map_data->so_img) - 1;
	while (map_data->so_img[j] == ' ' || map_data->so_img[j] == '\t')
		j--;
	map_data->so_img = ft_substr(map_data->so_img, i, j - i + 1);
	if (!get_we_ea_image(map_data, 0, 0))
		return (0);
	return (1);
}

short	check_colors_is_found(t_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map_data->str_f_color[i] == ' ' || map_data->str_f_color[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->str_f_color[i]))
		return (ft_putstr_fd("F color not found.\n", 2), 0);
	j = ft_strlen(map_data->str_f_color) - 1;
	while (map_data->str_f_color[j] == ' ' || map_data->str_f_color[j] == '\t')
		j--;
	map_data->str_f_color = ft_substr(map_data->str_f_color, i, j - i + 1);
	i = 1;
	while (map_data->str_c_color[i] == ' ' || map_data->str_c_color[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->str_c_color[i]))
		return (ft_putstr_fd("C color not found.\n", 2), 0);
	j = ft_strlen(map_data->str_c_color) - 1;
	while (map_data->str_c_color[j] == ' ' || map_data->str_c_color[j] == '\t')
		j--;
	map_data->str_c_color = ft_substr(map_data->str_c_color, i, j - i + 1);
	return (1);
}

short	check_syntax_f_color(t_map_data *map_data,
								size_t i, size_t j, char **split)
{
	int		rgba[3];

	split = ft_split(map_data->str_f_color, ',');
	if (!split)
		return (ft_putstr_fd("F color not found.\n", 2), 0);
	while (split[i])
	{
		if (i == 3)
			return (ft_putstr_fd("Syntax error in F color\n", 2), 0);
		j = 0;
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
				return (ft_putstr_fd("Syntax error in F color\n", 2), 0);
			j++;
		}
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (ft_putstr_fd("Syntax error in F color\n", 2), 0);
		rgba[i] = ft_atoi(split[i]);
		i++;
	}
	if (i != 3)
		return (ft_putstr_fd("Syntax error in F color\n", 2), 0);
	map_data->f_color = rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | 255;
	return (1);
}

short	check_syntax_c_color(t_map_data *map_data,
								size_t i, size_t j, char **split)
{
	int		rgba[3];

	split = ft_split(map_data->str_c_color, ',');
	if (!split)
		return (ft_putstr_fd("C color not found.\n", 2), 0);
	while (split[i])
	{
		if (i == 3)
			return (ft_putstr_fd("Syntax error in C color\n", 2), 0);
		j = 0;
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
				return (ft_putstr_fd("Syntax error in C color\n", 2), 0);
			j++;
		}
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (ft_putstr_fd("Syntax error in C color\n", 2), 0);
		rgba[i] = ft_atoi(split[i]);
		i++;
	}
	if (i != 3)
		return (ft_putstr_fd("Syntax error in C color\n", 2), 0);
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

short	get_identifiers(int fd, char **line, t_map_data *map_data)
{
	*line = get_next_line(fd);
	if (!identifiers_cub(map_data, fd, line))
		return (0);
	if (!get_name_images(map_data))
		return (0);
	if (!get_hexa_colors(map_data))
		return (0);
	return (1);
}

short	is_valid_map2(char **map, size_t i, size_t j)
{
	static int	identifier_count;

	if (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W'
		|| map[i][j] == 'D' || map[i][j] == '0')
	{
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
		|| map[i][j] == ' '))
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

size_t	ft_long_row(char **map)
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

short	add_spaces_in_map(t_map_data *map_data, size_t j, size_t k, size_t i)
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

short	get_lines_map(t_map_data *map_data, char **line, int fd)
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
				return (ft_putstr_fd("Error: Empty line in map!\n", 2), 0);
		}
		join_line = ft_strjoin(join_line, *line);
		*line = get_next_line(fd);
	}
	split = ft_split(join_line, '\n');
	if (!split)
		return (ft_putstr_fd("Map no found\n", 2), 0);
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
		return (ft_putstr_fd("Error: file not open!\n", 2), NULL);
	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
		return (NULL);
	ft_memset(map_data, 0, sizeof(t_map_data));
	if (!get_identifiers(fd, &line, map_data))
		return (NULL);
	while (line)
	{
		if (line[0] != '\n' && !is_empty(line))
			break ;
		line = get_next_line(fd);
	}
	if (!get_lines_map(map_data, &line, fd))
		return (NULL);
	if (!add_spaces_in_map(map_data, 0, 0, 0) || !check_map(map_data))
		return (NULL);
	return (map_data);
}
