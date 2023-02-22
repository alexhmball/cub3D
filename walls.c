/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:20:32 by aball             #+#    #+#             */
/*   Updated: 2023/02/22 23:12:58 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	drawing(t_data *data, int x, double start, double end)
{
	while (start < end)
	{
		if (data->texture->x > data->texture->width - 1)
			data->texture->x = data->texture->width - 1;
		if (data->texture->y > data->texture->height - data->texture->ystep - 1)
			data->texture->y = data->texture->height - data->texture->ystep - 1;
		my_mlx_pixel_put(data, x, start,
			get_colour(data->texture, data->texture->x,
				data->texture->y += data->texture->ystep));
		start++;
	}
}

void	draw_wall_slice(t_data *data, int x, t_texture *texture, double xo)
{
	double	w_height;
	double	start;
	double	end;

	texture = find_t(data, &w_height);
	start = ((double)SCREEN_H / 2.0) - (w_height / 2.0);
	end = ((double)SCREEN_H / 2.0) + (w_height / 2.0);
	if (end > SCREEN_H)
		end = SCREEN_H;
	if (data->distv < data->disth)
		xo = (int)(data->player.ray.vy * texture->width) % texture->width;
	else
		xo = (int)(data->player.ray.hx * texture->width) % texture->width;
	texture->x = xo;
	texture->y = 0;
	texture->ystep = texture->height / w_height;
	if (start < 0)
	{
		texture->y = -start / w_height * texture->height;
		start = 0;
	}
	data->texture = texture;
	drawing(data, x, start, end);
}

int	check_vert_walls(t_data *data)
{
	int	vy;
	int	vx;

	vy = (int)floor(data->player.ray.vy);
	vx = (int)floor(data->player.ray.vx);
	if (vy < 0 || vx < 0)
		return (0);
	if (vy > two_d_strlen(data->map.map) - 1)
		return (0);
	if (vx > ft_strlen(data->map.map[vy]))
		return (0);
	if (data->map.map[vy][vx] == '1')
		return (0);
	data->player.ray.vx += data->player.ray.vx_inc;
	data->player.ray.vy += data->player.ray.vy_inc;
	return (1);
}

int	check_horiz_walls(t_data *data)
{
	int	hy;
	int	hx;

	hy = (int)floor(data->player.ray.hy);
	hx = (int)floor(data->player.ray.hx);
	if (hy < 0 || hx < 0)
		return (0);
	if (hy > two_d_strlen(data->map.map))
		return (0);
	if (hx > ft_strlen(data->map.map[hy]))
		return (0);
	if (data->map.map[hy][hx] != '0')
		return (0);
	data->player.ray.hx += data->player.ray.hx_inc;
	data->player.ray.hy += data->player.ray.hy_inc;
	return (1);
}
