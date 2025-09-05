#include "cub3d.h"

void	destroy(void *arg)
{
	t_game	*game = (t_game *)arg;
	if (mlx_is_key_down(game->init, MLX_KEY_ESCAPE))
	{
		printf ("YOU CLOSED WINDOW :(");
		mlx_close_window(game->init);
	}
}

void	close_window(void *arg)
{
	t_game	*game = (t_game *)arg;

	printf ("WINDOW CLOSED :(\n");
	mlx_close_window(game->init);
}
