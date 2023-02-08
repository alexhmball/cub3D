/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:34:16 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 18:05:30 by aball            ###   ########.fr       */
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
	data->cub_file[i] = ft_gnl(fd);
	while (i < len && data->cub_file[i++])
		data->cub_file[i] = ft_gnl(fd);
	data->cub_file[i] = 0;
	close(fd);
}

void	ft_check_fc(char **file, int *i)
{
	int	found;
	int	j;
	int	ex;

	found = 0;
	ex = *i;
	j = *i + 2;
	while (*i < j && file[*i])
	{
		if (ft_strncmp(file[*i], "F ", 2) == 0
			|| ft_strncmp(file[*i], "C ", 2) == 0)
			found++;
		(*i)++;
	}
	if (*i - ex != found && found != 2)
		ft_perror("Wrong Colors\n");
}

void	ft_check_cub_file(char **file)
{
	int	i;

	i = 0;
	ft_check_texture(file, &i);
	while (file[i] && ft_strcmp(file[i], "\n") == 0)
		i++;
	ft_check_fc(file, &i);
	while (file[i] && ft_strcmp(file[i], "\n") == 0)
		i++;
	if (!file[i])
		ft_perror("Wrong Map!\n");
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
	ft_check_cub_file(data->cub_file);
	ft_get_map(data);
	check_map(data->map.map);
	get_textures(data);
	get_fc(data);
	get_player(&data->map);
	check_map_all(data);
}
