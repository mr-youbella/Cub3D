#include "cub3d.h"

void    check_key_moves(void *arg)
{
    t_player_map *player = (t_player_map *)arg;
    float new_pos_x;
    float new_pos_y;
    if (mlx_is_key_down(player->game->init, MLX_KEY_W))
    {
        new_pos_x = player->pos_x + (player->dir_x * 0.1);
        new_pos_y = player->pos_y + (player->dir_y * 0.1);
        if (player->map[(int)player->pos_y][(int)new_pos_x] != '1')
            player->pos_x = new_pos_x;

        if (player->map[(int)new_pos_y][(int)player->pos_x] != '1')
            player->pos_y = new_pos_y;
    }
    else if (mlx_is_key_down(player->game->init, MLX_KEY_S))
    {
        new_pos_x = player->pos_x - (player->dir_x * 0.1);
        new_pos_y = player->pos_y - (player->dir_y * 0.1);
        if (player->map[(int)player->pos_y][(int)new_pos_x] != '1')
            player->pos_x = new_pos_x;

        if (player->map[(int)new_pos_y][(int)player->pos_x] != '1')
            player->pos_y = new_pos_y;
    }
    else if (mlx_is_key_down(player->game->init, MLX_KEY_A))
    {
        new_pos_x = player->pos_x - (player->plane_x * 0.1);
        new_pos_y = player->pos_y - (player->plane_y * 0.1);
        if (player->map[(int)player->pos_y][(int)new_pos_x] != '1')
            player->pos_x = new_pos_x;

        if (player->map[(int)new_pos_y][(int)player->pos_x] != '1')
            player->pos_y = new_pos_y;
    }
    else if (mlx_is_key_down(player->game->init, MLX_KEY_D))
    {
        new_pos_x = player->pos_x + (player->plane_x * 0.1);
           new_pos_y = player->pos_y + (player->plane_y * 0.1);
        if (player->map[(int)player->pos_y][(int)new_pos_x] != '1')
            player->pos_x = new_pos_x;

        if (player->map[(int)new_pos_y][(int)player->pos_x] != '1')
            player->pos_y = new_pos_y;
    }
    update(player->game, player);
}
