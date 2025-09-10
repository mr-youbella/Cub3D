#include "cub3d_bonus.h"

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
	data->dragons->frame_counter++;
	if (data->dragons->frame_counter >= data->dragons->frame_speed)
	{
	    data->dragons->frame_counter = 0;
	    data->dragons->current_frame = (data->dragons->current_frame + 1) % 3;
	}
	draw_dragons(game, data->dragons);
}
