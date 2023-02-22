/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:06:42 by aball             #+#    #+#             */
/*   Updated: 2023/02/22 20:53:54 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_direction(t_data *data)
{
	if (data->player.direction == 'N')
		data->player.degree = 90;
	if (data->player.direction == 'W')
		data->player.degree = 180;
	if (data->player.direction == 'S')
		data->player.degree = 270;
	if (data->player.direction == 'E')
		data->player.degree = 0;
}

double	check_angle(double angle)
{
	if (angle < 0)
		angle += 360;
	if (angle > 360)
		angle -= 360;
	return (angle);
}
