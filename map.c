/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:47:43 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 17:55:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_player_space_detect(char **map, int row, int col)
{
	if (map[row][col + 1] == ' ' || map[row][col - 1] == ' '
		|| map[row + 1][col] == ' ' || map[row - 1][col] == ' ')
		ft_perror("space around player\n");
	return (0);
}

void	check_map(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_charcheck(map[i][j], " 01NSEW"))
				ft_perror("Wrong char in map.\n");
			if (ft_charcheck(map[i][j], "NSEW")
				&& !ft_player_space_detect(map, i, j))
				player++;
			j++;
		}
		i++;
	}
	if (!player)
		ft_perror("No player in map file\n");
	else if (player > 1)
		ft_perror("More than 1 player found\n");
}

void	ft_get_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->map.row = get_map_len(data);
	data->map.map = malloc(sizeof(char *) * (data->map.row + 1));
	data->map.col = 0;
	if (!data->map.map)
		ft_perror("Malloc Error\n");
	while (data->cub_file[i])
	{
		if (data->cub_file[i][0] == '1'
				|| data->cub_file[i][0] == ' '
				|| data->cub_file[i][0] == '0')
		{
			data->map.map[j++] = ft_strndup(data->cub_file[i],
					ft_strlen(data->cub_file[i]) - \
					check_new_line(data->cub_file[i]));
			if (data->map.col < ft_strlen(data->map.map[j - 1]))
				data->map.col = ft_strlen(data->map.map[j - 1]);
		}
		i++;
	}
	data->map.map[j] = 0;
}

int	get_map_len(t_data *data)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (data->cub_file[i])
	{
		if (data->cub_file[i][0] == '1'
				|| data->cub_file[i][0] == ' '
				|| data->cub_file[i][0] == '0')
		{
			len++;
		}
		i++;
	}
	return (len);
}



void	check_map_all(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map.map[row])
	{
		col = 0;
		if (check_extended_wall(data->map.map, row))
			ft_perror("map Error!\n");
		while (data->map.map[row][col])
		{
			map_checks_(data, row, col);
			col++;
		}
		row++;
	}
}


