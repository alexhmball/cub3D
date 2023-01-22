#include "cub3d.h"

int	parse_map(t_data *data)
{
	int i;

	i = 0;
	data->map.fd = open(data->map.path, O_RDONLY);
	data->map.file = (char **)ft_calloc(1, sizeof(char *));
	data->map.map = (char **)ft_calloc(1, sizeof(char *));
	if (data->map.fd > 0)
	{
		data->map.file = append_str(data->map.file, get_next_line(data->map.fd));
		while (data->map.file[i])
		{
			data->map.file = append_str(data->map.file, get_next_line(data->map.fd));
			if (data->map.file[i][0] != '\n' && data->map.file[i][0] != 'C' && data->map.file[i][0] != 'F' && data->map.file[i][0] != 'N' && data->map.file[i][0] != 'S' && data->map.file[i][0] != 'W' && data->map.file[i][0] != 'E')
				data->map.map = append_str(data->map.map, ft_strdup(data->map.file[i]));
			i++;
		}
		data->north.path = data->map.file[0] + 3;
		data->north.path[ft_strlen(data->north.path) - 1] = 0;
		printf("valid");
		return (1);
	}
	perror(strerror(errno));
	return (0);
}