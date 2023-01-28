/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:40 by aball             #+#    #+#             */
/*   Updated: 2023/01/29 00:28:21 by ballzball        ###   ########.fr       */
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

void	place_square(int x, int y, t_data *data, int size, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, colour);
			j++;
		}
		i++;
	}
}

void place_ceiling_floor(t_data *data)
{
	int	x;
	int	y;
	int	pixel_x;
	int	pixel_y;
	// int	limit;

	x = 0;
	pixel_x = 0;
	pixel_y = 0;
	place_square(0, 0, data, SCREEN_H, 0x000000);
	place_square(SCREEN_H, 0, data, SCREEN_H, 0x000000);
	while (data->map.map[x])
	{
		y = 0;
		pixel_y = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == '1')
			{
				place_square(pixel_y, pixel_x, data, 64, 0x00FF00);
			}
			y++;
			pixel_y += 64;
		}
		x++;
		pixel_x += 64;
	}
	place_square(data->player.x_pos * 64, data->player.y_pos * 64, data, 10, 0xffffff);
	// drawline(0, 0, 100, 100, data);
	cast_ray(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}