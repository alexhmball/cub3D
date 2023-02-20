/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalnaqbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:46:49 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/01/31 21:46:50 by aalnaqbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_perror(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(2);
}

void	ft_perror2(char *error, t_data *data)
{
	ft_free(data);
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(2);
}

void	ft_perror3(char *error, char **str)
{
	ft_free2darray(str);
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(2);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
