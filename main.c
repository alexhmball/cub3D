/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:43 by aball             #+#    #+#             */
/*   Updated: 2023/01/22 19:55:53 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_prog(void *param)
{
	(void)param;
	exit (1);
}

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
		if (!parse_map(&data) || !parse_texture(&data))
			exit(1);
		printf("%s\n", data.north.path);
		data.mlx  = mlx_init();
		data.win = mlx_new_window(data.mlx, SCREEN_H, SCREEN_W, "cub3d");
		data.img = mlx_new_image(data.mlx, SCREEN_H, SCREEN_W);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		// execute here
		test_exec(&data);
		mlx_key_hook(data.win, key_press, &data);
		mlx_hook(data.win, 17, 0, exit_prog, (void *)0);
		mlx_loop(data.mlx);
	}
}