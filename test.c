# include "cub3d.h"

void test_exec(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	hex;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	hex = hextoi("B5B6B7");
	while(i < 1000)
	{
		while( j < 1000)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, hex);
			j++;
			x++;
		}
		i++;
		y++;
		x = 0;
		j = 0;
	}
}