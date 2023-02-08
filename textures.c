/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:10:48 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 19:39:28 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_texture(char **file, int *i)
{
	int	found;

	found = 0;
	while (*i < 4 && file[*i])
	{
		if (ft_strncmp(file[*i], "NO ", 3) == 0
			|| ft_strncmp(file[*i], "SO ", 3) == 0
			|| ft_strncmp(file[*i], "WE ", 3) == 0
			|| ft_strncmp(file[*i], "EA ", 3) == 0)
			found++;
		(*i)++;
	}
	if (found != 4 && *i != found)
		ft_perror("Wrong Texture!\n");
	if (*i == 0)
		ft_perror("Empty .cub file!\n");
}

void	get_textures(t_data *data)
{
	char	**splited;
	int		i;

	i = 0;
	while (i < 4)
	{
		splited = ft_split(data->cub_file[i++], ", \n");
		if (!splited[0])
			return ;
		if (ft_strcmp(splited[0], "NO") == 0)
			data->north.path = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], "SO") == 0)
			data->south.path = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], "EA") == 0)
			data->east.path = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], "WE") == 0)
			data->west.path = ft_strdup(splited[1]);
		free_split(splited);
	}
	if (open(data->north.path, O_RDONLY) < 0
		|| open(data->south.path, O_RDONLY) < 0
		|| open(data->east.path, O_RDONLY) < 0
		|| open(data->west.path, O_RDONLY) < 0)
		ft_perror("Texture Error\n");
}
