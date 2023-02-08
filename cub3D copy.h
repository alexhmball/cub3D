/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D copy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:59:46 by aalnaqbi          #+#    #+#             */
/*   Updated: 2023/02/08 17:55:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# include <string.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_texture
{
	int		fd;
	char	*path;
	char	**texture;
	char	**file;
	void	*xpm;
	char	*addr;
	int		height;
	int		width;
	int		bits;
	int		line;
	int		endian;
}			t_texture;

typedef struct s_player
{
	int		x_pos;
	int		y_pos;
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
	//
	char		*file_name;
	int			row;
	int			col;
	t_player	player;
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
	//
	t_color		floor;
	t_color		ceiling;
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
//
void	check_map_all(t_data *data);

int		check_extended_wall(char **map, int row);
int		check_wall_(char **map, int row, int i);
int		check_wall(char **map, int row, int col);
void	map_checks_(t_data *data, int row, int col);
void 	ft_free(t_data *data);
void	ft_free2darray(char **c);

#endif
