NAME = cub3D

ARC = $(shell uname)

GNL = get_next_line.c get_next_line_utils.c

SCRS = main.c map_parser.c texture_parser.c test.c hextoi.c rgb.c player.c

SCRS += $(addprefix get_next_line/, $(GNL))

OBJS = ${SCRS:c=o}

ifeq (${ARC}, Darwin)
LINKS = -framework OpenGL -framework Appkit -L mlx/ -lmlx

LIBDIR = mlx/
endif

ifeq (${ARC}, Linux)
LINKS = -L mlx_linux/ -lmlx -lXext -lX11 -lm -lz

LIBDIR = mlx_linux/
endif

all: $(NAME)

$(NAME): libft mlx ${OBJS}
	gcc -g -fsanitize=address -Wall -Wextra -Werror ${OBJS} libft/libft.a ${LINKS} -lm -o ${NAME}

%.o:%.c
	gcc -g -Wall -Wextra -Werror -c $< -o ${<:c=o}

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