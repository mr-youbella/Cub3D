/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:49:49 by youbella          #+#    #+#             */
/*   Updated: 2025/09/06 17:05:01 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_map(char *path)
{
	char	**map;
	char	*join_line;
	char	*tmp;
	char	*line;
	int		fd;

	1 && (join_line = NULL, fd = open(path, O_RDONLY));
	if (fd == -1)
		return (ft_putstr_fd("Error: file not open!\n", 2), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "\n", 1))
			return (ft_putstr_fd("Error: Empty line!\n", 2),
				free(line), close(fd), NULL);
		1 && (tmp = join_line, join_line = ft_strjoin(join_line, line));
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	1 && (close(fd), map = ft_split(join_line, '\n'));
	free(join_line);
	if (!map)
		ft_putstr_fd("Map no found\n", 2);
	return (map);
}
