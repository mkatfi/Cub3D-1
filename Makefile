NAME = cub3D

LIBMLX = libmlx.a

SRC = main.c GNL/get_next_line.c GNL/get_next_line_utils.c src/utils1.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wextra -Wall -Werror -fsanitize=address

MLX = -lmlx -framework OpenGL -framework AppKit

${NAME}: ${LIBMLX} ${OBJ}
	@cc ${CFLAGS} ${OBJ} ${MLX} -o ${NAME}

all: ${NAME}

${LIBMLX}:
	@make -C ./mlx
	@make -C ./mlx clean
	@mv ./mlx/libmlx.a .



clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}
	@rm -f ${LIBMLX}

re: fclean all

#bonus: