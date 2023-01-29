/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:41:46 by ballzball         #+#    #+#             */
/*   Updated: 2023/01/30 03:30:18 by ballzball        ###   ########.fr       */
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


int	wall_direction(t_data *data)
{
	double diff_x;
	double diff_y;

	diff_x = data->player.ray.x - data->player.ray.prev_x;
	if (diff_x < 0)
		diff_x *= -1;
	diff_y = data->player.ray.y - data->player.ray.prev_y;
	if (diff_y < 0)
		diff_y *= -1;
	// printf("diff_x: %f, diff_y: %f\n", diff_x, diff_y);
	if (diff_x > diff_y)
		return (HORIZONTAL);
	else
		return (VERTICAL);
}

int		wall_colour(t_data *data)
{
	int quadrant;
	int direction;

	quadrant = find_quadrant(data->player.ray.angle);
	direction = wall_direction(data);
	if (quadrant == 1)
	{
		if (direction == HORIZONTAL)
			return (SOUTH);
		else
			return (EAST);
	}
	if (quadrant == 2)
	{
		if (direction == HORIZONTAL)
			return (SOUTH);
		else
			return (WEST);
	}
	if (quadrant == 3)
	{
		if (direction == HORIZONTAL)
			return (NORTH);
		else
			return (WEST);
	}
	if (quadrant == 4)
	{
		if (direction == HORIZONTAL)
			return (NORTH);
		else
			return (EAST);
	}
	return (0x000000);
}

void	update_rays(t_data *data)
{
	data->player.ray.prev_x = data->player.ray.x;
	data->player.ray.prev_y = data->player.ray.y;
}

void draw_wall_slice(t_data *data, int x)
{
	int w_height;
	int start;
	int end;

	w_height = (64 / distance(data->player.ray.x, data->player.ray.y, data->player.x_pos * 64, data->player.y_pos * 64)) * 512;
	start = (SCREEN_H / 2) - (w_height);
	end = (SCREEN_H / 2) + (w_height);
	while (start < end)
	{
		my_mlx_pixel_put(data, x, start, 0xff00ff);
		start++;
	}
}

void cast_ray(t_data *data)
{
	int x;
	int y;
	int	rays;

	x = data->player.x_pos * 64;
	y = data->player.y_pos * 64;
	data->player.ray.angle = check_angle(data->player.degree - FOV / 2);
	data->player.ray.x = x;
	data->player.ray.y = y;
	rays = 0;
	while (data->map.map[(int)data->player.ray.y / 64][(int)data->player.ray.x / 64] != '1')
	{
		data->player.ray.y += cos(degtorad(data->player.ray.angle));
		data->player.ray.x -= sin(degtorad(data->player.ray.angle));
		if (data->player.ray.y > SCREEN_H || data->player.ray.x > SCREEN_W)
			break ;
		// if ((int)data->player.ray.x % 5 == 0 && (int)data->player.ray.y % 5 == 0)
		// 	my_mlx_pixel_put(data, data->player.ray.x, data->player.ray.y, 0xFFFFFF);
	}
	rays += 2;
	data->player.ray.angle = check_angle(data->player.ray.angle + 0.1);
	update_rays(data);
	while (rays < FOV * 20)
	{
		while (data->map.map[(int)data->player.ray.y / 64][(int)data->player.ray.x / 64] != '1')
		{
			data->player.ray.y += cos(degtorad(data->player.ray.angle));
			data->player.ray.x -= sin(degtorad(data->player.ray.angle));
			if (data->player.ray.y > SCREEN_H || data->player.ray.x > SCREEN_W)
				break ;
			// if ((int)data->player.ray.x % 5 == 0 && (int)data->player.ray.y % 5 == 0)
			// 	my_mlx_pixel_put(data, data->player.ray.x, data->player.ray.y, 0xFFFFFF);
		}
		draw_wall_slice(data, rays);
		draw_wall_slice(data, rays + 1);
		update_rays(data);
		rays += 2;
		data->player.ray.angle = check_angle(data->player.ray.angle + 0.1);
		data->player.ray.x = x;
		data->player.ray.y = y;
	}
}