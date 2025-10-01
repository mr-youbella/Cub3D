/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:02 by youbella          #+#    #+#             */
/*   Updated: 2025/10/02 00:23:47 by youbella         ###   ########.fr       */
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

static void	delete_texture(t_data *data)
{
	if (data->walls->no_img)
		mlx_delete_texture(data->walls->no_img);
	if (data->walls->so_img)
		mlx_delete_texture(data->walls->so_img);
	if (data->walls->we_img)
		mlx_delete_texture(data->walls->we_img);
	if (data->walls->ea_img)
		mlx_delete_texture(data->walls->ea_img);
	if (data->door->door)
		mlx_delete_texture(data->door->door);
	if (data->dragons->dragon1)
		mlx_delete_texture(data->dragons->dragon1);
	if (data->dragons->dragon2)
		mlx_delete_texture(data->dragons->dragon2);
	if (data->dragons->dragon3)
		mlx_delete_texture(data->dragons->dragon3);
	if (data->knife->hand_knife)
		mlx_delete_texture(data->knife->hand_knife);
	if (data->knife->hand)
		mlx_delete_texture(data->knife->hand);
}

void	free_leaks(t_data *data)
{
	delete_texture(data);
	mlx_delete_image(data->game->init, data->game->img);
	mlx_terminate(data->game->init);
	free(data->game);
	free(data->walls);
	free(data->donnee);
	free(data->door);
	free(data->map_data);
	free(data->dragons);
	free(data->knife);
	free(data);
}
