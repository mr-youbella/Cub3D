#include "cub3d_bonus.h"

void	update(t_game *game, t_data *data)
{
	int columns = 0;
	float camera_x;
	float ray_dir_x;
	float ray_dir_y;
	int map_x;
	int map_y;
	short step_x, step_y;
	float side_dist_x, side_dist_y;
	float delta_dist_x, delta_dist_y;
	int mur;
	short side;

	while (columns < WIDTH)
	{
		int y = 0;
		while (y < HEIGHT / 2)
			mlx_put_pixel(game->img, columns, y++, data->map_data->c_color);

		while (y < HEIGHT)
			mlx_put_pixel(game->img, columns, y++, data->map_data->f_color);
		columns++;
	}
	columns = 0;
	while (columns < WIDTH)
	{
		map_x = (int)data->pos_x;
		map_y = (int)data->pos_y;
		side = -1;
		mur = 48;
		camera_x = 2 * ((double)columns / WIDTH) - 1;
		ray_dir_x = data->dir_x + (data->plane_x * camera_x);
		ray_dir_y = data->dir_y + (data->plane_y * camera_x);
		if (ray_dir_x)
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y)
			delta_dist_y = fabs(1 / ray_dir_y);
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1 - data->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1 - data->pos_y) * delta_dist_y;
		}
		while (mur == 48)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (data->map_data->map[map_y][map_x] == '1')
				mur = 49;
			else if (data->map_data->map[map_y][map_x] == 'D')
			{
				data->walls->side = side;
				data->walls->step_x = step_x;
				data->walls->step_y = step_y;
				data->walls->map_x = map_x;
				data->walls->map_y = map_y;
				data->walls->columns = columns;
				data->walls->ray_dir_x = ray_dir_x;
				data->walls->ray_dir_y = ray_dir_y;
				image_wall(game, data, data->walls, 1);
			}
		}
		data->walls->side = side;
		data->walls->step_x = step_x;
		data->walls->step_y = step_y;
		data->walls->map_x = map_x;
		data->walls->map_y = map_y;
		data->walls->columns = columns;
		data->walls->ray_dir_x = ray_dir_x;
		data->walls->ray_dir_y = ray_dir_y;
		image_wall(game, data, data->walls, 0);
		columns++;
	}
}
