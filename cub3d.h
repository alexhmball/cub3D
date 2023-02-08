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


# define FOV 60
# define SCREEN_W FOV * 20
# define SCREEN_H FOV * 20

typedef struct s_ray
{
	double	x;
	double	y;
	double	vx;
	double	vy;
	double	hx;
	double	hy;
	double	hx_inc;
	double	hy_inc;
	double	vx_inc;
	double	vy_inc;
	double	vert_len;
	double	horz_len;
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
	double	y;
	int		height;
	int		width;
	int		bits;
	int		line;
	int		endian;
	int		xstep;
	double		ystep;
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
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour);
void	cast_ray(t_data *data);
int		find_quadrant(double degree);
void	move_player(t_data *data, char direction);
int		get_colour(t_texture *img, int x, int y);
void	place_square(int x, int y, t_data *data, int size, int colour);
void	draw_wall_slice(t_data *data, int x);
int		check_vert_walls(t_data *data);
int		check_horiz_walls(t_data *data);
t_texture	*find_texture(t_data *data, double *distv, double *disth, double *w_height);

#endif