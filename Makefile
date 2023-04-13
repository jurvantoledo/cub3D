NAME = cub3D
CC = gcc
FLAGS = -Wall -Werror -Wextra
LFLAGS := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

LIBFT = include/libft
MLX_DIR = ./libs/MLX42
HEADERS	:= -I ./libs/MLX42/include/MLX42
MLX_LIB	:= $(MLX_DIR)/libmlx42.a

SRC =	src/main.c \
		src/parser/parse_map.c \
		src/parser/parse_elements.c \
		src/parser/parse_height.c \
		src/parser/parse_width.c \
		src/parser/validate_map.c \
		src/parser/checks.c \
		src/parser/check_world_map.c \
		src/parser/check_whole_world_map.c \
		src/parser/remove_newline_in_map.c \
		src/parser/more_shit.c \
		src/textures/textures.c \
		src/hooks/hook.c \
		src/hooks/move_hooks.c \
		src/hooks/look_hooks.c \
		src/raycasting/setup.c \
		src/raycasting/raycaster.c \
		src/raycasting/calc.c \
		src/raycasting/get_textures.c \
		src/error/error.c \
		src/free/free.c \
		src/utils/utils.c \
		include/gnl/get_next_line_utils.c \
		include/gnl/get_next_line.c

OBJ = ${SRC:%.c=%.o}

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT)/libft.a $(MLX_LIB) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	cd $(MLX_DIR) && cp ./libmlx42.a ../../

libft:
	@$(MAKE) -C $(LIBFT)

clean:
	rm -f $(OBJ)
	@rm -f $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re