/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dragon_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:59:06 by youbella          #+#    #+#             */
/*   Updated: 2025/09/11 13:25:00 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	move_dragon(t_data *data)
{
	if (mlx_is_key_down(data->game->init, MLX_KEY_UP))
	{
		if (data->dragons->height_dragon < 200)
			data->dragons->height_dragon += 5;
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_DOWN))
	{
		if (data->dragons->height_dragon > -10)
			data->dragons->height_dragon -= 5;
	}
}

static void	put_pixels_dragons(t_game *game, t_dragons *dragons,
							mlx_texture_t *frame_dragon, size_t color)
{
	int		dy;
	int		dx;
	int		draw_x;
	int		draw_y;

	dy = 0;
	while (dy < 2)
	{
		dx = 0;
		while (dx < 2)
		{
			draw_x = (WIDTH / 2 + 400 - frame_dragon->width / 2 + dragons->x)
				* 2 + dx;
			draw_y
				= (HEIGHT / 2 - dragons->height_dragon
					- frame_dragon->height + dragons->y) * 2 + dy;
			mlx_put_pixel(game->img, draw_x, draw_y, color);
			dx++;
		}
		dy++;
	}
}

static void	get_pixels_dragons(t_game *game, t_dragons *dragons,
							mlx_texture_t *frame_dragon, size_t color)
{
	int		index;
	size_t	r;
	size_t	g;
	size_t	b;
	size_t	a;

	dragons->x = 0;
	while (dragons->x < (int)frame_dragon->width)
	{
		index = (dragons->y * frame_dragon->width + dragons->x) * 4;
		r = frame_dragon->pixels[index + 0];
		g = frame_dragon->pixels[index + 1];
		b = frame_dragon->pixels[index + 2];
		a = frame_dragon->pixels[index + 3];
		if (a > 0)
		{
			color = (r << 24) | (g << 16) | (b << 8) | a;
			put_pixels_dragons(game, dragons, frame_dragon, color);
		}
		dragons->x++;
	}
}

void	draw_dragons(t_game *game, t_dragons *dragons, t_knife *knife)
{
	mlx_texture_t	*frame_dragon;

	draw_hand_knife(game, knife);
	dragons->y = 0;
	dragons->frame_counter++;
	if (dragons->frame_counter >= dragons->frame_speed)
	{
		dragons->frame_counter = 0;
		dragons->current_frame = (dragons->current_frame + 1) % 3;
	}
	if (dragons->current_frame == 0)
		frame_dragon = dragons->dragon1;
	else if (dragons->current_frame == 1)
		frame_dragon = dragons->dragon2;
	else
		frame_dragon = dragons->dragon3;
	while (dragons->y < (int)frame_dragon->height)
	{
		get_pixels_dragons(game, dragons, frame_dragon, 0);
		dragons->y++;
	}
}
