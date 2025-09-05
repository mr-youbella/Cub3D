#include "cub3d.h"

void update(t_game *game, t_player_map *player)
{
	int columns = 0;
	int width = 1536;
	int height = 960;
	float camera_x;
	float ray_dir_x;
	float ray_dir_y;
	int map_x;
	int map_y;
	int step_x, step_y;
	float side_dist_x, side_dist_y;
	float delta_dist_x, delta_dist_y;
	int mur;
	int side;
	int l_height;
	float perp_w_dist;
	float draw_start, draw_end;
	int start;
	int color;
	

	while (columns < width)
	{
		int y = 0;
		while (y < height / 2)
			mlx_put_pixel(game->img, columns, y++, 0x233d3c);

		while (y < height)
			mlx_put_pixel(game->img, columns, y++, 0x000000FF);
		columns++;
	}
	columns = 0;
	while (columns < width)
	{
		map_x = (int)player->pos_x;
		map_y = (int)player->pos_y;
		side = -1;
		mur = 48;
		camera_x = 2 * ((double)columns / width) - 1;
		ray_dir_x = player->dir_x + (player->plane_x * camera_x);
		ray_dir_y = player->dir_y + (player->plane_y * camera_x);
		if (ray_dir_x)
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y)
			delta_dist_y = fabs(1 / ray_dir_y);
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (player->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1 - player->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (player->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1 - player->pos_y) * delta_dist_y;
		}
		while (mur == 48)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
				color = 0x800080FF;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
				color = 0xFF69B4FF;
			}
			if (player->map[map_y][map_x] == '1')
				mur = 49;
		}
		if (side == 0 && ray_dir_x != 0)
			perp_w_dist = (map_x - player->pos_x + (1 - step_x) / 2) / ray_dir_x;
		else if (side == 1 && ray_dir_y != 0)
			perp_w_dist = (map_y - player->pos_y + (1 - step_y) / 2) / ray_dir_y;
		l_height = (int)(height / perp_w_dist);
		draw_start = -l_height / 2 + height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = (l_height / 2) + (height / 2);
		if (draw_end >= height)
			draw_end = height - 1;
		start = draw_start;
		while (start < draw_end)
		{
			mlx_put_pixel(game->img, columns, start, color);
			start++;
		}
		columns++;
	}
	player->pos_x += game->x;
	player->pos_y += game->y;
}
