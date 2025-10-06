/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_knife_hand_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:33:47 by youbella          #+#    #+#             */
/*   Updated: 2025/10/06 16:26:20 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	put_pixels_hand_knife(t_knife *knife,
								t_game *game, int dy, size_t color)
{
	int	dx;

	dx = 0;
	while (dx < 2)
	{
		knife->draw_x = (WIDTH / 2 + knife->x) * 1.5 + dx;
		knife->draw_y = (HEIGHT / 2 - 50 + knife->y) * 1.5 + dy;
		mlx_put_pixel(game->img, knife->draw_x, knife->draw_y, color);
		dx++;
	}
}

static void	get_pixels_hand_knife(t_knife *knife,
								t_game *game, size_t color, int index)
{
	int		dy;
	size_t	r;
	size_t	g;
	size_t	b;
	size_t	a;

	dy = 0;
	index = (knife->y * knife->knife_hand->width + knife->x) * 4;
	r = knife->knife_hand->pixels[index + 0];
	g = knife->knife_hand->pixels[index + 1];
	b = knife->knife_hand->pixels[index + 2];
	a = knife->knife_hand->pixels[index + 3];
	if (a > 0)
	{
		color = (r << 24) | (g << 16) | (b << 8) | a;
		dy = 0;
		while (dy < 2)
		{
			put_pixels_hand_knife(knife, game, dy, color);
			dy++;
		}
	}
}

void	draw_hand_knife(t_game *game, t_knife *knife)
{
	knife->y = 0;
	if (!knife->key_knife)
		knife->knife_hand = knife->hand_knife;
	else
		knife->knife_hand = knife->hand;
	while (knife->y < (int)knife->knife_hand->height)
	{
		knife->x = 0;
		while (knife->x < (int)knife->knife_hand->width)
		{
			get_pixels_hand_knife(knife, game, 0, 0);
			knife->x++;
		}
		knife->y++;
	}
}
