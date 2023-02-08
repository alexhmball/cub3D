/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:43 by aball             #+#    #+#             */
/*   Updated: 2023/02/09 02:39:18 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_prog(void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	ft_free(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->north.xpm);
	mlx_destroy_image(data->mlx, data->south.xpm);
	mlx_destroy_image(data->mlx, data->east.xpm);
	mlx_destroy_image(data->mlx, data->west.xpm);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}

int	key_press(int keycode, void *data)
{
	t_data *data2;

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
		data2->player.degree = check_angle(data2->player.degree - 1.5);
	if (keycode == RIGHT)
		data2->player.degree = check_angle(data2->player.degree + 1.5);
	mlx_clear_window(data2->mlx, data2->win);
	place_ceiling_floor(data2);
	return (0);
}

int	main(int ac, char **av)
{
	t_data data;

		data.map.file_name = av[1];
		data.map.player = &data.player;
		parse_cub(&data, ac, av);
		set_direction(&data);
		data.mlx  = mlx_init();
		data.win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "cub3d");
		data.img = mlx_new_image(data.mlx, SCREEN_W, SCREEN_H);
		set_up_ptr(&data);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		place_ceiling_floor(&data);
		mlx_hook(data.win, 2, 1L<<0, key_press, &data);
		mlx_hook(data.win, 17, 0, exit_prog, (void *)&data);
		mlx_loop(data.mlx);
		ft_free(&data);
}