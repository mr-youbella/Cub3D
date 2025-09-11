#include "cub3d_bonus.h"

void	rotate_key(void *arg)
{
	t_data *data = (t_data *)arg;
	float	old_dir_x;
	float	old_plane_x;

	if (mlx_is_key_down(data->game->init, MLX_KEY_RIGHT))
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(0.05) - data->dir_y * sin(0.05);
		data->dir_y = old_dir_x * sin(0.05) + data->dir_y * cos(0.05);

		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(0.05) - data->plane_y * sin(0.05);
		data->plane_y = old_plane_x * sin(0.05) + data->plane_y * cos(0.05);
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_LEFT))
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-0.05) - data->dir_y * sin(-0.05);
		data->dir_y = old_dir_x * sin (-0.05) + data->dir_y * cos(-0.05);

		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-0.05) - data->plane_y * sin(-0.05);
		data->plane_y = old_plane_x * sin(-0.05) + data->plane_y * cos(-0.05);
	}
	update(data->game, data);
}
