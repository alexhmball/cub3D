/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:57:58 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 18:03:49 by aball            ###   ########.fr       */
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

void ft_free(t_data *data)
{
	free(data->east.path);
	free(data->north.path);
	free(data->south.path);
	free(data->west.path);
	ft_free2darray(data->cub_file);
	ft_free2darray(data->map.map);

}

// int	main(int ac, char **av)
// {
// 	t_data	data;
// 	data.map.file_name = av[1];
// 	parse_cub(&data, ac, av);
// 	ft_free(&data);

// }
