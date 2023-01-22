# include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

void test_exec(t_data *data)
{
	for (int i = 0; data->map.map[i]; i++)
	{
		printf("%s\n", data->map.map[i]);
	}
	//loop through map and draw walls

}