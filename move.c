/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:34:10 by aball             #+#    #+#             */
/*   Updated: 2023/02/22 22:19:32 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_lr(t_data *data, double angle)
{
	int	px;
	int	py;

	py = (int)floor(data->player.y_pos - sin(angle) * SPEED);
	px = (int)floor(data->player.x_pos + cos(angle) * SPEED);
	if (data->map.map[py][px] != '0')
		return (1);
	return (0);
}

static void	check_collision(t_data *data, double x, double y)
{
	double	angle;
	int		px;
	int		py;
	int		left;
	int		right;

	angle = data->player.move;
	px = (int)floor(data->player.x_pos);
	py = (int)floor(data->player.y_pos);
	right = check_lr(data, degtorad(check_angle(angle - 0.5)));
	left = check_lr(data, degtorad(check_angle(angle + 0.5)));
	if (left && right)
	{
		data->player.x_pos = x;
		data->player.y_pos = y;
		return ;
	}
	if (data->map.map[py][px] == '1')
	{
		data->player.x_pos = x;
		data->player.y_pos = y;
	}
}

void	move_player(t_data *data, char direction)
{
	double	prev_x;
	double	prev_y;

	prev_x = data->player.x_pos;
	prev_y = data->player.y_pos;
	move_w(data, direction);
	move_s(data, direction);
	move_a(data, direction);
	move_d(data, direction);
	check_collision(data, prev_x, prev_y);
}
