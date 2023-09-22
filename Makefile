NAME = cub3D

NAME_BONUS = cub3D_bonus

CC = clang

MLX_LIB = libmlx.a

FLAGS = -Wall -Wextra -Werror

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC =	mandatory/main.c mandatory/engine/initilize.c \
		mandatory/engine/utils1.c mandatory/engine/hooks_utils.c \
		mandatory/engine/render_map.c \
		mandatory/engine/player_hooks.c \
		mandatory/engine/dda_version.c \
		mandatory/engine/fake_3d.c \
		mandatory/engine/set_textuers.c \
		mandatory/parcing/get_next_line.c\
		mandatory/parcing/ft_split.c \
		mandatory/parcing/function_libft_used.c \
		mandatory/parcing/function_libft.c \
		mandatory/parcing/fun_read_and_partition_map.c \
		mandatory/parcing/fun_used_check_map_in_main.c \
		mandatory/parcing/function_check_map.c \
		mandatory/parcing/function_check_texter.c \
		mandatory/parcing/fun_check_newline.c \
		mandatory/parcing/check_plus_texter.c \
		mandatory/parcing/texters.c \

SRC_BONUS = bonus/main.c \
		bonus/engine/utils1.c \
		bonus/engine/mini_map.c \
		bonus/engine/render_map.c \
		bonus/engine/initialize.c \
		bonus/engine/player_hooks.c \
		bonus/engine/hooks_utils.c \
		bonus/engine/dda_version.c \
		bonus/engine/initialize_utils.c \
		bonus/engine/animation.c \
		bonus/engine/hit_wall_checker.c \
		bonus/engine/fake_3d.c \
		bonus/engine/dda_utils.c \
		bonus/engine/set_textuers.c \
		bonus/parcing/get_next_line.c\
		bonus/parcing/ft_split.c \
		bonus/parcing/function_libft_used.c \
		bonus/parcing/function_libft.c \
		bonus/parcing/fun_read_and_partition_map.c \
		bonus/parcing/fun_used_check_map_in_main.c \
		bonus/parcing/function_check_map.c \
		bonus/parcing/function_check_texter.c \
		bonus/parcing/fun_check_newline.c \
		bonus/parcing/check_plus_texter.c \
		bonus/parcing/texters.c \

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

%.o: %.c
	@$(CC) ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJ}
	@$(CC) ${FLAGS} $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

${NAME_BONUS}: ${OBJ_BONUS}
	@$(CC) ${FLAGS} $(OBJ_BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)

all: ${NAME}

clean:
	@rm -f ${OBJ} $(OBJ_BONUS)

fclean: clean
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all

bonus: ${NAME_BONUS}
