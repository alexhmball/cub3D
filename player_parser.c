/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:04:37 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/14 14:06:25 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->map[row])
	{
		col = 0;
		while (map->map[row][col])
		{
			if (ft_charcheck(map->map[row][col], "NSEW"))
			{
				map->player->x_pos = col + 0.5;
				map->player->y_pos = row + 0.5;
				map->player->direction = map->map[row][col];
				map->map[row][col] = '0';
				return ;
			}
			col++;
		}
		row++;
	}
}
