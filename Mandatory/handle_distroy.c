/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_distroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:31:21 by wkannouf          #+#    #+#             */
/*   Updated: 2025/09/11 12:14:28 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	if (mlx_is_key_down(game->init, MLX_KEY_ESCAPE))
	{
		printf ("THANK YOU FOR PLAYING IN OUR GAME :)");
		mlx_close_window(game->init);
	}
}

void	close_window(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	printf ("THANK YOU FOR PLAYING IN OUR GAME :)");
	mlx_close_window(game->init);
}
