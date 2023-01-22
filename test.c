/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:40 by aball             #+#    #+#             */
/*   Updated: 2023/01/22 19:56:24 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

void test_exec(t_data *data)
{
	printf("printing map\n");
	for (int i = 0; data->map.map[i]; i++)
	{
		printf("%s\n", data->map.map[i]);
	}
	for (int i = 0; i < SCREEN_H; i++)
	{
		for (int j = 0; j < SCREEN_W; j++)
			my_mlx_pixel_put(data, i, j, data->ceiling);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	printf("floor: %d  ceiling:  %d\n", data->floor, data->ceiling);
	//loop through map and draw walls

}