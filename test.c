/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:40 by aball             #+#    #+#             */
/*   Updated: 2023/02/14 14:02:23 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	get_colour(t_texture *img, int x, int y)
{
	char	*pixel;
	int		colour;

	pixel = img->addr + (y * img->line + x * (img->bits / 8));
	colour = *(unsigned int *)pixel;
	return (colour);
}

void	place_ceiling_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			if (y < SCREEN_H / 2)
				my_mlx_pixel_put(data, x, y, 0xff0f0f);
			else
				my_mlx_pixel_put(data, x, y, 0x00ff00);
			x++;
		}
		y++;
	}
	cast_ray(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
