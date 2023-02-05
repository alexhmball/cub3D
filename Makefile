NAME = cub3D

ARC = $(shell uname)

GNL = get_next_line.c get_next_line_utils.c

SCRS = main.c map_parser.c texture_parser.c test.c hextoi.c rgb.c player.c math_utils.c \
	ray_cast.c move.c

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

$(NAME): libft mlx ${OBJS}
	gcc -O3 -Wall -Wextra -Werror -D ${OS} ${OBJS} libft/libft.a ${LINKS} -lm -o ${NAME}

%.o:%.c
	gcc -O3 -Wall -Wextra -Werror -D ${OS} -c $< -o ${<:c=o}

clean:
	rm -fr ${OBJS}
	make clean -C ${LIBDIR}
	make clean -C libft

fclean: clean
	rm -fr ${NAME}
	make fclean -C libft

re: fclean all

mlx:
	make -C ${LIBDIR}

libft:
	make -C libft

.PHONY: all re clean fclean mlx libft