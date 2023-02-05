/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:06:42 by aball             #+#    #+#             */
/*   Updated: 2023/02/06 01:50:23 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid(char c, t_data *data, int x, int y)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'E' && c != 'W' && c != 'S')
	{
		printf("Error\nInvalid character in map.\n");
		return (0);
	}
	if (c == 'S' || c == 'E' || c == 'W' || c == 'N')
	{
		if (!data->player.direction)
		{
			data->player.direction = c;
			data->player.x_pos = x;
			data->player.y_pos = y;
		}
		else
		{
			printf("Error\nmore than one player position\n");
			return (0);
		}
	}
	return (1);
}

void	set_direction(t_data *data)
{
	if (data->player.direction == 'N')
		data->player.degree = 90;
	if (data->player.direction == 'W')
		data->player.degree = 180;
	if (data->player.direction == 'S')
		data->player.degree = 270;
	if (data->player.direction == 'E')
		data->player.degree = 0;
}

double	check_angle(double angle)
{
	if (angle < 0)
		angle += 360;
	if (angle > 360)
		angle -= 360;
	return (angle);
}

int	parse_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->player.direction = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (!check_valid(data->map.map[y][x], data, x, y))
				return (0);
			x++;
		}
		y++;
	}
	set_direction(data);
	return (1);
}