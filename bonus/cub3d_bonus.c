/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:54:54 by youbella          #+#    #+#             */
/*   Updated: 2025/09/12 13:44:14 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static short	set_images_walls(t_data *data)
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

static short	set_images(t_data *data)
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

static void	mlx(t_data *data)
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
