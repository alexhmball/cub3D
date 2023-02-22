/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalnaqbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:03:58 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/04 13:03:59 by aalnaqbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(char **map, int row, int col)
{
	if (map[row][col] != '1' && map[row][col] != ' ')
		return (1);
	return (0);
}

int	check_wall_(char **map, int row, int i)
{
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_extended_wall(char **map, int row)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(map[row]);
	l2 = 0;
	if (map[row + 1])
		l2 = ft_strlen(map[row + 1]);
	if (l1 > l2 && l2 > 0)
	{
		if (check_wall_(map, row, l2))
			return (1);
	}
	else if (l2 > l1)
	{
		if (check_wall_(map, row + 1, l1))
			return (1);
	}
	return (0);
}

void	map_checks_(t_data *data, int row, int col)
{
	if ((row == 0 && check_wall(data->map.map, row, col))
		|| (row == data->map.row - 1 && check_wall(data->map.map, row, col)))
		ft_perror2("Border not 1 up and down!\n", data);
	else if (col == 0 && check_wall(data->map.map, row, col))
		ft_perror2("left boarder not 1\n", data);
	else if (col == ft_strlen(data->map.map[row]) - 1 && \
	check_wall(data->map.map, row, col))
		ft_perror2("right boarder not 1\n", data);
	else if ((row > 0 && row < data->map.row - 1) && \
	(col > 0 && col < ft_strlen(data->map.map[row]) - 1))
	{
		if (data->map.map[row][col] == '0' && \
		(data->map.map[row + 1][col] == ' ' || \
			data->map.map[row - 1][col] == ' ' || \
			data->map.map[row][col + 1] == ' ' || \
			data->map.map[row][col - 1] == ' '))
			ft_perror2("floor surrounded by space\n", data);
	}
}

int	get_map_start(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (data->cub_file[i])
	{
		str = data->cub_file[i];
		j = -1;
		while (str[++j])
		{
			if (str[j] == '1')
				return (i);
			if (str[j] == ' ')
				j++;
			else if (str[j] != '1' )
			{
				i++;
				break ;
			}	
		}
	}
	ft_perror3("there is no map in cub file\n", data->cub_file);
	return (0);
}
