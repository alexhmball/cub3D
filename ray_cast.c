/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:41:46 by ballzball         #+#    #+#             */
/*   Updated: 2023/02/06 02:56:24 by ballzball        ###   ########.fr       */
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
	if (degree >= 270 && degree <= 360)
		return (4);
	return (0);
}

void cast_horizonal(t_data *data)
{
	double tangent;

	tangent = 1 / tan(degtorad(data->player.ray.angle));
	if (data->player.ray.angle < 180)
	{
		data->player.ray.hy_inc = -1.0;
		data->player.ray.hy = floor(data->player.ray.y) - 0.00001;
		data->player.ray.hx = ((data->player.ray.y - data->player.ray.hy) * tangent) + data->player.ray.x;
		data->player.ray.hx_inc = -data->player.ray.hy_inc * tangent;
	}
	else if (data->player.ray.angle > 180)
	{
		data->player.ray.hy_inc = 1.0;
		data->player.ray.hy = floor(data->player.ray.y) + 1.0;
		data->player.ray.hx = ((data->player.ray.y - data->player.ray.hy) * tangent) + data->player.ray.x;
		data->player.ray.hx_inc = -data->player.ray.hy_inc * tangent;
	}
	else
	{
		data->player.ray.hx = -0.01;
		data->player.ray.hy = -0.01;
	}
}

void cast_vertical(t_data *data)
{
	double tangent;

	// printf("quad: %d angle: %f\n", quad, data->player.ray.angle);
	tangent = tan(degtorad(data->player.ray.angle));
	if (data->player.ray.angle > 90 && data->player.ray.angle < 270)
	{
		data->player.ray.vx_inc = -1.0;
		data->player.ray.vx = floor(data->player.ray.x) - 0.00001;
		data->player.ray.vy = ((data->player.ray.x - data->player.ray.vx) * tangent) + data->player.ray.y;
		data->player.ray.vy_inc = -data->player.ray.vx_inc * tangent;
	}
	else if (data->player.ray.angle < 90 || data->player.ray.angle > 270)
	{
		data->player.ray.vx_inc = 1.0;
		data->player.ray.vx = floor(data->player.ray.x) + 1.0;
		data->player.ray.vy = ((data->player.ray.x - data->player.ray.vx) * tangent) + data->player.ray.y;
		data->player.ray.vy_inc = -data->player.ray.vx_inc * tangent;
	}
	else
	{
		data->player.ray.vx = -0.01;
		data->player.ray.vy = -0.01;
	}
}

void draw_wall_slice(t_data *data, int x)
{
	int w_height;
	int start;
	int end;
	double disth;
	double distv;
	t_texture *texture;

//   int ca = check_angle(data->player.degree - data->player.ray.angle); 

	distv = distance(data->player.ray.vx, data->player.ray.vy, data->player.x_pos, data->player.y_pos);
	disth = distance(data->player.ray.hx, data->player.ray.hy, data->player.x_pos, data->player.y_pos);
	if (distv < disth && distv > 0)
	{
		if (find_quadrant(data->player.ray.angle) == 1 || find_quadrant(data->player.ray.angle) == 4)
			texture = &data->east;
		else
			texture = &data->west;
		w_height = SCREEN_H / (distv);
	}
	else
	{
		if (find_quadrant(data->player.ray.angle) == 1 || find_quadrant(data->player.ray.angle) == 2)
			texture = &data->south;
		else
			texture = &data->north;
		w_height = SCREEN_H / (disth);
	}
	start = (SCREEN_H / 2) - (w_height / 2);
	end = (SCREEN_H / 2) + (w_height / 2);
	if (start < 0)
		start = 0;
	if (end > SCREEN_H)
		end = SCREEN_H;
	texture->step = (double)texture->height / (double)w_height;
	while (start < end)
	{
		if (texture->x > texture->width - 2)
			texture->x = 0;
		if (texture->y > texture->height - 1)
			texture->y = 0;
		my_mlx_pixel_put(data, x, start, get_colour(texture, texture->x, texture->y));
		my_mlx_pixel_put(data, x + 1, start, get_colour(texture, texture->x + 1, texture->y += texture->step));
		start++;
	}
	texture->x += 2;
	texture->y = 0;
}

int check_vert_walls(t_data *data)
{
	if (floor(data->player.ray.vy) < 0 || floor(data->player.ray.vx) < 0)
		return (0);
	if (floor(data->player.ray.vy) > two_d_strlen(data->map.map) - 1)
		return (0);
	if (floor(data->player.ray.vx) > ft_strlen(data->map.map[(int)floor(data->player.ray.vy)]))
		return (0);
	if (data->map.map[(int)floor(data->player.ray.vy)][(int)floor(data->player.ray.vx)] == '1')
		return (0);
	data->player.ray.vx += data->player.ray.vx_inc;
	data->player.ray.vy += data->player.ray.vy_inc;
	return (1);
}

int check_horiz_walls(t_data *data)
{
	if (floor(data->player.ray.hy) < 0 || floor(data->player.ray.hx) < 0)
		return (0);
	if (floor(data->player.ray.hy) > two_d_strlen(data->map.map))
		return (0);
	if (floor(data->player.ray.hx) > ft_strlen(data->map.map[(int)floor(data->player.ray.hy)]))
		return (0);
	if (data->map.map[(int)floor(data->player.ray.hy)][(int)floor(data->player.ray.hx)] == '1')
		return (0);
	data->player.ray.hx += data->player.ray.hx_inc;
	data->player.ray.hy += data->player.ray.hy_inc;
	return (1);
}

void cast_ray(t_data *data)
{
	int rays;

	data->player.ray.angle = check_angle(data->player.degree - FOV / 2);
	rays = 0;
	while (rays < FOV * 20)
	{
		data->player.ray.x = data->player.x_pos;
		data->player.ray.y = data->player.y_pos;
		cast_vertical(data);
		while (check_vert_walls(data))
		{
			// if (data->player.ray.vx * 64 < SCREEN_W && data->player.ray.vy * 64 < SCREEN_H && data->player.ray.vx * 64 > 0 && data->player.ray.vy * 64 > 0)
			// 	my_mlx_pixel_put(data, data->player.ray.vx * 64, data->player.ray.vy * 64, 0xffffff);
		}
		cast_horizonal(data);
		while (check_horiz_walls(data))
		{
			// if (data->player.ray.hx * 64 < SCREEN_W && data->player.ray.hy * 64 < SCREEN_H && data->player.ray.hx * 64 > 0 && data->player.ray.hy * 64 > 0)
			// 	my_mlx_pixel_put(data, data->player.ray.hx * 64, data->player.ray.hy * 64, 0xff0000);
		}
		draw_wall_slice(data, rays);
		rays += 2;
		data->player.ray.angle = check_angle(data->player.ray.angle + 0.1);
	}
}
