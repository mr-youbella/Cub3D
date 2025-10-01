/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:29:17 by youbella          #+#    #+#             */
/*   Updated: 2025/10/02 00:22:31 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_leaks(t_data *data, bool is_all)
{
	if (is_all)
	{
		mlx_delete_texture(data->walls->no_img);
		mlx_delete_texture(data->walls->so_img);
		mlx_delete_texture(data->walls->ea_img);
		mlx_delete_texture(data->walls->we_img);
		mlx_delete_image(data->game->init, data->game->img);
		mlx_terminate(data->game->init);
	}
	free(data->game);
	free(data->walls);
	free(data->map_data);
	free(data->donne);
	free(data);
}

static t_data	*alloc_struct(void)
{
	t_game		*game;
	t_walls		*walls;
	t_data		*data;
	t_donnee	*donnee;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	ft_memset(game, 0, sizeof(t_game));
	walls = malloc(sizeof(t_walls));
	if (!walls)
		return (free(game), NULL);
	ft_memset(walls, 0, sizeof(t_walls));
	donnee = malloc(sizeof(t_donnee));
	if (!donnee)
		return (free(game), free(walls), NULL);
	ft_memset(donnee, 0, sizeof(t_donnee));
	data = malloc(sizeof(t_data));
	if (!data)
		return (free(game), free(walls), free(donnee), NULL);
	ft_memset(data, 0, sizeof(t_data));
	data->game = game;
	data->walls = walls;
	data->donne = donnee;
	return (data);
}

static short	init_window(t_data *data)
{
	int	window;

	data->game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", false);
	if (!data->game->init)
		return (0);
	data->game->img = mlx_new_image(data->game->init, WIDTH, HEIGHT);
	if (!data->game->img)
		return (0);
	window = mlx_image_to_window(data->game->init, data->game->img, 0, 0);
	if (window == -1)
		return (0);
	return (1);
}

static short	set_image(t_data *data, t_map_data *map_data)
{
	data->walls->no_img = mlx_load_png(map_data->no_img);
	if (!data->walls->no_img)
		return (ft_putstr_fd("Error\nImage no_img not found\n", 2), 0);
	data->walls->so_img = mlx_load_png(map_data->so_img);
	if (!data->walls->so_img)
	{
		mlx_delete_texture(data->walls->no_img);
		return (ft_putstr_fd("Error\nImage so_img not found\n", 2), 0);
	}
	data->walls->we_img = mlx_load_png(map_data->we_img);
	if (!data->walls->we_img)
	{
		mlx_delete_texture(data->walls->no_img);
		mlx_delete_texture(data->walls->so_img);
		return (ft_putstr_fd("Error\nImage we_img not found\n", 2), 0);
	}
	data->walls->ea_img = mlx_load_png(map_data->ea_img);
	if (!data->walls->ea_img)
	{
		mlx_delete_texture(data->walls->no_img);
		mlx_delete_texture(data->walls->so_img);
		mlx_delete_texture(data->walls->we_img);
		return (ft_putstr_fd("Error\nImage ea_img not found\n", 2), 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map_data	*map_data;
	t_data		*data;

	if (argc != 2)
		return (1);
	data = alloc_struct();
	if (!data)
		return (1);
	map_data = ft_map_data(argv[1]);
	if (!map_data)
		return (data->map_data = NULL, free_leaks(data, 0), 1);
	data->map_data = map_data;
	player_position(data);
	if (!set_image(data, map_data))
		return (free_leaks(data, 0), 1);
	if (!init_window(data))
		return (free_leaks(data, 1), 1);
	update(data);
	mlx_loop_hook(data->game->init, check_fleche_key, data);
	mlx_loop_hook(data->game->init, check_key_moves, data);
	mlx_loop_hook(data->game->init, destroy, data->game);
	mlx_close_hook(data->game->init, close_window, data->game);
	mlx_loop(data->game->init);
	free_leaks(data, 1);
}
