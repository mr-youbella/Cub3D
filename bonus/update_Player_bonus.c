#include "cub3d_bonus.h"

void draw_knife(t_game *game, t_walls *walls)
{
    int x, y;
    for (y = 0; y < (int)walls->knife->height; y++)
    {
        for (x = 0; x < (int)walls->knife->width; x++)
        {
            int index = (y * walls->knife->width + x) * 4;
            size_t r = walls->knife->pixels[index + 0];
            size_t g = walls->knife->pixels[index + 1];
            size_t b = walls->knife->pixels[index + 2];
            size_t a = walls->knife->pixels[index + 3];

            if (a > 0)
            {
                size_t color = (r << 24) | (g << 16) | (b << 8) | a;
                mlx_put_pixel(game->img, WIDTH/2 - walls->knife->width/2 + x,
                                           HEIGHT - walls->knife->height + y,
                                           color);
            }
        }
    }
}

void	update(t_game *game, t_data *data)
{
	data->walls->columns = 0;
	float camera_x;
	float side_dist_x, side_dist_y;
	float delta_dist_x, delta_dist_y;
	int wall;

	while (data->walls->columns < WIDTH)
	{
		int y = 0;
		while (y < HEIGHT / 2)
			mlx_put_pixel(game->img, data->walls->columns, y++, data->map_data->c_color);

		while (y < HEIGHT)
			mlx_put_pixel(game->img, data->walls->columns, y++, data->map_data->f_color);
		data->walls->columns++;
	}
	data->walls->columns = 0;
	while (data->walls->columns < WIDTH)
	{
		data->walls->map_x = (int)data->pos_x;
		data->walls->map_y = (int)data->pos_y;
		data->walls->side = -1;
		wall = 48;
		camera_x = 2 * ((double)data->walls->columns / WIDTH) - 1;
		data->walls->ray_dir_x = data->dir_x + (data->plane_x * camera_x);
		data->walls->ray_dir_y = data->dir_y + (data->plane_y * camera_x);
		if (data->walls->ray_dir_x)
			delta_dist_x = fabs(1 / data->walls->ray_dir_x);
		if (data->walls->ray_dir_y)
			delta_dist_y = fabs(1 / data->walls->ray_dir_y);
		if (data->walls->ray_dir_x < 0)
		{
			data->walls->step_x = -1;
			side_dist_x = (data->pos_x - data->walls->map_x) * delta_dist_x;
		}
		else
		{
			data->walls->step_x = 1;
			side_dist_x = (data->walls->map_x + 1 - data->pos_x) * delta_dist_x;
		}
		if (data->walls->ray_dir_y < 0)
		{
			data->walls->step_y = -1;
			side_dist_y = (data->pos_y - data->walls->map_y) * delta_dist_y;
		}
		else
		{
			data->walls->step_y = 1;
			side_dist_y = (data->walls->map_y + 1 - data->pos_y) * delta_dist_y;
		}
		while (wall == 48)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				data->walls->map_x += data->walls->step_x;
				data->walls->side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				data->walls->map_y += data->walls->step_y;
				data->walls->side = 1;
			}
			if (data->map_data->map[data->walls->map_y][data->walls->map_x] == '1')
				wall = 49;
			else if (data->map_data->map[data->walls->map_y][data->walls->map_x] == 'D')
				wall = 'D';
		}
		if (wall == 49)
			image_wall(game, data, data->walls, 0);
		else if (wall == 'D')
			image_wall(game, data, data->walls, 1);
		data->walls->columns++;
	}
	draw_knife(game, data->walls);
}
