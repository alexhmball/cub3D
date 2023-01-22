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
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

# define SIZE 256

typedef struct s_hex
{
	int		colour;
	char	*key;
	struct s_hex	*next;
}			t_hex;

typedef struct s_texture
{
	int		fd;
	char	*path;
	t_hex	**colours;
	int		c_num;
	int		c_size;
	char	**texture;
	char	**file;
	void	*xpm;
}			t_texture;

typedef struct s_map
{
	int		fd;
	int		height;
	int		width;
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
	int			floor;
	int			ceiling;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			height;
	int			width;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}			t_data;

int	parse_map(t_data *data);
int	parse_texture(t_data *data);
void test_exec(t_data *data);
int	hextoi(char *hex);
unsigned int hash_key(char *str);
t_hex	**create_table(void);
t_hex	*create_hex(char *key, char *colour, t_hex *new);
t_hex	**insert_hex(t_hex **hash_table, char *key, char *colour);
int		find_hex_colour(char *key, t_hex **hash_table, int size);

#endif