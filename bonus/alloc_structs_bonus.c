/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_structs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:02 by youbella          #+#    #+#             */
/*   Updated: 2025/09/12 14:58:42 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_s(t_data *data)
{
	free(data->game);
	free(data->walls);
	free(data->donnee);
	free(data);
}

static t_data	*alloc_struct2(void)
{
	t_game		*game;
	t_walls		*walls;
	t_data		*data;
	t_donnee	*donnee;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(t_data));
	game = malloc(sizeof(t_game));
	if (!game)
		return (free(data), NULL);
	ft_memset(game, 0, sizeof(t_game));
	walls = malloc(sizeof(t_walls));
	if (!walls)
		return (free(data), free(game), NULL);
	ft_memset(walls, 0, sizeof(t_walls));
	donnee = malloc(sizeof(t_donnee));
	if (!donnee)
		return (free(data), free(game), free(walls), NULL);
	ft_memset(donnee, 0, sizeof(t_donnee));
	data->game = game;
	data->walls = walls;
	data->donnee = donnee;
	return (data);
}

t_data	*alloc_struct(t_door *door, t_dragons *dragons, t_knife *knife)
{
	t_data		*data;
	t_map_data	*map_data;

	data = alloc_struct2();
	if (!data)
		return (NULL);
	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
		return (free_s(data), NULL);
	ft_memset(map_data, 0, sizeof(t_map_data));
	door = malloc(sizeof(t_door));
	if (!door)
		return (free_s(data), free(map_data), NULL);
	ft_memset(door, 0, sizeof(t_door));
	dragons = malloc(sizeof(t_dragons));
	if (!dragons)
		return (free_s(data), free(map_data), free(door), NULL);
	ft_memset(dragons, 0, sizeof(t_dragons));
	knife = malloc(sizeof(t_knife));
	if (!knife)
		return (free_s(data), free(map_data), free(door), free(dragons), NULL);
	ft_memset(knife, 0, sizeof(t_knife));
	1 && (data->map_data = map_data, data->door = door);
	1 && (data->dragons = dragons, data->knife = knife);
	return (data);
}
