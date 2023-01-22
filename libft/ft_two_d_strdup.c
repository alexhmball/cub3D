/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_d_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:06:56 by aball             #+#    #+#             */
/*   Updated: 2023/01/22 17:46:52 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**two_d_strdup(char **str)
{
	char	**dest;
	int		i;

	if (!str || !*str)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * two_d_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		dest[i] = ft_strdup(str[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}