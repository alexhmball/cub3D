#include "cub3d.h"

void	check_collision(t_data *data, double x, double y)
{
	if (data->map.map[(int)floor(data->player.y_pos)][(int)floor(data->player.x_pos)] == '1')
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
	if (direction == 'A')
	{
		data->player.y_pos -= sin(degtorad(check_angle(data->player.degree - 90))) * 0.1;
		data->player.x_pos += cos(degtorad(check_angle(data->player.degree - 90))) * 0.1;
	}
	if (direction == 'D')
	{
		data->player.y_pos -= sin(degtorad(check_angle(data->player.degree + 90))) * 0.1;
		data->player.x_pos += cos(degtorad(check_angle(data->player.degree + 90))) * 0.1;
	}
	check_collision(data, prev_x, prev_y);
}