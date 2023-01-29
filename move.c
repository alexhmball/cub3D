#include "cub3d.h"

void	move_player_w(t_data *data, char direction)
{
	if (direction == 'W')
	{
		data->player.y_pos += cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'S')
	{
		data->player.y_pos -= cos(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += sin(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'A')
	{
		data->player.y_pos += sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos += cos(degtorad(data->player.degree)) * 0.1;
	}
	if (direction == 'D')
	{
		data->player.y_pos -= sin(degtorad(data->player.degree)) * 0.1;
		data->player.x_pos -= cos(degtorad(data->player.degree)) * 0.1;
	}
}