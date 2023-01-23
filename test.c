/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:40 by aball             #+#    #+#             */
/*   Updated: 2023/01/23 14:25:13 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

void place_ceiling_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_H)
	{
		y = 0;
		while (y < SCREEN_W)
		{
			if (y < SCREEN_W / 2)
				my_mlx_pixel_put(data, x, y, data->ceiling);
			else
				my_mlx_pixel_put(data, x, y, data->floor);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}