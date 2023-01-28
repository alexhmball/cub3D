/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:41:46 by ballzball         #+#    #+#             */
/*   Updated: 2023/01/28 21:28:32 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	find_vert_wall(t_data *data)
// {

// }

// void	find_horiz_wall(t_data *data)
// {

// }

void drawline(int x0, int y0, int x1, int y1, t_data *data)
{
	int	dx;
	int	dy;
	int	p;

	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * dy - dx;
	while (x0 < x1)
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(data, x0, y0, 0x00FF0000);
			y0++;
			p += 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(data, x0, y0, 0x00FF0000);
			p += 2 * dy;
		}
		x0++;
	}
}

void cast_ray(t_data *data)
{
	
}