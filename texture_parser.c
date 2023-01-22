#include "cub3d.h"

int	parse_texture(t_data *data)
{
	int	i;
	char *tmp;
	char **tmp2;
	char *tmp3;

	i = 0;
	data->north.fd = open(data->north.path, O_RDONLY);
	if (data->north.fd > 0)
	{
		data->north.file = NULL;
		data->north.file = append_str(data->north.file, get_next_line(data->north.fd));
		while (data->north.file[i])
		{
			data->north.file = append_str(data->north.file, get_next_line(data->north.fd));
			i++;
		}
		tmp = ft_substr(data->north.file[3], 1, ft_strlen(data->north.file[3]) - 2);
		printf("%s\n", tmp);
		tmp2 = ft_split(tmp, ' ');
		for (int i = 0; i < 2; i++)
			printf("%s\n", tmp2[i]);
		data->height = ft_atoi(tmp2[0]);
		data->width = ft_atoi(tmp2[1]);
		data->north.c_num = ft_atoi(tmp2[2]);
		data->north.c_size = ft_atoi(tmp2[3]);
		free(tmp);
		data->north.colours = create_table();
		i = 4;
		while (data->north.file[i][0] == '"')
		{
			tmp = ft_substr(data->north.file[i], 1, data->north.c_size);
			tmp3 = ft_substr(data->north.file[i], ft_strlen(data->north.file[i]) - 6, 6);
			data->north.colours = insert_hex(data->north.colours, tmp, tmp3);
			printf("%s\n", tmp);
			i++;
		// 	printf(" %d ", (data->north.file[i][1] + data->north.file[i][2]) % 512);
		// 	printf("%s", data->north.file[i++]);
		}
		i++;
		data->north.texture = NULL;
		while (data->north.file[i][0] == '"')
		{
			data->north.texture = append_str(data->north.texture, ft_substr(data->north.file[i], 1, ft_strlen(data->north.file[i]) - 2));
			i++;
		}
		printf("valid\n");
		return (1);
	}
	return(0);
}