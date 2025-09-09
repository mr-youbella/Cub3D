#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	t_walls		*walls;
	t_data		*data;
	t_map_data	*map_data;
	t_door		*door;

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
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	door = malloc(sizeof(t_door));
	if (!door)
		return (1);
	ft_memset(door, 0, sizeof(t_door));
	game->init = mlx_init(WIDTH, HEIGHT, "Cub3d_CRAFT", true);
	if (!game->init)
		return (1);
	game->img = mlx_new_image(game->init, WIDTH, HEIGHT);
	mlx_image_to_window(game->init, game->img, 0, 0);
	map_data = ft_map_data(argv[1]);
	if (!map_data)
		return (1);
	data->game = game;
	data->walls = walls;
	data->map_data = map_data;
	data->door = door;
	player_position(data);
	walls->no_img = mlx_load_png(map_data->no_img);
	if (!walls->no_img)
		return (1);
	walls->so_img = mlx_load_png(map_data->so_img);
	if (!walls->so_img)
		return (1);
	walls->we_img = mlx_load_png(map_data->we_img);
	if (!walls->we_img)
		return (1);
	walls->ea_img = mlx_load_png(map_data->ea_img);
	if (!walls->ea_img)
		return (1);
	walls->door = mlx_load_png("door.png");
	if (!walls->door)
		return (1);
	walls->knife = mlx_load_png("knife.png");
	if (!walls->knife)
		return (1);
	update(game, data);
	mlx_loop_hook(game->init, check_fleche_key, data);
	mlx_loop_hook(game->init, check_key_moves, data);
	mlx_loop_hook(game->init, destroy, game);
	mlx_close_hook(game->init, close_window, game);
	mlx_loop(game->init);
	mlx_terminate(game->init);
}
