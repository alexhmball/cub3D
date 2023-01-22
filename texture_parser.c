/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:56:21 by aball             #+#    #+#             */
/*   Updated: 2023/01/22 17:55:45 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_ext_xpm(char *path)
{
	if (ft_strncmp(ft_strrchr(path, '.'), ".xpm", 4)
		|| ft_strlen(ft_strrchr(path, '.')) != 4)
	{
		printf("path: |%s|\n", path);
		printf("Error\nTexture files must be xpm images\n");
		return (0);
	}
	return (1);
}

static int check_paths(t_data *data)
{
	if (!check_ext_xpm(data->north.path))
		return (0);
	if (!check_ext_xpm(data->south.path))
		return (0);
	if (!check_ext_xpm(data->east.path))
		return (0);
	if (!check_ext_xpm(data->west.path))
		return (0);
	return (1);
}

static int check_fds(t_data *data)
{
	if (data->north.fd < 0)
		return (0);
	if (data->south.fd < 0)
		return (0);
	if (data->east.fd < 0)
		return (0);
	if (data->west.fd < 0)
		return (0);
	return (1);
}

static void	set_up_ptr(t_data *data)
{
	int	h;
	int	w;

	h = 32;
	w = 32;
	data->north.xpm = mlx_xpm_file_to_image(data->mlx, data->north.path, &w, &h);
	data->south.xpm = mlx_xpm_file_to_image(data->mlx, data->south.path, &w, &h);
	data->east.xpm = mlx_xpm_file_to_image(data->mlx, data->east.path, &w, &h);
	data->west.xpm = mlx_xpm_file_to_image(data->mlx, data->west.path, &w, &h);
}

int	parse_texture(t_data *data)
{
	if (!check_paths(data))
		return (0);
	data->north.fd = open(data->north.path, O_RDONLY);
	data->south.fd = open(data->south.path, O_RDONLY);
	data->east.fd = open(data->east.path, O_RDONLY);
	data->west.fd = open(data->west.path, O_RDONLY);
	if (check_fds(data))
	{
		set_up_ptr(data);
		close(data->north.fd);
		close(data->south.fd);
		close(data->east.fd);
		close(data->west.fd);
		return (1);
	}
	printf("Error\ntexture files doesn't exist\n");
	return(0);
}