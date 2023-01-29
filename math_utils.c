/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:53:37 by aball             #+#    #+#             */
/*   Updated: 2023/01/29 23:08:44 by ballzball        ###   ########.fr       */
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

double	distance(double x, double y, double x2, double y2)
{
	double	dist;

	dist = sqrt(pow((x - x2), 2) + pow(y - y2, 2));
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