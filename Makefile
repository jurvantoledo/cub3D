NAME = cub3d
CC = gcc
FLAGS = 
LFLAGS := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

LIBFT = include/libft
MLX_DIR = ./libs/MLX42
HEADERS	:= -I ./libs/MLX42/include/MLX42
MLX_LIB	:= $(MLX_DIR)/build/libmlx42.a


SRC =	src/main.c \
		src/parser/parse_map.c \
		src/parser/parse_textures.c \
		src/parser/parse_floor_ceiling.c \
		src/parser/parse_lat_long.c \
		src/parser/validate_map.c \
		src/textures/textures.c \
		src/hooks/hook.c \
		src/hooks/move_hooks.c \
		src/exec/setup.c \
		src/utils/utils.c \
		src/error/error.c \
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