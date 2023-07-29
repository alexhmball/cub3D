/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:46:49 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/06/03 13:53:31 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_perror(char *error)
{
	int ret;
	ret = write(2, "Error\n", 6);
	ret = write(2, error, ft_strlen(error));
	exit(ret);
}

void	ft_perror2(char *error, t_data *data)
{
	int ret;
	ft_free(data);
	ret = write(2, "Error\n", 6);
	ret = write(2, error, ft_strlen(error));
	exit(ret);
}

void	ft_perror3(char *error, char **str)
{
	int ret;
	ft_free2darray(str);
	ret = write(2, "Error\n", 6);
	ret = write(2, error, ft_strlen(error));
	exit(ret);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
