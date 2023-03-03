NAME = cub3d
CC = gcc
FLAGS = 

LIBFT = include/libft

SRC =	src/main.c \
		src/parser/parse_map.c \
		src/parser/parse_textures.c \
		src/parser/parse_floor_ceiling.c \
		src/parser/parse_lat_long.c \
		src/utils/utils.c \
		src/error/error.c \
		include/gnl/get_next_line_utils.c \
		include/gnl/get_next_line.c

OBJ = ${SRC:%.c=%.o}

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFT)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re