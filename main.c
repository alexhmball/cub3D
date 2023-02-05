/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:43 by aball             #+#    #+#             */
/*   Updated: 2023/02/06 02:20:56 by ballzball        ###   ########.fr       */
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
	if (keycode == A)
		move_player_w(data2, 'A');
	if (keycode == D)
		move_player_w(data2, 'D');
	if (keycode == S)
		move_player_w(data2, 'S');
	if (keycode == W)
		move_player_w(data2, 'W');
	if (keycode == LEFT)
		data2->player.degree = check_angle(data2->player.degree - 1);
	if (keycode == RIGHT)
		data2->player.degree = check_angle(data2->player.degree + 1);
	mlx_clear_window(data2->mlx, data2->win);
	// mlx_put_image_to_window(data2->mlx, data2->win, data2->north.xpm, 0, 0);
	place_ceiling_floor(data2);
	// printf("%d\n", keycode);
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
		place_ceiling_floor(&data);
		mlx_hook(data.win, 2, 1L<<0, key_press, &data);
		mlx_hook(data.win, 17, 0, exit_prog, (void *)0);
		mlx_loop(data.mlx);
	}
}