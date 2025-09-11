/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:54:54 by youbella          #+#    #+#             */
/*   Updated: 2025/09/11 13:18:02 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	t_walls		*walls;
	t_data		*data;
	t_map_data	*map_data;
	t_door		*door;
	t_donnee	*donnee;
	t_dragons	*dragons;
	t_knife		*knife;

	if (argc != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	walls = malloc(sizeof(t_walls));
	if (!walls)
		return (1);
	ft_memset(walls, 0, sizeof(t_walls));
	donnee = malloc(sizeof(t_donnee));
	if (!donnee)
		return (1);
	ft_memset(donnee, 0, sizeof(t_donnee));
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	door = malloc(sizeof(t_door));
	if (!door)
		return (1);
	ft_memset(door, 0, sizeof(t_door));
	dragons = malloc(sizeof(t_dragons));
	if (!dragons)
		return (1);
	ft_memset(dragons, 0, sizeof(t_dragons));
	knife = malloc(sizeof(t_knife));
	if (!knife)
		return (1);
	ft_memset(knife, 0, sizeof(t_knife));
	game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", true);
	if (!game->init)
		return (1);
	game->img = mlx_new_image(game->init, WIDTH, HEIGHT);
	mlx_image_to_window(game->init, game->img, 0, 0);
	map_data = ft_map_data(argv[1]);
	if (!map_data)
		return (1);
	data->game = game;
	data->walls = walls;
	data->donnee = donnee;
	data->map_data = map_data;
	data->door = door;
	data->dragons = dragons;
	data->knife = knife;
	player_position(data);
	walls->no_img = mlx_load_png(map_data->no_img);
	if (!walls->no_img)
		return (1);
	walls->so_img = mlx_load_png(map_data->so_img);
	if (!walls->so_img)
		return (1);
	walls->we_img = mlx_load_png(map_data->we_img);
	if (!walls->we_img)
		return (1);
	walls->ea_img = mlx_load_png(map_data->ea_img);
	if (!walls->ea_img)
		return (1);
	door->door = mlx_load_png("door.png");
	if (!door->door)
		return (1);
	dragons->dragon1 = mlx_load_png("dragon1.png");
	if (!dragons->dragon1)
		return (1);
	dragons->dragon2 = mlx_load_png("dragon2.png");
	if (!dragons->dragon2)
		return (1);
	dragons->dragon3 = mlx_load_png("dragon3.png");
	if (!dragons->dragon3)
		return (1);
	knife->hand_knife = mlx_load_png("hand_with_knife.png");
	if (!knife->hand_knife)
		return (1);
	knife->hand = mlx_load_png("hand_without_knife.png");
	if (!knife->hand)
		return (1);
	dragons->frame_speed = 20;
	dragons->height_dragon = 100;
	update(game, data);
	mlx_loop_hook(game->init, rotate_key, data);
	mlx_loop_hook(game->init, check_key_moves, data);
	mlx_mouse_hook(game->init, key_knife, data);
	mlx_loop_hook(game->init, rotate_mouse, data);
	mlx_set_cursor_mode(game->init, MLX_MOUSE_DISABLED);
	mlx_loop_hook(game->init, destroy, game);
	mlx_close_hook(game->init, close_window, game);
	mlx_loop(game->init);
	mlx_terminate(game->init);
}
