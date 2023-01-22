/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:06:42 by aball             #+#    #+#             */
/*   Updated: 2023/01/22 20:19:09 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid(char c, char *direction)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'E' && c != 'W' && c != 'S')
	{
		printf("Error\nInvalid character in map.\n");
		return (0);
	}
	if (c == 'S' || c == 'E' || c == 'W' || c == 'N')
	{
		if (!*direction)
			*direction = c;
		else
		{
			printf("Error\nmore than one player position\n");
			return (0);
		}
	}
	return (1);
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
			if (!check_valid(data->map.map[x][y], &data->player.direction))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}