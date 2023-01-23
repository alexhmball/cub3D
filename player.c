/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:06:42 by aball             #+#    #+#             */
/*   Updated: 2023/01/23 17:01:38 by aball            ###   ########.fr       */
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
		data->player.degree = 0;
	if (data->player.direction == 'W')
		data->player.degree = 90;
	if (data->player.direction == 'S')
		data->player.degree = 180;
	if (data->player.direction == 'E')
		data->player.degree = 270;
}

int	parse_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->player.direction = 0;
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (!check_valid(data->map.map[x][y], data, x, y))
				return (0);
			y++;
		}
		x++;
	}
	set_direction(data);
	return (1);
}