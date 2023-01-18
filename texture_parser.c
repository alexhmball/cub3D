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
		printf("valid\n");
		return (1);
	}
	return(0);
}