#include "cub3d.h"

int	check_key_moves(int key_code, void *param)
{
	t_player_map *player = (t_player_map *)param;
	if (key_code == KEY_W)
	{
		player->pos_x += player->dir_x;
		player->pos_y += player->dir_y;
	}
	else if (key_code == KEY_S)
	{
		player->pos_x -= player->dir_x;
    	player->pos_y -= player->dir_y;
	}
	else if (key_code == KEY_A )
	{
		player->pos_x -= player->plane_x;
    	player->pos_y -= player->plane_y;
	}
	else if (key_code == KEY_D)
	{
		player->pos_x += player->plane_x;
   		player->pos_y += player->plane_y;
	}
	update(player->game, player);
	return (0);
}

void	handle_mlx_hook(t_player_map *player)
{
	mlx_hook(player->game->window, 2, 0, check_key_moves, player);
}