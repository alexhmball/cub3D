#include "cub3d.h"

static void move_quad_one(t_data *data, char direction)
{
	if (direction == 'A')
	{
		data->player.y_pos += cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'D')
	{
		data->player.y_pos -= cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'W')
	{
		data->player.y_pos -= sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += cos(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'S')
	{
		data->player.y_pos += sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= cos(degtorad(data->player.degree)) * 0.1;
	}
}

static void	move_quad_two(t_data *data, char direction)
{
	if (direction == 'A')
	{
		data->player.y_pos += cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'D')
	{
		data->player.y_pos -= cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'S')
	{
		data->player.y_pos += sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += cos(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'W')
	{
		data->player.y_pos -= sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= cos(degtorad(data->player.degree)) * 0.1;
	}
}

static void	move_quad_three(t_data *data, char direction)
{
	if (direction == 'A')
	{
		data->player.y_pos += cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'D')
	{
		data->player.y_pos -= cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'W')
	{
		data->player.y_pos -= sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += cos(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'S')
	{
		data->player.y_pos += sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= cos(degtorad(data->player.degree)) * 0.1;
	}
}

static void	move_quad_four(t_data *data, char direction)
{
	if (direction == 'A')
	{
		data->player.y_pos += cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'D')
	{
		data->player.y_pos -= cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'S')
	{
		data->player.y_pos += sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= cos(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'W')
	{
		if (data->player.degree != 0)
			data->player.y_pos -= sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += cos(degtorad(data->player.degree)) * 0.1;
	}
}

void	move_player(t_data *data, char direction)
{
	int	quad;

	quad = find_quadrant(data->player.degree);
	printf("quad: %d angle: %f\n", quad, data->player.degree);
	if (quad == 1)
		move_quad_one(data, direction);
	if (quad == 2)
		move_quad_two(data, direction);
	if (quad == 3)
		move_quad_three(data, direction);
	if (quad == 4)
		move_quad_four(data, direction);
}