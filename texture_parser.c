#include "cub3d.h"

int	parse_texture(t_data *data)
{
	int	i;

	i = 0;
	data->north.fd = open(data->north.path, O_RDONLY);
	if (data->north.fd > 0)
	{
		data->north.file = (char **)ft_calloc(1, sizeof(char *));
		data->north.file = append_str(data->north.file, get_next_line(data->north.fd));
		while (data->north.file[i])
		{
			data->north.file = append_str(data->north.file, get_next_line(data->north.fd));
			i++;
		}
		i = 4;
		while (i < 259)
		{
			printf(" %d ", (data->north.file[i][1] + data->north.file[i][2]) % 512);
			printf("%s", data->north.file[i++]);
		}
		printf("valid\n");
		return (1);
	}
	return(0);
}