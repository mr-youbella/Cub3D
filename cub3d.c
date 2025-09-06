#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_walls	*walls;

	if (argc != 2)
		return (1);
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", false);
	if (!game->init)
		return (1);
	walls = malloc(sizeof(t_walls));
	if (!walls)
		return (1);
	ft_memset(walls, 0, sizeof(t_walls));
	game->img = mlx_new_image(game->init, WIDTH, HEIGHT);
	mlx_image_to_window(game->init, game->img, 0, 0);
	t_player_map	*player;
	player = malloc(sizeof(t_player_map));
	if (!player)
		return (1);
	ft_memset(player, 0, sizeof(t_player_map));
	player->game = game;
	player->map = get_map(argv[1]);
	if (!player->map)
		return (1);
	player_position(player);
	walls->no_img = mlx_load_png("mk1.png");
	walls->so_img = mlx_load_png("mk2.png");
	walls->we_img = mlx_load_png("mk3.png");
	walls->ea_img = mlx_load_png("mk4.png");
	player->walls = walls;
	update(game, player);
	mlx_loop_hook(game->init, check_key_moves, player);
	mlx_loop_hook(game->init, check_fleche_key, player);
	mlx_loop_hook(game->init, destroy, game);
	mlx_close_hook(game->init, close_window, game);
	mlx_loop(game->init);
	//mlx_terminate(game->init);
}
