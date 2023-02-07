#include "cub3d.h"

int	check_collision(t_data *data, char direction)
{
	double	wx;
	double	wy;
	double	wangle;

	if (direction == 'S')
	{
		wangle = degtorad(data->player.degree);
		wx = data->player.x_pos - cos(wangle) * 0.2;
		wy = data->player.y_pos + sin(wangle) * 0.2;
	}
	if (direction == 'W')
	{
		wangle = degtorad(data->player.degree);
		wx = data->player.x_pos + cos(wangle) * 0.2;
		wy = data->player.y_pos - sin(wangle) * 0.2;
	}
	if (direction == 'D')
	{
		wangle = degtorad(data->player.degree + 90);
		wx = data->player.x_pos + cos(wangle) * 0.2;
		wy = data->player.y_pos - sin(wangle) * 0.2;
	}
	if (direction == 'A')
	{
		wangle = degtorad(data->player.degree - 90);
		wx = data->player.x_pos + cos(wangle) * 0.2;
		wy = data->player.y_pos - sin(wangle) * 0.2;
	}
	if (wy < 0 || wx < 0)
		return (1);
	if ((int)ceil(wy) > two_d_strlen(data->map.map) - 1)
		return (1);
	if ((size_t)ceil(wx) > ft_strlen(data->map.map[(int)ceil(wy)]) - 1)
		return (1);
	if (data->map.map[(int)ceil(wy)][(int)ceil(wx)] == 1)
		return (1);
	return (0);
}

void	move_player(t_data *data, char direction)
{
	if (check_collision(data, direction))
		return ;
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
	check_collision(data, direction);
}