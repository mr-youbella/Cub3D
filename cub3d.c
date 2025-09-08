#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game			*game;
	t_walls			*walls;
	t_player_map	*player;
	t_map_data		*map_data;

	if (argc != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	walls = malloc(sizeof(t_walls));
	if (!walls)
		return (1);
	ft_memset(walls, 0, sizeof(t_walls));
	player = malloc(sizeof(t_player_map));
	if (!player)
		return (1);
	ft_memset(player, 0, sizeof(t_player_map));
	game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", true);
	if (!game->init)
		return (1);
	game->img = mlx_new_image(game->init, WIDTH, HEIGHT);
	mlx_image_to_window(game->init, game->img, 0, 0);
	map_data = ft_map_data(argv[1]);
	if (!map_data)
		return (1);
	player->game = game;
	player->walls = walls;
	player->map = map_data->map;
	player_position(player);
	walls->no_img = mlx_load_png(map_data->no_img);
	walls->so_img = mlx_load_png(map_data->so_img);
	walls->we_img = mlx_load_png(map_data->we_img);
	walls->ea_img = mlx_load_png(map_data->ea_img);
	update(game, player);
	mlx_loop_hook(game->init, check_key_moves, player);
	mlx_loop_hook(game->init, check_fleche_key, player);
	mlx_loop_hook(game->init, destroy, game);
	mlx_close_hook(game->init, close_window, game);
	mlx_loop(game->init);
	mlx_terminate(game->init);
}
