/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:41:46 by ballzball         #+#    #+#             */
/*   Updated: 2023/01/29 01:54:48 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int find_quadrant(t_data *data)
{
	if (data->player.degree >= 0 && data->player.degree < 90)
		return (1);
	if (data->player.degree >= 90 && data->player.degree < 180)
		return (2);
	if (data->player.degree >= 180 && data->player.degree < 270)
		return (3);
	if (data->player.degree >= 270 && data->player.degree < 360)
		return (4);
	return (0);
}

void drawline(int x1, int y1, int x2, int y2, t_data *data)
{
	int dx;
	int dy;
	int x;
	int	y;
	int	p;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx < dy)
	{
		if (y1 > y2)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		x = x1;
		y = y1;
		p = 2 * dx - dy;
		while (y <= y2)
		{
			my_mlx_pixel_put(data, x, y, 0xFFFFFF);
			if (p < 0)
				p += 2 * dx;
			else
			{
				x += (x2 - x1) / dy;
				p += 2 * (dx - dy);
			}
			y++;
		}
	}
	else
	{
		if (x1 > x2)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		x = x1;
		y = y1;
		p = 2 * dy - dx;
		while (x <= x2)
		{
			my_mlx_pixel_put(data, x, y, 0xFFFFFF);
			if (p < 0)
				p += 2 * dy;
			else
			{
				y += (y2 - y1) / dx;
				p += 2 * (dy - dx);
			}
			x++;
		}
	}
}

void cast_ray(t_data *data)
{
	int x;
	int y;

	x = data->player.x_pos * 64;
	y = data->player.y_pos * 64;
	data->player.ray.angle = data->player.degree;
	data->player.ray.x = data->player.x_pos;
	data->player.ray.y = data->player.y_pos;
	while (data->map.map[(int)data->player.ray.y][(int)data->player.ray.x] != '1')
	{
		data->player.ray.x += (int)cos(degtorad(data->player.degree));
		data->player.ray.y += (int)sin(degtorad(data->player.degree));
	}
	drawline(0, 100, 80, 100, data);
	drawline(x, y, data->player.ray.x * 64, data->player.ray.y * 64, data);
}