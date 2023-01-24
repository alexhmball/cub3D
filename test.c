/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:40 by aball             #+#    #+#             */
/*   Updated: 2023/01/24 19:19:20 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"
#include <time.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

int	get_colour(t_texture *img, int x, int y)
{
	char *pixel;
	int	colour;

	pixel = img->addr + (y * img->line + x * (img->bits / 8));
	colour = *(unsigned int *)pixel;
	return (colour);
}

void place_ceiling_floor(t_data *data)
{
	int	x;
	int	y;
	int	ix;
	int	iy;
	int	up;
	int down;

	x = 0;
	iy = 0;
	ix = 0;
	down = (SCREEN_H / 3);
	up = (SCREEN_H / 3) + (down);
	while (x < SCREEN_W)
	{
		y = 0;
		iy = 0;
		while (y < SCREEN_H)
		{
			if (y < SCREEN_H / 2)
				my_mlx_pixel_put(data, x, y, data->ceiling);
			else
				my_mlx_pixel_put(data, x, y, data->floor);
			if (x > 200 && y > down && x < 500 && y < up)
				my_mlx_pixel_put(data, x, y, get_colour(&data->north, ix, iy++));
			if (x >= 500 && y > down && x < 800 && y < up)
				my_mlx_pixel_put(data, x, y, get_colour(&data->east, ix, iy++));
			if (x >= 800 && y > down && x < 1100 && y < up)
				my_mlx_pixel_put(data, x, y, get_colour(&data->south, ix, iy++));
			if (x % 5 && y % 5)
				my_mlx_pixel_put(data, x, y, 0x000000);
			y++;
		}
		x++;
		ix++;
		if (x % 3 == 0 && x > 200 && x < 500)
		{
			up--;
			down--;
		}
		// else if (x > 500 && x < 800 && x % 10)
		// {
		// 	up--;
		// 	down--;
		// }
		else if (x > 800 && x < 1100 && x % 3 == 0)
		{
			up++;
			down++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}