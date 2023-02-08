/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:20:32 by aball             #+#    #+#             */
/*   Updated: 2023/02/08 15:13:02 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_wall_slice(t_data *data, int x)
{
	double w_height;
	int start;
	int end;
	double disth;
	double distv;
	double	offsetx;
	t_texture *texture;

	texture = find_texture(data, &distv, &disth, &w_height);
	start = (SCREEN_H / 2.0) - (w_height / 2.0);
	end = (SCREEN_H / 2.0) + (w_height / 2.0);
	if (end > SCREEN_H)
		end = SCREEN_H;
	if (distv < disth)
		offsetx = (int)(data->player.ray.vy * texture->width) % texture->width;
	else
		offsetx = (int)(data->player.ray.hx * texture->width) % texture->width;
	if (distv == disth)
		printf("corner\n");
	texture->x = offsetx;
	texture->y = 0;
	texture->ystep = (double)texture->height / (double)w_height;
	if (start < 0)
	{
		texture->y = -(double)start / (double)w_height * (double)texture->height;
		start = 0;
	}
	while (start < end)
	{
		if (texture->x > texture->width - 1)
			texture->x = texture->width - 1;
		if (texture->y > texture->height - texture->ystep - 1)
			texture->y = texture->height - texture->ystep - 1;
		my_mlx_pixel_put(data, x, start, get_colour(texture, texture->x, texture->y += texture->ystep));
		start++;
	}
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
	if (data->map.map[(int)floor(data->player.ray.hy)][(int)floor(data->player.ray.hx)] != '0')
		return (0);
	data->player.ray.hx += data->player.ray.hx_inc;
	data->player.ray.hy += data->player.ray.hy_inc;
	return (1);
}
