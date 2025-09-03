#include "cub3d.h"

int main()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	memset(game, 0, sizeof(t_game));
	game->init = mlx_init();
	if (!game->init)
		return (0);
	game->window = mlx_new_window(game->init, 1536, 960, "Cub3d_CRAFT");
	if (!game->window)
		return (0);
	t_player_map	*player;
	player = malloc(sizeof(t_player_map));
	if (!player)
		return (1);
	memset(player, 0, sizeof(t_player_map));
	player->game = game;
	char *map[25] = {
		"111111111111111111111111",
		"1110110111E0001111110001",
		"100000000000000111100001",
		"111111110000010000000001",
		"110000010001111111100001",
		"111111111000000000000001",
		"100111111100000000000011",
		"100000000000000000000001",
		"100000000000000000000001",
		"100000000000000000000001",
		"100000000111111111000001",
		"100000000000000000000001",
		"100000000000000000000001",
		"100000000000000000000001",
		"111111111111111111111111",
		NULL
	};
	player->map = map;
	player_position(player);
	update(game, player);
	handle_mlx_hook(player);
	mlx_loop(game->init);
}
