/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:32:07 by youbella          #+#    #+#             */
/*   Updated: 2025/09/11 07:03:57 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	image_wall(t_game *game, t_data *data, t_walls *walls, short is_door)
{
	mlx_texture_t	*texture;
	float			wall_x;
	int				d;
	int				tex_y;
	int				index;
	int				tex_x;
	size_t			color;
	size_t			r;
	size_t			g;
	size_t			b;
	size_t			a;

	if (is_door)
		texture = data->door->door;
	else if (walls->side == 0)
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
	if (walls->side == 0)
		wall_x = data->pos_y + walls->perp_w_dist * walls->ray_dir_y;
	else
		wall_x = data->pos_x + walls->perp_w_dist * walls->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)texture->width);
	if ((walls->side == 0 && walls->ray_dir_x > 0)
		|| (walls->side == 1 && walls->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	while (walls->start < walls->draw_end)
	{
		d = (walls->start * 256 - HEIGHT * 128 + walls->l_height * 128);
		tex_y = ((d * texture->height) / walls->l_height) / 256;
		index = (tex_y * texture->width + tex_x) * 4;
		r = texture->pixels[index + 0];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		color = (r << 24) | (g << 16) | (b << 8) | a;
		mlx_put_pixel(game->img, walls->columns, walls->start, color);
		walls->start++;
	}
}
