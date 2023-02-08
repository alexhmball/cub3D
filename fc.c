/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:40:44 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 18:05:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_rgb(t_color *color, char **str)
{
	if ((ft_atoi(str[0]) > 255) || (ft_atoi(str[1]) > 255) || \
	(ft_atoi(str[2]) > 255))
		ft_perror("out of color range (high)\n");
	if ((ft_atoi(str[0]) < 0) || (ft_atoi(str[1]) < 0) || (ft_atoi(str[2]) < 0))
		ft_perror("out of color range (low)\n");
	color->r = ft_atoi(str[0]);
	color->g = ft_atoi(str[1]);
	color->b = ft_atoi(str[2]);
}

void	get_fc(t_data *data)
{
	char	**splited;
	int		i;

	i = 0;
	while (data->cub_file[i])
	{
		if (data->cub_file[i][0] == '1'
				|| data->cub_file[i][0] == ' '
				|| data->cub_file[i][0] == '0')
			break ;
		splited = ft_split(data->cub_file[i++], ", \n");
		if (splited[0])
		{
			if (ft_strcmp(splited[0], "F") == 0)
				get_rgb(&data->floor, splited + 1);
			else if (ft_strcmp(splited[0], "C") == 0)
				get_rgb(&data->ceiling, splited + 1);
		}
		free_split(splited);
	}
}

