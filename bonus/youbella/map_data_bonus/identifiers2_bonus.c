/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:47:09 by youbella          #+#    #+#             */
/*   Updated: 2025/10/06 15:53:15 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static bool	mark_identifiers(char *identifier)
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
		return (true);
	return (false);
}

static bool	identifiers_cub(t_map_data *map_data, size_t i,
								int fd, char **line)
{
	char	*identifier;

	identifier = ft_strdup("NSWEFC");
	while (*line)
	{
		if (*line[0] == '\n' || is_empty(*line))
		{
			*line = get_next_line(fd);
			allocfreecraft(0, *line, 2);
			continue ;
		}
		i = 0;
		while ((*line)[i] == ' ' || (*line)[i] == '\t')
			i++;
		if (!identifiers(map_data, line, identifier, i))
			return (free(identifier), false);
		*line = get_next_line(fd);
		allocfreecraft(0, *line, 2);
		if (mark_identifiers(identifier))
			break ;
	}
	free(identifier);
	if (!*line)
		return (false);
	return (true);
}

static bool	get_we_ea_image(t_map_data *map_data, size_t i, size_t j)
{
	while (map_data->we_img[i] == ' ' || map_data->we_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->we_img[i]))
	{
		ft_putstr_fd("Error\nWE Image not found.\n", 2);
		return (false);
	}
	j = ft_strlen(map_data->we_img) - 1;
	while (map_data->we_img[j] == ' ' || map_data->we_img[j] == '\t')
		j--;
	map_data->we_img = ft_substr(map_data->we_img, i, j - i + 1);
	allocfreecraft(0, map_data->we_img, 2);
	i = 2;
	while (map_data->ea_img[i] == ' ' || map_data->ea_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->ea_img[i]))
	{
		ft_putstr_fd("Error\nEA Image not found.\n", 2);
		return (false);
	}
	j = ft_strlen(map_data->ea_img) - 1;
	while (map_data->ea_img[j] == ' ' || map_data->ea_img[j] == '\t')
		j--;
	map_data->ea_img = ft_substr(map_data->ea_img, i, j - i + 1);
	return (allocfreecraft(0, map_data->ea_img, 2), true);
}

static bool	get_name_images(t_map_data *map_data, size_t j)
{
	size_t	i;

	i = 2;
	while (map_data->no_img[i] == ' ' || map_data->no_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->no_img[i]))
		return (ft_putstr_fd("Error\nNO Image not found.\n", 2), 0);
	j = ft_strlen(map_data->no_img) - 1;
	while (map_data->no_img[j] == ' ' || map_data->no_img[j] == '\t')
		j--;
	map_data->no_img = ft_substr(map_data->no_img, i, j - i + 1);
	allocfreecraft(0, map_data->no_img, 2);
	i = 2;
	while (map_data->so_img[i] == ' ' || map_data->so_img[i] == '\t')
		i++;
	if (!ft_strlen(&map_data->so_img[i]))
		return (ft_putstr_fd("Error\nSO Image not found.\n", 2), 0);
	j = ft_strlen(map_data->so_img) - 1;
	while (map_data->so_img[j] == ' ' || map_data->so_img[j] == '\t')
		j--;
	map_data->so_img = ft_substr(map_data->so_img, i, j - i + 1);
	allocfreecraft(0, map_data->so_img, 2);
	if (!get_we_ea_image(map_data, 2, 0))
		return (false);
	return (true);
}

bool	get_identifiers(int fd, char **line, t_map_data *map_data)
{
	*line = get_next_line(fd);
	allocfreecraft(0, *line, 2);
	if (!identifiers_cub(map_data, 0, fd, line))
		return (ft_putstr_fd("Error\n", 2), false);
	if (!get_name_images(map_data, 0))
		return (false);
	if (!get_hexa_colors(map_data))
		return (false);
	return (true);
}
