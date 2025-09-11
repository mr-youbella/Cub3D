/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dragon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:59:06 by youbella          #+#    #+#             */
/*   Updated: 2025/09/11 02:58:32 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void draw_dragons(t_game *game, t_dragons *dragons)
{
    mlx_texture_t *frame;

    if (!dragons->key_knife)
        frame = dragons->hand_knife;
    else
        frame = dragons->hand;
    for (int y = 0; y < (int)frame->height; y++)
    {
        for (int x = 0; x < (int)frame->width; x++)
        {
            int index = (y * frame->width + x) * 4;
            size_t r = frame->pixels[index + 0];
            size_t g = frame->pixels[index + 1];
            size_t b = frame->pixels[index + 2];
            size_t a = frame->pixels[index + 3];

            if (a > 0)
            {
                size_t color = (r << 24) | (g << 16) | (b << 8) | a;
                for (int dy = 0; dy < 2; dy++)
                {
                    for (int dx = 0; dx < 2; dx++)
                    {
                        int draw_x = (WIDTH / 2 + x) * 1.5 + dx;
                        int draw_y = (HEIGHT / 2 - 50 + y) * 1.5 + dy;
                        mlx_put_pixel(game->img, draw_x, draw_y, color);
                    }
                }
            }
        }
    }
    
    dragons->frame_counter++;
	if (dragons->frame_counter >= dragons->frame_speed)
	{
	    dragons->frame_counter = 0;
	    dragons->current_frame = (dragons->current_frame + 1) % 3;
	}

    if (dragons->current_frame == 0)
        frame = dragons->dragon1;
    else if (dragons->current_frame == 1)
        frame = dragons->dragon2;
    else
        frame = dragons->dragon3;

    for (int y = 0; y < (int)frame->height; y++)
    {
        for (int x = 0; x < (int)frame->width; x++)
        {
            int index = (y * frame->width + x) * 4;
            size_t r = frame->pixels[index + 0];
            size_t g = frame->pixels[index + 1];
            size_t b = frame->pixels[index + 2];
            size_t a = frame->pixels[index + 3];

            if (a > 0)
            {
                size_t color = (r << 24) | (g << 16) | (b << 8) | a;
                for (int dy = 0; dy < 2; dy++)
                {
                    for (int dx = 0; dx < 2; dx++)
                    {
                        int draw_x = (WIDTH /2 + 400 - frame->width / 2 + x) * 2 + dx;
                        int draw_y = (HEIGHT / 2 - dragons->move_dragon - frame->height + y) * 2 + dy;
                        mlx_put_pixel(game->img, draw_x, draw_y, color);
                    }
                }
            }
        }
    }
}
