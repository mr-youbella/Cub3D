#include "cub3d.h"

void update(t_game *game, t_player_map *player)
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
			mlx_put_pixel(game->img, columns, y++, 0x233d3c);

		while (y < HEIGHT)
			mlx_put_pixel(game->img, columns, y++, 0x000000FF);
		columns++;
	}
	columns = 0;
	while (columns < WIDTH)
	{
		map_x = (int)player->pos_x;
		map_y = (int)player->pos_y;
		side = -1;
		mur = 48;
		camera_x = 2 * ((double)columns / WIDTH) - 1;
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
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (player->map[map_y][map_x] == '1')
				mur = 49;
		}
		player->walls->side = side;
		player->walls->step_x = step_x;
		player->walls->step_y = step_y;
		player->walls->map_x = map_x;
		player->walls->map_y = map_y;
		player->walls->columns = columns;
		player->walls->ray_dir_x = ray_dir_x;
		player->walls->ray_dir_y = ray_dir_y;
		image_wall(game, player, player->walls);
		columns++;
	}
	player->pos_x += game->x;
	player->pos_y += game->y;
}
