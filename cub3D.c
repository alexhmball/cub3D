/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:57:58 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/20 20:06:02 by aball            ###   ########.fr       */
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

// int	main(int ac, char **av)
// {
// 	t_data	data;

// 	int_data(&data);
// 	data.map.file_name = av[1];
// 	parse_cub(&data, ac, av);
// 	ft_free(&data);
// }

	// printf("the cubfile is [%s]\n", data.cub_file[0] );
	// printf("the cubfile is [%s]\n", data.cub_file[1] );
	// printf("the cubfile is [%s]\n", data.cub_file[2] );
	// printf("the cubfile is [%s]\n", data.cub_file[3] );
	// printf("the cubfile is [%s]\n", data.cub_file[4] );
	// printf("the cubfile is [%s]\n", data.cub_file[5] );
	// printf("the cubfile is [%s]\n", data.cub_file[6] );
	// printf("the cubfile is [%s]\n", data.cub_file[7] );
	// printf("the cubfile is [%s]\n", data.cub_file[8] );
	// printf("the cubfile is [%s]\n", data.cub_file[9] );
	// printf("the cubfile is [%s]\n", data.cub_file[10] );
	// printf("the cubfile is [%s]\n", data.cub_file[11] );
	// printf("the cubfile is [%s]\n", data.cub_file[12] );
	// printf("the cubfile is [%s]\n", data.cub_file[13] );
	// printf("the cubfile is [%s]\n", data.cub_file[14] );
	// printf("the cubfile is [%s]\n", data.cub_file[15] );
	// printf("the cubfile is [%s]\n", data.cub_file[16] );
	// printf("the cubfile is [%s]\n", data.cub_file[17] );
	// printf("the cubfile is [%s]\n", data.cub_file[18] );
	// printf("the cubfile is [%s]\n", data.cub_file[19] );
	// printf("the cubfile is [%s]\n", data.cub_file[20] );

	// printf("the north is [%s]\n", data.north.path);
	// printf("the south is [%s]\n", data.south.path);
	// printf("the east is [%s]\n", data.east.path);
	// printf("the west is [%s]\n", data.west.path);

	// printf("the floor color is [%d]\n", data.floor_int);
	// printf("the celing color is [%d]\n", data.ceiling_int);

	// printf("the map 0 is [%s]\n", data.map.map[0] );
	// printf("the map 1 is [%s]\n", data.map.map[1] );
	// printf("the map 2 is [%s]\n", data.map.map[2] );
	// printf("the map 3 is [%s]\n", data.map.map[3] );
	// printf("the map 4 is [%s]\n", data.map.map[4] );
	// printf("the map 5 is [%s]\n", data.map.map[5] );
	// printf("the map 6 is [%s]\n", data.map.map[6] );
	// printf("the map 7 is [%s]\n", data.map.map[7] );
