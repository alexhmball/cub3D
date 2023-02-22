/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:36:56 by aball             #+#    #+#             */
/*   Updated: 2023/02/22 21:47:59 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_data *data, char direction)
{
	if (direction == 'W')
	{
		data->player.move = data->player.degree;
		data->player.y_pos -= sin(degtorad(data->player.degree)) * SPEED;
		data->player.x_pos += cos(degtorad(data->player.degree)) * SPEED;
	}
}

void	move_s(t_data *data, char direction)
{
	if (direction == 'S')
	{
		data->player.move = check_angle(data->player.degree - 180);
		data->player.y_pos += sin(degtorad(data->player.degree)) * SPEED;
		data->player.x_pos -= cos(degtorad(data->player.degree)) * SPEED;
	}
}

void	move_a(t_data *data, char direction)
{
	double	angle;

	if (direction == 'A')
	{
		angle = degtorad(check_angle(data->player.degree - 90));
		data->player.move = angle;
		data->player.y_pos -= sin(angle) * SPEED;
		data->player.x_pos += cos(angle) * SPEED;
	}
}

void	move_d(t_data *data, char direction)
{
	double	angle;

	if (direction == 'D')
	{
		angle = degtorad(check_angle(data->player.degree + 90));
		data->player.move = angle;
		data->player.y_pos -= sin(angle) * SPEED;
		data->player.x_pos += cos(angle) * SPEED;
	}
}
