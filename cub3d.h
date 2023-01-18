#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include "mlx/mlx.h"

# define SIZE 256

typedef struct s_hex
{
	int		colour;
	char	*key;
}			t_hex;

typedef struct s_hash
{
	t_hex	**items;
	int		size;
	int		count;
}			t_hash;

typedef struct s_texture
{
	int		fd;
	char	*path;
	t_hash	colours;
	char	**texture;
	char	**file;
}			t_texture;

typedef struct s_map
{
	int		fd;
	char	**map;
	char	*path;
	char	**file;
}		t_map;

typedef struct s_data
{
	t_map		map;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	void		*mlx;
	void		*win;
	int			height;
	int			width;
}			t_data;

int	parse_map(t_data *data);
int	parse_texture(t_data *data);
void test_exec(t_data *data);
int	hextoi(char *hex);

#endif