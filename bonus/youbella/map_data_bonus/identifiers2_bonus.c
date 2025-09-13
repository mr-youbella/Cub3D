/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:47:09 by youbella          #+#    #+#             */
/*   Updated: 2025/09/12 20:18:11 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static short	mark_identifiers(char *identifier)
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

static short	identifiers_cub(t_map_data *map_data, int fd, char **line)
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

static short	get_we_ea_image(t_map_data *map_data, size_t i, size_t j)
{
	i = 2;
	while (map_data->we_img[i] == ' ' || map_data->we_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->we_img[i]))
	{
		ft_putstr_fd("Error\nWE Image not found.\n", 2);
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
		ft_putstr_fd("Error\nEA Image not found.\n", 2);
		return (0);
	}
	j = ft_strlen(map_data->ea_img) - 1;
	while (map_data->ea_img[j] == ' ' || map_data->ea_img[j] == '\t')
		j--;
	map_data->ea_img = ft_substr(map_data->ea_img, i, j - i + 1);
	return (1);
}

static short	get_name_images(t_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 2;
	while (map_data->no_img[i] == ' ' || map_data->no_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->no_img[i]))
		return (ft_putstr_fd("Error\nNO Image not found.\n", 2), 0);
	j = ft_strlen(map_data->no_img) - 1;
	while (map_data->no_img[j] == ' ' || map_data->no_img[j] == '\t')
		j--;
	map_data->no_img = ft_substr(map_data->no_img, i, j - i + 1);
	i = 2;
	while (map_data->so_img[i] == ' ' || map_data->so_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->so_img[i]))
		return (ft_putstr_fd("Error\nSO Image not found.\n", 2), 0);
	j = ft_strlen(map_data->so_img) - 1;
	while (map_data->so_img[j] == ' ' || map_data->so_img[j] == '\t')
		j--;
	map_data->so_img = ft_substr(map_data->so_img, i, j - i + 1);
	if (!get_we_ea_image(map_data, 0, 0))
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
