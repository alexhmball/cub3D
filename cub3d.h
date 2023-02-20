/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:52:55 by ballzball         #+#    #+#             */
/*   Updated: 2023/02/14 21:07:16 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	degree;
	double	move;
	t_ray	ray;
	char	direction;
}		t_player;

typedef struct s_map
{
	int			fd;
	int			height;
	int			width;
	char		**map;
	char		*path;
	char		**file;
	char		*file_name;
	int			row;
	int			col;
	t_player	*player;
}		t_map;


typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	char		**cub_file;
	t_color		floor;
	t_color		ceiling;
	int			f;
	int			c;
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
void	parse_cub(t_data *data, int ac, char **av);
void	ft_check_arg(int ac, char **av);
void	ft_perror(char *msg);
int		ft_strlen(char *s);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strrchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strndup(char *s1, int n);
char	**ft_split(char *str, char *d);
void	free_split(char **tab);
int		ft_atoi(const char *str);
char	*ft_gnl(int fd);
int		ft_count_lines(char *filename);
void	ft_get_cub_file(t_data *data);
void	ft_check_texture(char **file, int *i);
void	get_textures(t_data *data);
void	ft_check_fc(char **file, int *i);
void	get_fc(t_data *data);
void	get_rgb(t_color *color, char **str);
void	ft_check_cub_file(char **file);
int		ft_charcheck(char c, char *set);
void	ft_get_map(t_data *data);
void	check_map(char **map);
int		check_new_line(char *str);
int		get_map_len(t_data *data);
int		ft_player_space_detect(char **map, int row, int col);
void	get_player(t_map *map);
void	check_map_all(t_data *data);
int		two_d_strlen(char **str);
void	set_up_ptr(t_data *data);
void	set_direction(t_data *data);
int		check_extended_wall(char **map, int row);
int		check_wall_(char **map, int row, int i);
int		check_wall(char **map, int row, int col);
void	map_checks_(t_data *data, int row, int col);
void 	ft_free(t_data *data);
void	ft_free2darray(char **c);

#endif