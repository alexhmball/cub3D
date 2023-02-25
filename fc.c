/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:40:44 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/25 16:34:53 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_rgb(t_color *color, char **str, t_data *data)
{
	if (str[4])
	{
		free_split(str);
		ft_perror2("wrong FC!\n", data);
	}
	if ((ft_atoi(str[1]) > 255) || (ft_atoi(str[2]) > 255) || \
	(ft_atoi(str[3]) > 255))
	{
		free_split(str);
		ft_perror2("out of color range (high)\n", data);
	}
	if ((ft_atoi(str[1]) < 0) || (ft_atoi(str[2]) < 0) || (ft_atoi(str[3]) < 0))
	{
		free_split(str);
		ft_perror2("out of color range (low)\n", data);
	}
	color->r = ft_atoi(str[1]);
	color->g = ft_atoi(str[2]);
	color->b = ft_atoi(str[3]);
}

void	ft_check_fc(t_data *data)
{
	int	i;
	int	foundf;
	int	foundc;

	i = 0;
	foundf = 0;
	foundc = 0;
	while (i < data->map_b)
	{
		if (ft_strncmp(data->cub_file[i], "F ", 2) == 0)
		{
			foundf++;
			checklinebs(data->cub_file[i], data);
		}
		if (ft_strncmp(data->cub_file[i], "C ", 2) == 0)
		{
			foundc++;
			checklinebs(data->cub_file[i], data);
		}
		i++;
	}
	if ((foundf != 1) || (foundc != 1))
		ft_perror2("check FC!\n", data);
}

void	get_fc(t_data *data)
{
	char	**splited;
	int		i;

	i = 0;
	while (i < data->map_b)
	{
		splited = ft_split(data->cub_file[i++], ", \n");
		if (splited[0])
		{
			if (ft_strcmp(splited[0], "F") == 0)
			{
				get_rgb(&data->floor, splited, data);
				data->floor_int = (data->floor.r << 16) + \
				(data->floor.g << 8) + (data->floor.b);
			}
			else if (ft_strcmp(splited[0], "C") == 0)
			{
				get_rgb(&data->ceiling, splited, data);
				data->ceiling_int = (data->ceiling.r << 16) + \
				(data->ceiling.g << 8) + (data->ceiling.b);
			}
		}
		free_split(splited);
	}
}

void	checklinebs(char *str, t_data *data)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == ',')
			found++;
		i++;
	}
	if (found != 2)
		ft_perror2("wrong FC ,!\n", data);
}
