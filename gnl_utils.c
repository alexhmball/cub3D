/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:04:33 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/20 21:21:59 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	*ft_gnl(int fd)
// {
// 	char	line[5000];
// 	char	buf;
// 	int		i;

// 	i = 0;
// 	while (read(fd, &buf, 1) == 1)
// 	{
// 		line[i++] = buf;
// 		if (buf == '\n')
// 			break ;
// 	}
// 	line[i] = '\0';
// 	if (!line[0])
// 		return (NULL);
// 	return (ft_strdup(line));
// }

int	ft_count_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_perror("can't open file for read");
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}
