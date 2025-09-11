/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:54:54 by youbella          #+#    #+#             */
/*   Updated: 2025/09/11 18:28:30 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_data	*alloc_struct2(void)
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
		return (NULL);
	ft_memset(game, 0, sizeof(t_game));
	walls = malloc(sizeof(t_walls));
	if (!walls)
		return (NULL);
	ft_memset(walls, 0, sizeof(t_walls));
	donnee = malloc(sizeof(t_donnee));
	if (!donnee)
		return (NULL);
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
		return (NULL);
	ft_memset(map_data, 0, sizeof(t_map_data));
	door = malloc(sizeof(t_door));
	if (!door)
		return (NULL);
	ft_memset(door, 0, sizeof(t_door));
	dragons = malloc(sizeof(t_dragons));
	if (!dragons)
		return (NULL);
	ft_memset(dragons, 0, sizeof(t_dragons));
	knife = malloc(sizeof(t_knife));
	if (!knife)
		return (NULL);
	ft_memset(knife, 0, sizeof(t_knife));
	1 && (data->map_data = map_data, data->door = door);
	1 && (data->dragons = dragons, data->knife = knife);
	return (data);
}

short	set_images_walls(t_data *data)
{
	data->walls->no_img = mlx_load_png(data->map_data->no_img);
	if (!data->walls->no_img)
		return (0);
	data->walls->so_img = mlx_load_png(data->map_data->so_img);
	if (!data->walls->so_img)
		return (0);
	data->walls->we_img = mlx_load_png(data->map_data->we_img);
	if (!data->walls->we_img)
		return (0);
	data->walls->ea_img = mlx_load_png(data->map_data->ea_img);
	if (!data->walls->ea_img)
		return (0);
	return (1);
}

short	set_images(t_data *data)
{
	if (!set_images_walls(data))
		return (0);
	data->door->door = mlx_load_png("door.png");
	if (!data->door->door)
		return (0);
	data->dragons->dragon1 = mlx_load_png("dragon1.png");
	if (!data->dragons->dragon1)
		return (0);
	data->dragons->dragon2 = mlx_load_png("dragon2.png");
	if (!data->dragons->dragon2)
		return (0);
	data->dragons->dragon3 = mlx_load_png("dragon3.png");
	if (!data->dragons->dragon3)
		return (0);
	data->knife->hand_knife = mlx_load_png("hand_with_knife.png");
	if (!data->knife->hand_knife)
		return (0);
	data->knife->hand = mlx_load_png("hand_without_knife.png");
	if (!data->knife->hand)
		return (0);
	return (1);
}

void	mlx(t_data *data)
{
	mlx_loop_hook(data->game->init, rotate_key, data);
	mlx_loop_hook(data->game->init, check_key_moves, data);
	mlx_mouse_hook(data->game->init, key_knife, data);
	mlx_loop_hook(data->game->init, rotate_mouse, data);
	mlx_set_cursor_mode(data->game->init, MLX_MOUSE_DISABLED);
	mlx_loop_hook(data->game->init, destroy, data->game);
	mlx_close_hook(data->game->init, close_window, data->game);
	mlx_loop(data->game->init);
	mlx_terminate(data->game->init);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		return (1);
	data = alloc_struct(NULL, NULL, NULL);
	if (!data)
		return (1);
	data->game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", true);
	if (!data->game->init)
		return (1);
	data->game->img = mlx_new_image(data->game->init, WIDTH, HEIGHT);
	mlx_image_to_window(data->game->init, data->game->img, 0, 0);
	data->map_data = ft_map_data(argv[1]);
	if (!data->map_data)
		return (1);
	player_position(data);
	if (!set_images(data))
		return (1);
	data->dragons->frame_speed = 20;
	data->dragons->height_dragon = 100;
	update(data);
	mlx(data);
}
