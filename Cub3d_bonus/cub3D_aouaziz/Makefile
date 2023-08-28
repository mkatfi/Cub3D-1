NAME = cub3D

LIBFT = ../libft/


CFLAGS = -Wall -Wextra -Werror

CC = cc -fsanitize=address -g

#FSANITIZE = -fsanitize=address -g

SOURCES =	./parsing/cub3D.c \
			./parsing/parsing_file.c \
			./parsing/textur_lst.c \
			./parsing/reading_map.c \
			./parsing/ft_print.c \
			./parsing/check_map.c \
			./parsing/check_player.c \
			./parsing/check_null.c \
			./parsing/color_textur.c \


NC			= \033[0m
B_RED		= \033[1;31m
RED 		= \033[0;31m
PURPLE		= \033[0;35m
B_PURPLE	= \033[1;35m
PURPLE		= \033[1;34m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m

OBJECTS = $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)

all : $(NAME)

%.o: %.c
#	@echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(PURPLE)█\033[0m\c"

$(NAME): compile $(OBJECTS) $(LIBFT)libft.a  done 
	@$(CC) $(READLINE) $(OBJECTS)  $(LIBFT)libft.a -o  $(NAME)

$(LIBFT)libft.a :
	@make bonus -C $(LIBFT)

clean :
	@rm -f $(OBJECTS)
	@rm -f $(BOBJECTS)
	@echo "\033[0;33m•\033[0;33m\c"
	@echo "$(B_RED)🧹 Cleaning: $(RED) Minishell object files $(NC)"
	@make clean -C $(LIBFT)

fclean : clean
	@rm -f $(NAME)
	@echo "\033[0;33m••\033[0;33m\c"
	@echo "$(B_RED)🧹 Cleaning: $(RED) $(NAME) $(NC)"
	@make fclean -C $(LIBFT)

re : fclean all

compile	:
			@echo "\n$(PURPLE)[X] Compiling $(PURPLE)cub3D$(NC)\n"

done	:
			@echo "$(PURPLE) => 100%$(NC)\n"