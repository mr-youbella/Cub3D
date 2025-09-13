/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_distroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:31:21 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/13 01:35:59 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	if (mlx_is_key_down(game->init, MLX_KEY_ESCAPE))
	{
		printf("\033[1;34mTHANK YOU FOR PLAYING IN OUR GAME :)\033[0m\n");
		mlx_close_window(game->init);
	}
}

void	close_window(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	printf("\033[1;34mTHANK YOU FOR PLAYING IN OUR GAME :)\033[0m\n");
	mlx_close_window(game->init);
}
