/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:47:43 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/25 17:13:13 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_player_space_detect(t_data *data, int row, int col)
{
	if (data->map.map[row][col + 1] == ' ' || data->map.map[row][col - 1] == ' '
		|| data->map.map[row + 1][col] == ' '
		|| data->map.map[row - 1][col] == ' ')
		ft_perror2("space around player\n", data);
	return (0);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (!ft_charcheck(data->map.map[i][j], " 01NSEW"))
				ft_perror2("Wrong char in map.\n", data);
			if (ft_charcheck(data->map.map[i][j], "NSEW")
				&& !ft_player_space_detect(data, i, j))
				player++;
			j++;
		}
		i++;
	}
	if (!player)
		ft_perror2("No player in map file\n", data);
	else if (player > 1)
		ft_perror2("More than 1 player found\n", data);
}

void	ft_get_map(t_data *data)
{
	int		i;
	int		j;

	i = data->map_b;
	j = 0;
	data->map.row = get_map_len(data);
	data->map.map = malloc(sizeof(char *) * (data->map.row + 1));
	data->map.col = 0;
	if (!data->map.map)
		ft_perror2("Malloc Error\n", data);
	while (data->cub_file[i])
	{
		if (data->cub_file[i][0] == '1' || data->cub_file[i][0] == ' '
		|| data->cub_file[i][0] == '0')
		{
			data->map.map[j++] = ft_strndup(data->cub_file[i], \
			ft_strlen(data->cub_file[i]) - check_new_line(data->cub_file[i]));
			if (data->map.col < ft_strlen(data->map.map[j - 1]))
				data->map.col = ft_strlen(data->map.map[j - 1]);
			data->map.map[j] = 0;
		}
		else
			ft_perror2("Invalid map\n", data);
		i++;
	}
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
