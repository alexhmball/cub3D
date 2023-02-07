/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:53:37 by aball             #+#    #+#             */
/*   Updated: 2023/02/07 10:52:06 by aball            ###   ########.fr       */
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
