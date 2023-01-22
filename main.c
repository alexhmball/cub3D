#include "cub3d.h"

int	key_press(int keycode, void *data)
{
	t_data *data2;

	data2 = (t_data *)data;
	(void)keycode;
	// if (keycode == 25)
	// {
		mlx_clear_window(data2->mlx, data2->win);
		mlx_put_image_to_window(data2->mlx, data2->win, data2->north.xpm, 0, 0);
		printf("hi\n");
	// }
	return (0);
}



// void	key_hook(t_data *data)
// {
// 	// mlx_hook(data->win, 2, 1L<<0, key_press, data);
// 	mlx_key_hook(data->win, key_press, data);
// }

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
		printf("%s\n", data.north.path);
		parse_texture(&data);
		data.mlx  = mlx_init();
		data.win = mlx_new_window(data.mlx, data.height, data.width, "cub3d");
		data.img = mlx_new_image(data.mlx, data.width, data.height);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		data.north.xpm = mlx_xpm_file_to_image(data.mlx, data.north.path, &data.width, &data.height);
		test_exec(&data);
		// execute here
		// key_hook(&data);
		mlx_key_hook(data.win, key_press, &data);
		// mlx_hook(data.win, 17, 0, exit_prog, (void *)0);
		mlx_loop(data.mlx);
	}
}