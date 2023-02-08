/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:58:02 by aball             #+#    #+#             */
/*   Updated: 2023/02/08 17:55:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_everything(t_data *data)
{
	data->north.path = NULL;
	data->south.path = NULL;
	data->east.path = NULL;
	data->west.path = NULL;
}