/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:02 by youbella          #+#    #+#             */
/*   Updated: 2025/10/05 18:44:55 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_s(t_data *data)
{
	free(data->game);
	free(data->walls);
	free(data->donneee);
	free(data);
}

static t_data	*alloc_struct2(void)
{
	t_game		*game;
	t_walls		*walls;
	t_data		*data;
	t_donneee	*donneee;

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
	donneee = malloc(sizeof(t_donneee));
	if (!donneee)
		return (free(data), free(game), free(walls), NULL);
	ft_memset(donneee, 0, sizeof(t_donneee));
	data->game = game;
	data->walls = walls;
	data->donneee = donneee;
	return (data);
}

t_data	*alloc_struct(t_door *door, t_dragons *dragons, t_knife *knife)
{
	t_data	*data;

	data = alloc_struct2();
	if (!data)
		return (NULL);
	door = malloc(sizeof(t_door));
	if (!door)
		return (free_s(data), NULL);
	ft_memset(door, 0, sizeof(t_door));
	dragons = malloc(sizeof(t_dragons));
	if (!dragons)
		return (free_s(data), free(door), NULL);
	ft_memset(dragons, 0, sizeof(t_dragons));
	knife = malloc(sizeof(t_knife));
	if (!knife)
		return (free_s(data), free(door), free(dragons), NULL);
	ft_memset(knife, 0, sizeof(t_knife));
	data->door = door;
	data->dragons = dragons;
	data->knife = knife;
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

void	free_leaks(t_data *data, bool is_mlx)
{
	delete_texture(data);
	if (is_mlx)
	{
		mlx_delete_image(data->game->init, data->game->img);
		mlx_terminate(data->game->init);
	}
	free(data->game);
	free(data->walls);
	free(data->donneee);
	free(data->door);
	free(data->map_data);
	free(data->dragons);
	free(data->knife);
	free(data);
}
