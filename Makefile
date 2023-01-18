NAME = cub3D

GNL = get_next_line.c get_next_line_utils.c

SCRS = main.c map_parser.c texture_parser.c test.c hextoi.c

SCRS += $(addprefix get_next_line/, $(GNL))

OBJS = ${SCRS:c=o}

all: $(NAME)

$(NAME): libft mlx ${OBJS}
	gcc -Wall -Wextra -Werror ${OBJS} libft/libft.a -framework OpenGL -framework Appkit -L mlx/ -lmlx -lm -o ${NAME}

%.o:%.c
	gcc -Wall -Wextra -Werror -c $< -o ${<:c=o}

clean:
	rm -fr ${OBJS}
	make clean -C mlx
	make clean -C libft

fclean: clean
	rm -fr ${NAME}
	make fclean -C libft

re: fclean all

mlx:
	make -C mlx

libft:
	make -C libft

.PHONY: all re clean fclean mlx libft