/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dragon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:59:06 by youbella          #+#    #+#             */
/*   Updated: 2025/09/11 00:27:03 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void draw_dragons(t_game *game, t_dragons *dragons)
{
    mlx_texture_t *frame;

    frame = mlx_load_png("knife.png");
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
                int draw_x = (WIDTH /2 + 400 - frame->width / 2 + x);
                int draw_y = (HEIGHT / 2 - 100 - frame->height + y);
                mlx_put_pixel(game->img, draw_x, draw_y, color);
            }
        }
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
                        int draw_y = (HEIGHT / 2 - 100 - frame->height + y) * 2 + dy;
                        mlx_put_pixel(game->img, draw_x, draw_y, color);
                    }
                }
            }
        }
    }
}
