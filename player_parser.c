/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:04:37 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 19:52:47 by ballzball        ###   ########.fr       */
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
				map->player->x_pos = col;
				map->player->y_pos = row;
				map->player->direction = map->map[row][col];
				map->map[row][col] = '0';
				return ;
			}
			col++;
		}
		row++;
	}
}
