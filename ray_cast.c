/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:41:46 by ballzball         #+#    #+#             */
/*   Updated: 2023/02/25 14:52:34 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_horizonal(t_data *data, double tangent)
{
	if (data->player.ray.angle < 180)
	{
		data->player.ray.hy_inc = -1.0;
		data->player.ray.hy = floor(data->player.ray.y) - 0.00001;
		data->player.ray.hx = ((data->player.ray.y - data->player.ray.hy)
				* tangent) + data->player.ray.x;
		data->player.ray.hx_inc = -data->player.ray.hy_inc * tangent;
	}
	else if (data->player.ray.angle > 180)
	{
		data->player.ray.hy_inc = 1.0;
		data->player.ray.hy = floor(data->player.ray.y) + 1.0;
		data->player.ray.hx = ((data->player.ray.y - data->player.ray.hy)
				* tangent) + data->player.ray.x;
		data->player.ray.hx_inc = -data->player.ray.hy_inc * tangent;
	}
	else
	{
		data->player.ray.hx = -0.1;
		data->player.ray.hy = -0.1;
	}
}

void	cast_vertical(t_data *data, double tangent)
{
	if (data->player.ray.angle > 90 && data->player.ray.angle < 270)
	{
		data->player.ray.vx_inc = -1.0;
		data->player.ray.vx = floor(data->player.ray.x) - 0.00001;
		data->player.ray.vy = ((data->player.ray.x - data->player.ray.vx)
				* tangent) + data->player.ray.y;
		data->player.ray.vy_inc = -data->player.ray.vx_inc * tangent;
	}
	else if (data->player.ray.angle < 90 || data->player.ray.angle > 270)
	{
		data->player.ray.vx_inc = 1.0;
		data->player.ray.vx = floor(data->player.ray.x) + 1.0;
		data->player.ray.vy = ((data->player.ray.x - data->player.ray.vx)
				* tangent) + data->player.ray.y;
		data->player.ray.vy_inc = -data->player.ray.vx_inc * tangent;
	}
	else
	{
		data->player.ray.vx = -0.1;
		data->player.ray.vy = -0.1;
	}
}

void	find_texture(t_data *data, double *w_ht)
{
	if (data->distv < data->disth)
	{
		if (find_quadrant(data->player.ray.angle) == 1
			|| find_quadrant(data->player.ray.angle) == 4)
			data->texture = &data->east;
		else
			data->texture = &data->west;
		*w_ht = (double)SCREEN_H / data->distv;
	}
	else
	{
		if (find_quadrant(data->player.ray.angle) == 1
			|| find_quadrant(data->player.ray.angle) == 2)
			data->texture = &data->north;
		else
			data->texture = &data->south;
		*w_ht = (double)SCREEN_H / data->disth;
	}
}

t_texture	*find_t(t_data *data, double *w_ht)
{
	double		x;
	double		y;
	double		fish;

	x = data->player.x_pos;
	y = data->player.y_pos;
	fish = check_angle(data->player.ray.angle - data->player.degree);
	data->distv = distance(data->player.ray.vx, data->player.ray.vy, x, y);
	data->disth = distance(data->player.ray.hx, data->player.ray.hy, x, y);
	data->distv *= cos(degtorad(fish));
	data->disth *= cos(degtorad(fish));
	find_texture(data, w_ht);
	return (data->texture);
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
		cast_vertical(data, tan(degtorad(data->player.ray.angle)));
		while (check_vert_walls(data))
			;
		cast_horizonal(data, 1 / tan(degtorad(data->player.ray.angle)));
		while (check_horiz_walls(data))
			;
		draw_wall_slice(data, rays, data->texture, 0);
		rays++;
		data->player.ray.angle = check_angle(data->player.ray.angle + 0.05);
	}
}
