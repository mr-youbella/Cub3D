#include "cub3d_bonus.h"

void check_key_moves(void *arg)
{
	t_data *data = (t_data *)arg;
	float new_pos_x;
	float new_pos_y;

	if (mlx_is_key_down(data->game->init, MLX_KEY_W))
	{
		new_pos_x = data->pos_x + (data->dir_x * 0.05);
		new_pos_y = data->pos_y + (data->dir_y * 0.05);
		
		if (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			data->pos_x = new_pos_x;

		if (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			data->pos_y = new_pos_y;
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_S))
	{
		new_pos_x = data->pos_x - (data->dir_x * 0.05);
		new_pos_y = data->pos_y - (data->dir_y * 0.05);
	
		if (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			data->pos_x = new_pos_x;

		if (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			data->pos_y = new_pos_y;
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_A))
	{
		new_pos_x = data->pos_x - (data->plane_x * 0.05);
		new_pos_y = data->pos_y - (data->plane_y * 0.05);

		if (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1'&&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			data->pos_x = new_pos_x;

		if (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1'&&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			data->pos_y = new_pos_y;
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_D))
	{
		new_pos_x = data->pos_x + (data->plane_x * 0.05);
		new_pos_y = data->pos_y + (data->plane_y * 0.05);

		if (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			data->pos_x = new_pos_x;

		if (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			data->pos_y = new_pos_y;
	}
	update(data->game, data);
}
