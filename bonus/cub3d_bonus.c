/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:54:54 by youbella          #+#    #+#             */
/*   Updated: 2025/09/13 05:39:30 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_leaks(t_data *data)
{
	free(data->game);
	free(data->walls);
	free(data->donnee);
	free(data->door);
	free(data->map_data);
	free(data->dragons);
	free(data->knife);
	free(data);
}

static short	set_images_walls(t_data *data)
{
	data->walls->no_img = mlx_load_png(data->map_data->no_img);
	if (!data->walls->no_img)
		return (ft_putstr_fd("Error\nImage no_img not found\n", 2), 0);
	data->walls->so_img = mlx_load_png(data->map_data->so_img);
	if (!data->walls->so_img)
		return (ft_putstr_fd("Error\nImage so_img not found\n", 2), 0);
	data->walls->we_img = mlx_load_png(data->map_data->we_img);
	if (!data->walls->we_img)
		return (ft_putstr_fd("Error\nImage we_img not found\n", 2), 0);
	data->walls->ea_img = mlx_load_png(data->map_data->ea_img);
	if (!data->walls->ea_img)
		return (ft_putstr_fd("Error\nImage ea_img not found\n", 2), 0);
	return (1);
}

static short	set_images(t_data *data)
{
	if (!set_images_walls(data))
		return (0);
	data->door->door = mlx_load_png("bonus/youbella/img_bonus/door.png");
	if (!data->door->door)
		return (ft_putstr_fd("Error\nImage door not found\n", 2), 0);
	data->dragons->dragon1
		= mlx_load_png("bonus/youbella/img_bonus/dragon1.png");
	if (!data->dragons->dragon1)
		return (ft_putstr_fd("Error\nImage dragon1 not found\n", 2), 0);
	data->dragons->dragon2
		= mlx_load_png("bonus/youbella/img_bonus/dragon2.png");
	if (!data->dragons->dragon2)
		return (ft_putstr_fd("Error\nImage dragon2 not found\n", 2), 0);
	data->dragons->dragon3
		= mlx_load_png("bonus/youbella/img_bonus/dragon3.png");
	if (!data->dragons->dragon3)
		return (ft_putstr_fd("Error\nImage dragon3 not found\n", 2), 0);
	data->knife->hand_knife
		= mlx_load_png("bonus/youbella/img_bonus/hand_with_knife.png");
	if (!data->knife->hand_knife)
		return (ft_putstr_fd("Error\nImage hand_with_knife not found\n", 2), 0);
	data->knife->hand = mlx_load_png("bonus/youbella/img_bonus/hand.png");
	if (!data->knife->hand)
		return (ft_putstr_fd("Error\nImage hand not found\n", 2), 0);
	return (1);
}

static void	mlx(t_data *data)
{
	mlx_loop_hook(data->game->init, rotate_key, data);
	mlx_loop_hook(data->game->init, check_key_moves, data);
	mlx_mouse_hook(data->game->init, key_knife, data);
	mlx_loop_hook(data->game->init, rotate_mouse, data);
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
	data->game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", false);
	if (!data->game->init)
		return (free_leaks(data), 1);
	data->game->img = mlx_new_image(data->game->init, WIDTH, HEIGHT);
	mlx_image_to_window(data->game->init, data->game->img, 0, 0);
	data->map_data = ft_map_data(argv[1]);
	if (!data->map_data)
		return (free_leaks(data), 1);
	player_position(data);
	if (!set_images(data))
		return (free_leaks(data), 1);
	data->dragons->frame_speed = 20;
	data->dragons->height_dragon = 100;
	update(data, 0);
	mlx(data);
	free_leaks(data);
}
