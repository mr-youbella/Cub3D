/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:49:49 by youbella          #+#    #+#             */
/*   Updated: 2025/09/08 18:07:12 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

short	get_identifiers(int fd, char **line, t_map_data *map_data)
{
	size_t	i;
	size_t	j;
	char	*identifier;
	char	**split;
	char	*f_color;
	char	*c_color;
	int		rgba[3];

	identifier = malloc(7);
	ft_strlcpy(identifier, "NSWEFC", 8);
	*line = get_next_line(fd);
	while (*line)
	{
		if (*line[0] == '\n')
		{
			*line = get_next_line(fd);
			continue ;
		}
		if (*line[0] == 'N' && identifier[0] == 'N')
		{
			if (!ft_strncmp(*line, "NO ", 3) || !ft_strncmp(*line, "NO\n", 3))
			{
				map_data->no_img = ft_strdup(*line);
				identifier[0] = 'X';
			}
			else
				return (0);
		}
		else if (*line[0] == 'S' && identifier[1] == 'S')
		{
			if (!ft_strncmp(*line, "SO ", 3) || !ft_strncmp(*line, "SO\n", 3))
			{
				map_data->so_img = ft_strdup(*line);
				identifier[1] = 'X';
			}
			else
				return (0);
		}
		else if (*line[0] == 'W' && identifier[2] == 'W')
		{
			if (!ft_strncmp(*line, "WE ", 3) || !ft_strncmp(*line, "WE\n", 3))
			{
				map_data->we_img = ft_strdup(*line);
				identifier[2] = 'X';
			}
			else
				return (0);
		}
		else if (*line[0] == 'E' && identifier[3] == 'E')
		{
			if (!ft_strncmp(*line, "EA ", 3) || !ft_strncmp(*line, "EA\n", 3))
			{
				map_data->ea_img = ft_strdup(*line);
				identifier[3] = 'X';
			}
			else
				return (0);
		}
		else if (*line[0] == 'F' && identifier[4] == 'F')
		{
			if (!ft_strncmp(*line, "F ", 2) || !ft_strncmp(*line, "F\n", 2))
			{
				f_color = ft_strdup(*line);
				identifier[4] = 'X';
			}
			else
				return (0);
		}
		else if (*line[0] == 'C' && identifier[5] == 'C')
		{
			if (!ft_strncmp(*line, "C ", 2) || !ft_strncmp(*line, "C\n", 2))
			{
				c_color = ft_strdup(*line);
				identifier[5] = 'X';
			}
			else
				return (0);
		}
		else
			return (0);
		*line = get_next_line(fd);
		i = 0;
		while (identifier[i])
		{
			if (identifier[i] != 'X')
				break ;
			i++;
		}
		if (i == 6)
			break ;
	}
	i = 2;
	while (map_data->no_img[i] == ' ' || map_data->no_img[i] == '\t')
		i++;
	map_data->no_img = ft_substr(map_data->no_img, i, ft_strlen(map_data->no_img) - i - 1);
	if (ft_strlen(map_data->no_img) < 4)
	{
		ft_putstr_fd("Wrong name in NO Image\n", 2);
		return (0);
	}
	i = 2;
	while (map_data->so_img[i] == ' ' || map_data->so_img[i] == '\t')
		i++;
	map_data->so_img = ft_substr(map_data->so_img, i, ft_strlen(map_data->so_img) - i - 1);
	if (ft_strlen(map_data->so_img) < 4)
	{
		ft_putstr_fd("Wrong name in SO Image\n", 2);
		return (0);
	}
	i = 2;
	while (map_data->we_img[i] == ' ' || map_data->we_img[i] == '\t')
		i++;
	map_data->we_img = ft_substr(map_data->we_img, i, ft_strlen(map_data->we_img) - i - 1);
	if (ft_strlen(map_data->we_img) < 4)
	{
		ft_putstr_fd("Wrong name in WE Image\n", 2);
		return (0);
	}
	i = 2;
	while (map_data->ea_img[i] == ' ' || map_data->ea_img[i] == '\t')
		i++;
	map_data->ea_img = ft_substr(map_data->ea_img, i, ft_strlen(map_data->ea_img) - i - 1);
	if (ft_strlen(map_data->ea_img) < 4)
	{
		ft_putstr_fd("Wrong name in EA Image\n", 2);
		return (0);
	}
	i = 1;
	while (f_color[i] == ' ' || f_color[i] == '\t')
		i++;
	f_color = ft_substr(f_color, i, ft_strlen(f_color) - i - 1);
	if (!ft_strlen(f_color))
	{
		ft_putstr_fd("Wrong name in F color\n", 2);
		return (0);
	}
	i = 1;
	while (c_color[i] == ' ' || c_color[i] == '\t')
		i++;
	c_color = ft_substr(c_color, i, ft_strlen(c_color) - i - 1);
	if (!ft_strlen(c_color))
	{
		ft_putstr_fd("Wrong name in C color\n", 2);
		return (0);
	}
	split = ft_split(f_color, ',');
	if (!split)
	{
		ft_putstr_fd("Color F no found\n", 2);
		return (0);
	}
	i = 0;
	while (split[i])
	{
		if (i == 3)
		{
			ft_putstr_fd("Syntax error in color\n", 2);
			return (0);
		}
		j = 0;
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
			{
				ft_putstr_fd("Syntax error in color\n", 2);
				return (0);
			}
			j++;
		}
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
		{
			ft_putstr_fd("Syntax error in color\n", 2);
			return (0);
		}
		rgba[i] = ft_atoi(split[i]);
		i++;
	}
	map_data->f_color = rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | 255;
	split = ft_split(c_color, ',');
	if (!split)
	{
		ft_putstr_fd("Color C no found\n", 2);
		return (0);
	}
	i = 0;
	while (split[i])
	{
		if (i == 3)
		{
			ft_putstr_fd("Syntax error in color\n", 2);
			return (0);
		}
		j = 0;
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
			{
				ft_putstr_fd("Syntax error in color\n", 2);
				return (0);
			}
			j++;
		}
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
		{
			ft_putstr_fd("Syntax error in color\n", 2);
			return (0);
		}
		rgba[i] = ft_atoi(split[i]);
		i++;
	}
	map_data->c_color = rgba[0] << 24 | rgba[1] << 16 | rgba[2] << 8 | 255;
	return (1);
}

t_map_data	*ft_map_data(char *path)
{
	t_map_data	*map_data;
	char		**split;
	char		*join_line;
	char		*line;
	int			fd;

	join_line = NULL;
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
		if (line[0] != '\n')
			break ;
		line = get_next_line(fd);
	}
	while (line)
	{
		if (line[0] == '\n')
		{
			ft_putstr_fd("Error: Empty line!\n", 2);
			return (NULL);
		}
		join_line = ft_strjoin(join_line, line);
		line = get_next_line(fd);
	}
	split = ft_split(join_line, '\n');
	if (!split)
	{
		ft_putstr_fd("Map no found\n", 2);
		return (NULL);
	}
	map_data->map = split;
	return (map_data);
}
