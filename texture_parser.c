/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:56:21 by aball             #+#    #+#             */
/*   Updated: 2023/02/08 20:01:29 by ballzball        ###   ########.fr       */
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

void	set_up_ptr(t_data *data)
{
	data->north.xpm = mlx_xpm_file_to_image(data->mlx, data->north.path, &data->north.width, &data->north.height);
	data->north.addr = mlx_get_data_addr(data->north.xpm, &data->north.bits, &data->north.line, &data->north.endian);
	data->south.xpm = mlx_xpm_file_to_image(data->mlx, data->south.path, &data->south.width, &data->south.height);
	data->south.addr = mlx_get_data_addr(data->south.xpm, &data->south.bits, &data->south.line, &data->south.endian);
	data->east.xpm = mlx_xpm_file_to_image(data->mlx, data->east.path, &data->east.width, &data->east.height);
	data->east.addr = mlx_get_data_addr(data->east.xpm, &data->east.bits, &data->east.line, &data->east.endian);
	data->west.xpm = mlx_xpm_file_to_image(data->mlx, data->west.path, &data->west.width, &data->west.height);
	data->west.addr = mlx_get_data_addr(data->west.xpm, &data->west.bits, &data->west.line, &data->west.endian);
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