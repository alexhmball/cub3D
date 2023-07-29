/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:43 by aball             #+#    #+#             */
/*   Updated: 2023/06/03 13:55:21 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_prog(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->north.xpm);
	mlx_destroy_image(data->mlx, data->south.xpm);
	mlx_destroy_image(data->mlx, data->east.xpm);
	mlx_destroy_image(data->mlx, data->west.xpm);
	mlx_destroy_window(data->mlx, data->win);
	ft_free(data);
	free(data->mlx);
	exit (0);
}

int	key_press(int keycode, void *data)
{
	t_data	*data2;

	data2 = (t_data *)data;
	(void)keycode;
	if (keycode == ESC)
		exit_prog(data);
	if (keycode == A)
		move_player(data2, 'A');
	if (keycode == D)
		move_player(data2, 'D');
	if (keycode == S)
		move_player(data2, 'S');
	if (keycode == W)
		move_player(data2, 'W');
	if (keycode == LEFT)
		data2->player.degree = check_angle(data2->player.degree - 2.5);
	if (keycode == RIGHT)
		data2->player.degree = check_angle(data2->player.degree + 2.5);
	mlx_clear_window(data2->mlx, data2->win);
	place_ceiling_floor(data2);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.map.file_name = av[1];
	data.map.player = &data.player;
	int_data(&data);
	parse_cub(&data, ac, av);
	set_direction(&data);
	data.mlx = mlx_init();
	// mlx_do_sync(data.mlx);
	data.win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "cub3d");
	data.img = mlx_new_image(data.mlx, SCREEN_W, SCREEN_H);
	set_up_ptr(&data);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	place_ceiling_floor(&data);
	mlx_hook(data.win, 2, 1L, key_press, &data);
	mlx_hook(data.win, 17, 0, exit_prog, (void *)&data);
	mlx_loop(data.mlx);
	ft_free(&data);
}
