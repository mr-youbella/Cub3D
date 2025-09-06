/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:32:07 by youbella          #+#    #+#             */
/*   Updated: 2025/09/06 17:26:26 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_wall(t_game *game, t_player_map *player, t_walls *walls)
{
	mlx_texture_t	*texture;
	float			perp_w_dist;
	float			draw_start;
	float			draw_end;
	float			wall_x;
	int				l_height;
	int				start;
	int				d;
	int				tex_y;
	int				index;
	int				tex_x;
	size_t			color;
	size_t			r;
	size_t			g;
	size_t			b;
	size_t			a;

	perp_w_dist = 0;
	if (walls->side == 0)
	{
		if (walls->step_x == -1)
			texture = walls->ea_img;
		else
			texture = walls->we_img;
	}
	else
	{
		if (walls->step_y == -1)
			texture = walls->no_img;
		else
			texture = walls->so_img;
	}
	if (walls->side == 0 && walls->ray_dir_x != 0)
		perp_w_dist = (walls->map_x - player->pos_x
				+ (1 - walls->step_x) / 2) / walls->ray_dir_x;
	else if (walls->side == 1 && walls->ray_dir_y != 0)
		perp_w_dist = (walls->map_y - player->pos_y
				+ (1 - walls->step_y) / 2) / walls->ray_dir_y;
	l_height = (int)(HEIGHT / perp_w_dist);
	draw_start = -l_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (l_height / 2) + (HEIGHT / 2);
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	start = draw_start;
	if (walls->side == 0)
		wall_x = player->pos_y + perp_w_dist * walls->ray_dir_y;
	else
		wall_x = player->pos_x + perp_w_dist * walls->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)texture->width);
	if ((walls->side == 0 && walls->ray_dir_x > 0)
		|| (walls->side == 1 && walls->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	while (start < draw_end)
	{
		d = (start * 256 - HEIGHT * 128 + l_height * 128);
		tex_y = ((d * texture->height) / l_height) / 256;
		index = (tex_y * texture->width + tex_x) * 4;
		r = texture->pixels[index + 0];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		color = (r << 24) | (g << 16) | (b << 8) | a;
		mlx_put_pixel(game->img, walls->columns, start, color);
		start++;
	}
}
