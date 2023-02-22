/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:56:21 by aball             #+#    #+#             */
/*   Updated: 2023/02/22 20:49:25 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_up_ptr(t_data *data)
{
	if (mlx_xpm_file_to_image(data->mlx, data->north.path, \
	&data->north.width, &data->north.height) == NULL || \
		mlx_xpm_file_to_image(data->mlx, data->south.path, \
		&data->south.width, &data->south.height) == NULL || \
		mlx_xpm_file_to_image(data->mlx, data->east.path, \
		&data->east.width, &data->east.height) == NULL || \
		mlx_xpm_file_to_image(data->mlx, data->west.path, \
		&data->west.width, &data->west.height) == NULL)
		ft_perror2("empty xmp file", data);
	data->north.xpm = mlx_xpm_file_to_image(data->mlx, data->north.path, \
	&data->north.width, &data->north.height);
	data->north.addr = mlx_get_data_addr(data->north.xpm, &data->north.bits, \
	&data->north.line, &data->north.endian);
	data->south.xpm = mlx_xpm_file_to_image(data->mlx, data->south.path, \
	&data->south.width, &data->south.height);
	data->south.addr = mlx_get_data_addr(data->south.xpm, &data->south.bits, \
	&data->south.line, &data->south.endian);
	data->east.xpm = mlx_xpm_file_to_image(data->mlx, data->east.path, \
	&data->east.width, &data->east.height);
	data->east.addr = mlx_get_data_addr(data->east.xpm, &data->east.bits, \
	&data->east.line, &data->east.endian);
	data->west.xpm = mlx_xpm_file_to_image(data->mlx, data->west.path, \
	&data->west.width, &data->west.height);
	data->west.addr = mlx_get_data_addr(data->west.xpm, &data->west.bits, \
	&data->west.line, &data->west.endian);
}
