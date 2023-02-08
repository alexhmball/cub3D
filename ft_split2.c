/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:26:33 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 17:55:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	is_delim(char c, char *sap)
{
	int	i;

	i = 0;
	while (sap[i])
	{
		if (c == sap[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *sap)
{
	int	i;
	int	w_count;
	int	state;

	i = 0;
	w_count = 0;
	state = 0;
	while (str[i])
	{
		if (!is_delim(str[i], sap))
		{
			if (!state)
				w_count++;
			state = 1;
			i++;
		}
		else
		{
			state = 0;
			i++;
		}
	}
	return (w_count);
}

static char	*ft_strdup_w(char *str, int *index, char *sap)
{
	char	*word;
	int		len;
	int		i;

	i = *index;
	len = 0;
	while (str[i] && !is_delim(str[i++], sap))
		len++;
	word = (char *) malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str[*index])
	{
		if (!is_delim(str[*index], sap))
		{
			word[i++] = str[*index];
			(*index)++;
		}
		else
			break ;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *d)
{
	char	**splitted;
	int		i;
	int		words;
	int		w_i;

	i = 0;
	w_i = 0;
	words = count_words(str, d);
	splitted = (char **) malloc((words + 1) * sizeof(char **));
	if (!splitted)
		return (NULL);
	while (w_i < words)
	{
		while (is_delim(str[i], d) && str[i])
			if (!str[i++])
				break ;
		splitted[w_i] = ft_strdup_w(str, &i, d);
		if (!splitted[w_i])
			return (malloc_error(splitted));
		w_i++;
	}
	splitted[words] = 0;
	return (splitted);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}