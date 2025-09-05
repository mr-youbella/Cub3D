#include "cub3d.h"

void	check_fleche_key(void *arg)
{
	t_player_map *player = (t_player_map *)arg;
	
	if (mlx_is_key_down(player->game->init, MLX_KEY_RIGHT))
	{
		player->dir_x = player->dir_x * cos(0.05) - player->dir_y * sin(0.05);
		player->dir_y = player->dir_x * sin (0.05) + player->dir_y * cos(0.05);

		player->plane_x = player->plane_x * cos(0.05) - player->plane_y * sin(0.05);
		player->plane_y = player->plane_x * sin(0.05) + player->plane_y * cos(0.05);
	}
	else if (mlx_is_key_down(player->game->init, MLX_KEY_LEFT))
	{
		player->dir_x = player->dir_x * cos(-0.05) - player->dir_y * sin(-0.05);
		player->dir_y = player->dir_x * sin (-0.05) + player->dir_y * cos(-0.05);

		player->plane_x = player->plane_x * cos(-0.05) - player->plane_y * sin(-0.05);
		player->plane_y = player->plane_x * sin(-0.05) + player->plane_y * cos(-0.05);
	}
	update(player->game, player);
}
