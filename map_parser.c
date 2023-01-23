/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:47:36 by aball             #+#    #+#             */
/*   Updated: 2023/01/22 21:57:22 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_ext_cub(char *path)
{
	char *ext;

	ext = ft_strrchr(path, '.');
	if (ft_strncmp(ext, ".cub", 4)
		|| ft_strlen(ext) != 4)
	{
		printf("Error\nmap is not .cub\n");
		return (0);
	}
	return (1);
}

static void	read_file(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	data->map.file = NULL;
	data->map.map = NULL;
	data->map.file = append_str(data->map.file, get_next_line(data->map.fd));
	while (data->map.file[i])
	{
		len = ft_strlen(data->map.file[i]);
		if (len > 1 && data->map.file[i][len - 1] == '\n')
			data->map.file[i][len - 1] = 0;
		data->map.file = append_str(data->map.file, get_next_line(data->map.fd));
		i++;
	}
}

static int	check_char(char c)
{
	if (c != ' ' && c != '\n' && c != '1' && c != '0' && c != '\t')
		return (0);
	return (1);
}

void	find_map(t_data *data)
{
	int	i;

	i = two_d_strlen(data->map.file) - 1;
	while (i >= 0 && check_char(data->map.file[i][0]))
		i--;
	i++;
	data->map.map = two_d_strdup(data->map.file + i);
	i = 0;
	while (data->map.map[i] && data->map.map[i][0] == '\n'
		&& ft_strlen(data->map.map[i]) == 1)
	{
		free(data->map.map[i]);
		data->map.map++;
		i++;
	}
}

int	find_textures(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.file[i])
	{
		if (!ft_strncmp(data->map.file[i], "NO", 2) && data->map.file[i][2] == ' ')
			data->north.path = ft_strdup(ft_strchr(data->map.file[i], '.'));
		if (!ft_strncmp(data->map.file[i], "SO", 2) && data->map.file[i][2] == ' ')
			data->south.path = ft_strdup(ft_strchr(data->map.file[i], '.'));
		if (!ft_strncmp(data->map.file[i], "EA", 2) && data->map.file[i][2] == ' ')
			data->east.path = ft_strdup(ft_strchr(data->map.file[i], '.'));
		if (!ft_strncmp(data->map.file[i], "WE", 2) && data->map.file[i][2] == ' ')
			data->west.path = ft_strdup(ft_strchr(data->map.file[i], '.'));
		i++;
	}
	if (!data->north.path || !data->south.path || !data->east.path || !data->west.path)
	{
		printf("Error\nMissing textures\n");
		return (0);
	}
	return (1);
}

int	convert_colour(char *str, int *colour)
{
	int	r;
	int	g;
	int	b;
	int	end;

	end = 0;
	while (str[end] != ',' && str[end])
		end++;
	end++;
	r = ft_atoi(str);
	g = ft_atoi(str + end);
	b = ft_atoi(ft_strrchr(str, ',') + 1);
	if (r > 255 || g > 255 || b > 255)
	{
		printf("Error\nNumber out of range\n");
		return (0);
	}
	if (r == -1 || g == -1 || b == -1)
		return (0);
	*colour = rgbtoi(r, g, b);
	return (1);
}

int	find_colour(char *str, int *colour)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		printf("Error\nColour not accepted\n");
		return (0);
	}
	if (!convert_colour(str + i, colour))
		return (0);
	return (1);
}

int	find_fc(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.file[i])
	{
		if (data->map.file[i][0] == 'F')
		{
			if (!find_colour(data->map.file[i] + 1, &data->floor))
				return (0);
		}
		if (data->map.file[i][0] == 'C')
		{
			if (!find_colour(data->map.file[i] + 1, &data->ceiling))
				return (0);
		}
		i++;
	}
	return (1);
}

int	parse_map(t_data *data)
{
	if (!check_ext_cub(data->map.path))
		return (0);
	data->map.fd = open(data->map.path, O_RDONLY);
	if (data->map.fd > 0)
	{
		read_file(data);
		close(data->map.fd);
		find_map(data);
		if (!find_textures(data))
			return (0);
		if (!find_fc(data))
			return (0);
		return (1);
	}
	printf("Error\nMap file does not exist\n");
	return (0);
}