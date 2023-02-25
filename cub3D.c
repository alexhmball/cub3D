/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:57:58 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/25 16:35:07 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free2darray(char **c)
{
	int	i;

	i = -1;
	if (c)
	{
		while (c[++i])
			free(c[i]);
		free(c);
	}
}

void	ft_free(t_data *data)
{
	if (data->east.path)
		free(data->east.path);
	if (data->north.path)
		free(data->north.path);
	if (data->south.path)
		free(data->south.path);
	if (data->west.path)
		free(data->west.path);
	if (data->cub_file)
		ft_free2darray(data->cub_file);
	if (data->map.map)
		ft_free2darray(data->map.map);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	int_data(t_data *data)
{
	data->east.path = NULL;
	data->north.path = NULL;
	data->south.path = NULL;
	data->west.path = NULL;
	data->cub_file = NULL;
	data->map.map = NULL;
}
