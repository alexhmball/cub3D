/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:34:16 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/20 21:20:54 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_cub_file(t_data *data)
{
	int		len;
	int		fd;
	int		i;

	i = 0;
	len = ft_count_lines(data->map.file_name);
	data->cub_file = malloc(sizeof(char *) * (len + 1));
	if (!data->cub_file)
		ft_perror("Can't Malloc \n");
	fd = open(data->map.file_name, O_RDONLY);
	if (fd == -1)
		ft_perror("can't open file for read1");
	data->cub_file[i] = get_next_line(fd);
	while (i < len && data->cub_file[i++])
		data->cub_file[i] = get_next_line(fd);
	data->cub_file[i] = NULL;
	close(fd);
}

void	ft_check_cub_file(t_data *data)
{
	ft_check_texture(data);
	ft_check_fc(data);
}

void	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
		ft_perror("run as: ./cub3D <map path .cub>\n");
	if (ft_strrchr(av[1], '.'))
	{
		if (ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5)
			|| ft_strlen(av[1]) == 4)
			ft_perror("Error: map name should end with .cub extention\n");
	}
}

void	parse_cub(t_data *data, int ac, char **av)
{
	ft_check_arg(ac, av);
	ft_get_cub_file(data);
	data->map_b = get_map_start(data);
	
	ft_check_cub_file(data);
	ft_get_map(data);
	check_map(data);
	get_textures1(data);
	get_textures2(data);
	get_fc(data);
	check_map_all(data);
	get_player(&data->map);
}
