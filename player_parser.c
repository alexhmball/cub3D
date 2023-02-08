/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:04:37 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 18:24:47 by aball            ###   ########.fr       */
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
				map->player.x_pos = row;
				map->player.y_pos = col;
				map->map[row][col] = '0';
				map->player.direction = map->map[row][col];
				return ;
			}
			col++;
		}
		row++;
	}
}
