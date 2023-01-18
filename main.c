#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		printf("Error\nPlease provide a configuration file\n");
	}
	else
	{
		data.map.path = *(av + 1);
		parse_map(&data);
		parse_texture(&data);
		// data.mlx  = mlx_init();
		// data.win = mlx_new_window(data.mlx, 1000, 1000, "cub3d");
		// test_exec(&data);
		// execute here
		// mlx_loop(data.mlx);
	}
}