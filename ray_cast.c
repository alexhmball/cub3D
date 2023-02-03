/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:41:46 by ballzball         #+#    #+#             */
/*   Updated: 2023/02/03 18:20:14 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int find_quadrant(double degree)
{
	if (degree >= 0 && degree < 90)
		return (1);
	if (degree >= 90 && degree < 180)
		return (2);
	if (degree >= 180 && degree < 270)
		return (3);
	if (degree >= 270 && degree < 360)
		return (4);
	return (0);
}

void	cast_horizonal(t_data *data)
{
	int	quad;

	quad = find_quadrant(data->player.ray.angle);
	if (quad == 3 || quad == 4)
	{
		data->player.ray.hy_inc = -1;
		data->player.ray.hy = floor(data->player.ray.y) - 1;
		data->player.ray.hx = (data->player.ray.y - data->player.ray.hy) / tan(degtorad(data->player.ray.angle)) + data->player.ray.x ;
		data->player.ray.hx_inc = 1 / tan(degtorad(data->player.ray.angle));
	}
	else
	{
		data->player.ray.hy_inc = 1;
		data->player.ray.hy = floor(data->player.ray.y) + 1;
		data->player.ray.hx = (data->player.ray.y - data->player.ray.hy) / tan(degtorad(data->player.ray.angle)) + data->player.ray.x;
		data->player.ray.hx_inc = 1 / tan(degtorad(data->player.ray.angle));
	}
}

void	cast_vertical(t_data *data)
{
	int	quad;

	quad = find_quadrant(data->player.ray.angle);
	if (quad == 3 || quad == 2)
	{
		data->player.ray.vx_inc = -1;
		data->player.ray.vx = floor(data->player.ray.x) - 1;
		data->player.ray.vy = ((data->player.ray.x - data->player.ray.vx) / tan(degtorad(data->player.ray.angle))) + data->player.ray.y;
		data->player.ray.vy_inc = 1 / tan(degtorad(data->player.ray.angle));
	}
	else
	{
		data->player.ray.vx_inc = 1;
		data->player.ray.vx = floor(data->player.ray.x) + 1;
		data->player.ray.vy = ((data->player.ray.x - data->player.ray.vx) / tan(degtorad(data->player.ray.angle))) + data->player.ray.y;
		data->player.ray.vy_inc = 1 / tan(degtorad(data->player.ray.angle));
	}
	// printf("tanv: %f\n", tan(degtorad(data->player.ray.angle)));
}

void draw_wall_slice(t_data *data, int x)
{
	int	w_height;
	int	start;
	int	end;
	// int	red;
	// int	blue;
	double	disth;
	double	distv;
	int	colour;

	distv = distance(data->player.ray.vx, data->player.ray.vy, data->player.x_pos, data->player.y_pos);
	disth = distance(data->player.ray.hx, data->player.ray.hy, data->player.x_pos, data->player.y_pos);
	// blue = 255 - dist / 5;
	// red = 255 - dist / 5;
	colour = 0xff00ff;
	if (distv < disth)
		w_height = (distv) * 64;
	else
		w_height = (disth) * 64;
	start = (SCREEN_H / 2) - (w_height);
	end = (SCREEN_H / 2) + (w_height);
	if (start < 0)
		start = 0;
	if (end > SCREEN_H)
		end = SCREEN_H;
	while (start < end)
	{
		my_mlx_pixel_put(data, x, start, colour);
		my_mlx_pixel_put(data, x + 1, start, colour);
		start++;
	}
}

int	check_walls(t_data *data)
{
	if (floor(data->player.ray.vy) < 0 || floor(data->player.ray.vx) < 0)
		return (0);
	if (floor(data->player.ray.hy) < 0 || floor(data->player.ray.hx) < 0)
		return (0);
	if (data->map.map[(int)floor(data->player.ray.hy)][(int)floor(data->player.ray.hx)] == '1')
		return (0);
	if (data->map.map[(int)floor(data->player.ray.vy)][(int)floor(data->player.ray.vx)] == '1')
		return (0);
	data->player.ray.vx += data->player.ray.vx_inc;
	data->player.ray.vy += data->player.ray.vy_inc;
	data->player.ray.hx += data->player.ray.hx_inc;
	data->player.ray.hy += data->player.ray.hy_inc;
	return (1);
}

void	cast_ray(t_data *data)
{
	int	rays;

	data->player.ray.angle = check_angle(data->player.degree - FOV / 2);
	rays = 0;
	while (rays < FOV * 20)
	{
		data->player.ray.x = data->player.x_pos;
		data->player.ray.y = data->player.y_pos;
		cast_horizonal(data);
		cast_vertical(data);
		// printf("player: x: %f y: %f\n", data->player.x_pos, data->player.y_pos);
		// printf("vertical x: %f y: %f\n", data->player.ray.vx / 64, data->player.ray.vy / 64);
		// printf("horizonal x: %f y: %f\n", data->player.ray.hx / 64, data->player.ray.hy / 64);
		printf("angle: %f\n", data->player.ray.angle);
		printf("increase v x: %f y: %f\n", data->player.ray.vx_inc, data->player.ray.vy_inc);
		printf("increase h x: %f y: %f\n", data->player.ray.hx_inc, data->player.ray.hy_inc);
		while (check_walls(data) != 0)
		{
			printf("hi\n");

		// printf("vertical x: %f y: %f\n", data->player.ray.vx, data->player.ray.vy);
		// printf("horizonal x: %f y: %f\n", data->player.ray.hx, data->player.ray.hy);
			// data->player.ray.y += cos(degtorad(data->player.ray.angle));
			// data->player.ray.x -= sin(degtorad(data->player.ray.angle));
			// if (data->player.ray.vy > SCREEN_H || data->player.ray.vx > SCREEN_W)
			// 	break ;
			// if (data->player.ray.hy > SCREEN_H || data->player.ray.hx > SCREEN_W)
			// 	break ;
			// if ((int)data->player.ray.x % 5 == 0 && (int)data->player.ray.y % 5 == 0)
			// my_mlx_pixel_put(data, data->player.ray.hx * 64, data->player.ray.hy * 64, 0xFFFFFF);
			// my_mlx_pixel_put(data, data->player.ray.vx * 64, data->player.ray.vy * 64, 0x000000);
		}
		draw_wall_slice(data, rays);
		rays += 2;
		data->player.ray.angle = check_angle(data->player.ray.angle + 0.1);
	}
}
