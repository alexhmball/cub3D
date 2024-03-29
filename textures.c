/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:10:48 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/20 20:49:32 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_texture(t_data *data)
{
	int	found;
	int	i;

	i = 0;
	found = 0;
	while (i < data->map_b)
	{
		if (ft_strncmp(data->cub_file[i], "NO ", 3) == 0
			|| ft_strncmp(data->cub_file[i], "SO ", 3) == 0
			|| ft_strncmp(data->cub_file[i], "WE ", 3) == 0
			|| ft_strncmp(data->cub_file[i], "EA ", 3) == 0)
			found++;
		i++;
	}
	if (found != 4)
		ft_perror("Wrong Texture!\n");
}

void	get_textures1(t_data *data)
{
	char	**splited;
	int		i;

	i = 0;
	while (i < data->map_b)
	{
		splited = ft_split(data->cub_file[i++], ", \n");
		if (splited[0])
		{
			if (ft_strcmp(splited[0], "NO") == 0)
			{
				ft_check_xpm(splited[1], data);
				data->north.path = ft_strdup(splited[1]);
			}
			else if (ft_strcmp(splited[0], "SO") == 0)
			{
				ft_check_xpm(splited[1], data);
				data->south.path = ft_strdup(splited[1]);
			}
		}
		free_split(splited);
	}
}

void	get_textures2(t_data *data)
{
	char	**splited;
	int		i;

	i = 0;
	while (i < data->map_b)
	{
		splited = ft_split(data->cub_file[i++], ", \n");
		if (splited[0])
		{
			if (ft_strcmp(splited[0], "EA") == 0)
			{
				ft_check_xpm(splited[1], data);
				data->east.path = ft_strdup(splited[1]);
			}
			else if (ft_strcmp(splited[0], "WE") == 0)
			{
				ft_check_xpm(splited[1], data);
				data->west.path = ft_strdup(splited[1]);
			}
		}
		free_split(splited);
	}
}

void	ft_check_xpm(char *str, t_data *data)
{
	if (&str[0] == NULL)
		ft_perror("wrong xmp file [empty]\n");
	if (ft_strrchr(&str[0], '.'))
	{
		if (ft_strncmp(ft_strrchr(&str[0], '.'), ".xpm", 4)
			|| ft_strlen(&str[0]) == 4)
			ft_perror2("wrong xmp file\n", data);
	}
	if (open(&str[0], O_RDONLY) < 0)
		ft_perror2("Texture Error\n", data);
}
