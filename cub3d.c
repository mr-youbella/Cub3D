#include "cub3d.h"

int main()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	memset(game, 0, sizeof(t_game));
	game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", false);
	if (!game->init)
		return (1);
	game->img = mlx_new_image(game->init, WIDTH, HEIGHT);
	mlx_image_to_window(game->init, game->img, 0, 0);
	t_player_map	*player;
	player = malloc(sizeof(t_player_map));
	if (!player)
		return (1);
	memset(player, 0, sizeof(t_player_map));
	player->game = game;
	char *map[50] = {
		"111111111111111111111111",
		"111011011100001111110001",
		"100000000000000111100001",
		"111111110000010000000001",
		"110000010001111111100001",
		"111111111000000000000001",
		"1001111111000000S0000011",
		"111111111100000000000001",
		"100000000000000000000001",
		"100000000000000000000001",
		"100000000111111111000001",
		"100000000000000000000001",
		"101111110000000011111101",
		"100000000111111111110001",
		"111111111111111111111111",
		NULL
	};
	player->map = map;
	player_position(player);
	update(game, player);
	mlx_loop_hook(game->init, check_key_moves, player);
	mlx_loop_hook(game->init, check_fleche_key, player);
	mlx_loop_hook(game->init, destroy, game);
	mlx_close_hook(game->init, close_window, game);
	mlx_loop(game->init);
	//mlx_terminate(game->init);
}
