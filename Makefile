NAME = cub3D

LIBMLX = libmlx.a

LIBFT = libft.a

SRC = main.c cub3D_iantar/utils1.c cub3D_iantar/player.c cub3D_iantar/render_map.c \
		cub3D_iantar/player_hooks.c cub3D_iantar/slow_version.c \
			./cub3D_aouaziz/parsing/cub3D.c \
			./cub3D_aouaziz/parsing/parsing_file.c \
			./cub3D_aouaziz/parsing/textur_lst.c \
			./cub3D_aouaziz/parsing/reading_map.c \
			./cub3D_aouaziz/parsing/ft_print.c \
			./cub3D_aouaziz/parsing/check_map.c \
			./cub3D_aouaziz/parsing/check_player.c \
			./cub3D_aouaziz/parsing/check_null.c \
			./cub3D_aouaziz/parsing/color_textur.c \

OBJ = ${SRC:.c=.o}

CFLAGS = -Wextra -Wall -Werror -fsanitize=address

MLX = -lmlx -framework OpenGL -framework AppKit

${NAME}: ${LIBMLX} ${LIBFT} ${OBJ}
	@cc ${CFLAGS} ${LIBFT} ${OBJ} ${MLX} -o ${NAME}

all: ${NAME}

${LIBFT}:
	@make -C ./libft
	@make -C ./libft clean
	@mv ./libft/libft.a .

${LIBMLX}:
	@make -C ./mlx
	@make -C ./mlx clean
	@mv ./mlx/libmlx.a .

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}
	@rm -f ${LIBMLX}
	@rm -f ${LIBFT}

re: fclean all

COM = "cub3D"
VAR = "pull"
git:
	git add .
	git commit -m ${COM}
	git ${VAR}

#bonus:
