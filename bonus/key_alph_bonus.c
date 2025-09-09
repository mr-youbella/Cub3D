#include "cub3d_bonus.h"

void	key_door(t_data *data)
{
	float	x;
	float	y;

	if (mlx_is_key_down(data->game->init, MLX_KEY_O))
	{
		if (data->map_data->map[(int)(data->pos_y - 1)][(int)(data->pos_x)] == 'D')
		{
			data->map_data->map[(int)(data->pos_y - 1)][(int)(data->pos_x)] = 'O';
			data->door->pos_y = data->pos_y - 1;
			data->door->pos_x = data->pos_x;
		}
		else if (data->map_data->map[(int)(data->pos_y + 1)][(int)(data->pos_x)] == 'D')
		{
			data->map_data->map[(int)(data->pos_y + 1)][(int)(data->pos_x)] = 'O';
			data->door->pos_y = data->pos_y + 1;
			data->door->pos_x = data->pos_x;
		}
		else if (data->map_data->map[(int)(data->pos_y)][(int)(data->pos_x - 1)] == 'D')
		{
			data->map_data->map[(int)(data->pos_y)][(int)(data->pos_x - 1)] = 'O';
			data->door->pos_y = data->pos_y;
			data->door->pos_x = data->pos_x - 1;
		}
		else if (data->map_data->map[(int)(data->pos_y)][(int)(data->pos_x + 1)] == 'D')
		{
			data->map_data->map[(int)(data->pos_y)][(int)(data->pos_x + 1)] = 'O';
			data->door->pos_y = data->pos_y;
			data->door->pos_x = data->pos_x + 1;
		}
		data->door->is_open = 1;
	}
	if (data->door->is_open)
	{
	    x = data->pos_x - data->door->pos_x;
	    y = data->pos_y - data->door->pos_y;
	    if (x * x + y * y > 4) 
	    {
	        data->map_data->map[(int)data->door->pos_y][(int)data->door->pos_x] = 'D';
	        data->door->is_open = 0;
	    }
	}
}

void check_key_moves(void *arg)
{
	t_data *data = (t_data *)arg;
	float new_pos_x;
	float new_pos_y;

	if (mlx_is_key_down(data->game->init, MLX_KEY_W))
	{
		new_pos_x = data->pos_x + (data->dir_x * 0.05);
		new_pos_y = data->pos_y + (data->dir_y * 0.05);
		
		if ((data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			&& (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != 'D' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != 'D'))
			data->pos_x = new_pos_x;

		if ((data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			&& (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != 'D' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != 'D' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != 'D'))
			data->pos_y = new_pos_y;
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_S))
	{
		new_pos_x = data->pos_x - (data->dir_x * 0.05);
		new_pos_y = data->pos_y - (data->dir_y * 0.05);
	
		if ((data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			&& (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != 'D' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != 'D'))
			data->pos_x = new_pos_x;

		if ((data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			&& (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != 'D' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != 'D' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != 'D'))
			data->pos_y = new_pos_y;
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_A))
	{
		new_pos_x = data->pos_x - (data->plane_x * 0.05);
		new_pos_y = data->pos_y - (data->plane_y * 0.05);

		if ((data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1'&&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			&& (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != 'D' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != 'D'))
			data->pos_x = new_pos_x;

		if ((data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1'&&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			&& (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != 'D' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != 'D'&&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != 'D'))
			data->pos_y = new_pos_y;
	}
	else if (mlx_is_key_down(data->game->init, MLX_KEY_D))
	{
		new_pos_x = data->pos_x + (data->plane_x * 0.05);
		new_pos_y = data->pos_y + (data->plane_y * 0.05);

		if ((data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != '1' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != '1' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != '1')
			&& (data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y)][(int)(new_pos_x - 0.15)] != 'D' &&
			data->map_data->map[(int)(data->pos_y + 0.15)][(int)(new_pos_x)] != 'D' &&
			data->map_data->map[(int)(data->pos_y - 0.15)][(int)(new_pos_x)] != 'D'))
			data->pos_x = new_pos_x;

		if ((data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != '1' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != '1')
			&& (data->map_data->map[(int)(new_pos_y + 0.15)][(int)(data->pos_x)] != 'D' &&
			data->map_data->map[(int)(new_pos_y - 0.15)][(int)(data->pos_x)] != 'D' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x + 0.15)] != 'D' &&
			data->map_data->map[(int)(new_pos_y)][(int)(data->pos_x - 0.15)] != 'D'))
			data->pos_y = new_pos_y;
	}
	key_door(data);
	update(data->game, data);
}
