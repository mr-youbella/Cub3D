#include "cub3d.h"

void	check_fleche_key(void *arg)
{
	t_player_map *player = (t_player_map *)arg;
	float	old_dir_x;
	float	old_plane_x;

	if (mlx_is_key_down(player->game->init, MLX_KEY_RIGHT))
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(0.05) - player->dir_y * sin(0.05);
		player->dir_y = old_dir_x * sin (0.05) + player->dir_y * cos(0.05);

		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(0.05) - player->plane_y * sin(0.05);
		player->plane_y = old_plane_x * sin(0.05) + player->plane_y * cos(0.05);
	}
	else if (mlx_is_key_down(player->game->init, MLX_KEY_LEFT))
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-0.05) - player->dir_y * sin(-0.05);
		player->dir_y = old_dir_x * sin (-0.05) + player->dir_y * cos(-0.05);

		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-0.05) - player->plane_y * sin(-0.05);
		player->plane_y = old_plane_x * sin(-0.05) + player->plane_y * cos(-0.05);
	}
	update(player->game, player);
}
