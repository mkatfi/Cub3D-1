
NAME = cub3D

CC = clang

MLX_LIB = libmlx.a

FLAGS = -Wall -Wextra -Werror

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = src/main.c \
		src/engine/utils1.c \
		src/engine/mini_map.c \
		src/engine/render_map.c \
		src/engine/initialize.c \
		src/engine/player_hooks.c \
		src/engine/hooks_utils.c \
		src/engine/dda_version.c \
		src/engine/initialize_utils.c \
		src/engine/animation.c \
		src/engine/hit_wall_checker.c \
		src/engine/fake_3d.c \
		src/engine/dda_utils.c \
		src/engine/set_textuers.c \
		src/parcing/get_next_line.c\
		src/parcing/ft_split.c \
		src/parcing/function_libft_used.c \
		src/parcing/function_libft.c \
		src/parcing/fun_read_and_partition_map.c \
		src/parcing/fun_used_check_map_in_main.c \
		src/parcing/function_check_map.c \
		src/parcing/function_check_texter.c \
		src/parcing/fun_check_newline.c \
		src/parcing/check_plus_texter.c \
		src/parcing/texters.c \

OBJ = ${SRC:.c=.o}

%.o: %.c
	@$(CC) ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJ}
	@$(CC) ${FLAGS} $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: ${NAME}

clean:
	@rm -f ${OBJ} $(OBJ)

fclean: clean
	@rm -f ${NAME} ${NAME}

re: fclean all
