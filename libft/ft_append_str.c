/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:33:49 by aball             #+#    #+#             */
/*   Updated: 2023/01/22 19:27:15 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freedom(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

int	two_d_strlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	**append_str(char **str, char *append)
{
	int		i;
	int		size;
	char	**new;

	if (str)
		size = two_d_strlen(str) + 2;
	else
		size = 2;
	new = (char **)malloc(sizeof(char *) * size);
	if (!new)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	new[i++] = ft_strdup(append);
	new[i] = NULL;
	freedom(str);
	free(append);
	return (new);
}
