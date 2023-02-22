/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:53:37 by aball             #+#    #+#             */
/*   Updated: 2023/02/22 22:32:34 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degtorad(double deg)
{
	double	rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

double	distance(double x, double y, double x2, double y2)
{
	double	dist;

	dist = sqrt(pow((x - x2), 2) + pow(y - y2, 2));
	return (dist);
}

int	find_quadrant(double degree)
{
	if (degree >= 0 && degree < 90)
		return (1);
	if (degree >= 90 && degree < 180)
		return (2);
	if (degree >= 180 && degree < 270)
		return (3);
	if (degree >= 270 && degree <= 360)
		return (4);
	return (0);
}
