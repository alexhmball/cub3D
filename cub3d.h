#ifndef CUB3D_H
# define CUB3D_H

# ifdef LINUX
#  include "mlx_linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
#endif

# ifdef MACOS
#  include "mlx/mlx.h"
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>


# define FOV 90
# define SCREEN_W FOV * 20
# define SCREEN_H 1000
# define STEP 1
# define BLOCK 64
# define HORIZONTAL 0
# define VERTICAL 1
# define NORTH 0x0000FF
# define SOUTH 0x00FF00
# define EAST 0xFF0000
# define WEST 0xFFFF00

// testing hashmaps
// # define SIZE 256

// typedef struct s_hex
// {
// 	int		colour;
// 	char	*key;
// 	struct s_hex	*next;
// }			t_hex;

typedef struct s_ray
{
	double	x;
	double	y;
	double	prev_x;
	double	prev_y;
	double	angle;
}		t_ray;


typedef struct s_texture
{
	int		fd;
	char	*path;
	char	**texture;
	char	**file;
	void	*xpm;
	char	*addr;
	int		x;
	int		y;
	int		height;
	int		width;
	int		bits;
	int		line;
	int		endian;
	int		step;
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

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	degree;
	double	radian;
	t_ray	ray;
	char	direction;
}		t_player;

typedef struct s_data
{
	t_map		map;
	t_player	player;
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

int		parse_map(t_data *data);
int		parse_texture(t_data *data);
void	place_ceiling_floor(t_data *data);
int		hextoi(char *hex);
int		rgbtoi(int r, int g, int b);
int		parse_player(t_data *data);
double	radtodeg(double rad);
double	degtorad(double deg);
double	distance(double x, double y, double x2, double y2);
double	check_angle(double angle);
void	drawline(int x0, int y0, int x1, int y1, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour);
void	cast_ray(t_data *data);
int		find_quadrant(double degree);
void	move_player_w(t_data *data, char direction);

// testing hash maps
// unsigned int	hash_key(char *str);
// t_hex	**create_table(void);
// t_hex	*create_hex(char *key, char *colour, t_hex *new);
// t_hex	**insert_hex(t_hex **hash_table, char *key, char *colour);
// int		find_hex_colour(char *key, t_hex **hash_table, int size);

#endif