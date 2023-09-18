NAME = cub3D_bonus

CC = clang

MLX_LIB = libmlx.a

FLAGS = -Wall -Wextra -Werror

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = main.c \
		engine/utils1.c \
		engine/mini_map.c \
		engine/render_map.c \
		engine/initialize.c \
		engine/player_hooks.c \
		engine/hooks_utils.c \
		engine/dda_version.c \
		engine/initialize_utils.c \
		engine/animation.c \
		engine/hit_wall_checker.c \
		engine/fake_3d.c \
		engine/dda_utils.c \
		engine/set_textuers.c \
		parcing/get_next_line.c\
		parcing/ft_split.c \
		parcing/function_libft_used.c \
		parcing/function_libft.c \
		parcing/fun_read_and_partition_map.c \
		parcing/fun_used_check_map_in_main.c \
		parcing/function_check_map.c \
		parcing/function_check_texter.c \
		parcing/fun_check_newline.c \
		parcing/check_plus_texter.c

OBJ = ${SRC:.c=.o}

%.o: %.c
	$(CC) ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@


${NAME}: ${LIBFT} ${OBJ}
	$(CC) ${FLAGS} $(OBJ) ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: ${NAME}

${LIBFT}:
	@make -C ./libft
	@make -C ./libft clean
	@mv ./libft/libft.a .


clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}
	@rm -f ${LIBFT}

re: fclean all

COM = "cub3D"
VAR = "pull"
git:
	git add .
	git commit -m ${COM}
	git ${VAR}

#bonus:
