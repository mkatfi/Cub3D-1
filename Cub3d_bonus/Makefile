NAME = cub3D

CC = clang

MLX_LIB = libmlx.a

LIBFT = libft.a

FLAGS = -Wall -Wextra -Werror  -fsanitize=address -g3

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = main.c cub3D_iantar/utils1.c cub3D_iantar/render_map.c \
		cub3D_iantar/player_hooks.c cub3D_iantar/dda_version.c cub3D_iantar/animation.c \
		cub3D_iantar/fake_3d.c cub3D_iantar/set_textuers.c \
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

%.o: %.c
	$(CC) ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@
	

#MLX = -lmlx -framework OpenGL -framework AppKit

${NAME}: ${LIBFT} ${OBJ}
	$(CC) ${FLAGS} $(OBJ) ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#@${CC} ${FLAGS} ${MLX} ${MLX_LIB} ${OBJ}   -o ${NAME}
#	cc $(OBJ)  -o $(NAME)

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
