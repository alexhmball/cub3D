/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:43 by aball             #+#    #+#             */
/*   Updated: 2023/01/29 01:43:31 by ballzball        ###   ########.fr       */
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
	if (keycode == ESC)
		exit_prog(data);
	if (keycode == W)
		data2->player.y_pos -= 0.1;
	if (keycode == S)
		data2->player.y_pos += 0.1;
	if (keycode == A)
		data2->player.x_pos -= 0.1;
	if (keycode == D)
		data2->player.x_pos += 0.1;
	if (keycode == LEFT)
		data2->player.degree = check_angle(data2->player.degree - 1);
	if (keycode == RIGHT)
		data2->player.degree = check_angle(data2->player.degree + 1);
	mlx_clear_window(data2->mlx, data2->win);
	// mlx_put_image_to_window(data2->mlx, data2->win, data2->north.xpm, 0, 0);
	place_ceiling_floor(data2);
	printf("%d\n", keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		printf("Error\nPlease provide a configuration file\n");
	else
	{
		data.mlx  = mlx_init();
		data.map.path = *(av + 1);
		if (!parse_map(&data) || !parse_texture(&data) || !parse_player(&data))
			exit(1);
		printf("%s\n", data.north.path);
		data.win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "cub3d");
		data.img = mlx_new_image(data.mlx, SCREEN_W, SCREEN_H);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		// execute here
		place_ceiling_floor(&data);
		// mlx_key_hook(data.win, key_press, &data);
		printf("hyppo 64 cube: %f\n", sqrt(pow((16 - 0), 2) + pow(16 - 0, 2)));
		mlx_hook(data.win, 2, 1L<<0, key_press, &data);
		mlx_hook(data.win, 17, 0, exit_prog, (void *)0);
		mlx_loop(data.mlx);
	}
}