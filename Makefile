# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 17:54:03 by aball             #+#    #+#              #
#    Updated: 2023/02/20 21:22:04 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

ARC = $(shell uname)

GNL = get_next_line.c get_next_line_utils.c

SCRS = main.c test.c hextoi.c rgb.c player.c math_utils.c \
	ray_cast.c move.c walls.c cub3D.c utils.c utils2.c gnl_utils.c parse_cub.c map.c \
	map2.c textures.c fc.c ft_split2.c player_parser.c texture_parser.c utils3.c

SCRS += $(addprefix get_next_line/, $(GNL))

OBJS = ${SCRS:c=o}

ifeq (${ARC}, Darwin)
LINKS = -framework OpenGL -framework Appkit -L mlx/ -lmlx

OS = MACOS

LIBDIR = mlx/
endif

ifeq (${ARC}, Linux)
LINKS = -L mlx_linux/ -lmlx -lXext -lX11 -lm -lz

OS = LINUX

LIBDIR = mlx_linux/
endif

all: $(NAME)

$(NAME):  mlx ${OBJS}
	gcc -fsanitize=address -O3 -Wall -Wextra -Werror -D ${OS} ${OBJS} ${LINKS} -lm -o ${NAME}

%.o:%.c
	gcc -O3 -g -Wall -Wextra -Werror -D ${OS} -c $< -o ${<:c=o}

clean:
	rm -fr ${OBJS}
	make clean -C ${LIBDIR}

fclean: clean
	rm -fr ${NAME}

re: fclean all

mlx:
	make -C ${LIBDIR}

.PHONY: all re clean fclean mlx libft