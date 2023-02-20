/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalnaqbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:36:18 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/03 18:36:23 by aalnaqbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	check_new_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}

char	*ft_strndup(char *s1, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_charcheck(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > 2147483647) && (sign == 1))
			return (-1);
		else if ((result > 2147483648) && (sign == -1))
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
