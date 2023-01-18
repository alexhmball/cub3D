#include "cub3d.h"

int	parse_map(t_data *data)
{
	int i;

	i = 0;
	data->map.fd = open(data->map.path, O_RDONLY);
	data->map.file = (char **)ft_calloc(1, sizeof(char *));
	if (data->map.fd > 0)
	{
		data->map.file = append_str(data->map.file, get_next_line(data->map.fd));
		while (data->map.file[i])
		{
			data->map.file = append_str(data->map.file, get_next_line(data->map.fd));
			i++;
			printf("valid");
		}
		data->north.path = data->map.file[0] + 3;
		data->north.path[ft_strlen(data->north.path) - 1] = 0;
		return (1);
	}
	perror(strerror(errno));
	return (0);
}