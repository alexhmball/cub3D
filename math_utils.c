/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:53:37 by aball             #+#    #+#             */
/*   Updated: 2023/01/23 18:30:10 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degtorad(double deg)
{
	double	rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

double	radtodeg(double rad)
{
	double	deg;

	deg = rad * (180 / M_PI);
	return (deg);
}

double	distance(double x, double y, t_player *player)
{
	double	dist;

	dist = sqrt(pow((x - player->x_pos), 2) + pow(y - player->y_pos, 2));
	return (dist);
}

double	dist_to_projection(void)
{
	return ((SCREEN_W / 2) / tan(FOV));
}

double	projected_height(double plane, double distance)
{
	return ((BLOCK / distance) * plane);
}