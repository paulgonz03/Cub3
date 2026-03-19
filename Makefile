NAME = cub3D

MLX_PATH = ./minilibx-linux
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a
CC = cc

SRC = cube.c free.c ./parser/map.c\
./parser/flood_fill.c ./parser/parser.c ./parser/coordinates.c ./parser/utils_parser.c ./parser/char_parser.c\
./raycast/raycast.c ./raycast/keys.c ./raycast/textures.c ./raycast/rays.c\
./raycast/draw_column.c ./raycast/key_movement.c ./raycast/ray_init.c\
./raycast/raycast_init.c ./raycast/rays_textures.c ./raycast/rays_utils.c\

SRC_BONUS = cube.c free.c ./parser/map.c\
./parser/flood_fill.c ./parser/parser.c ./parser/coordinates.c ./parser/utils_parser.c ./parser/char_parser.c\
./bonus/key_movement_bonus.c ./bonus/key_utils.c\
./bonus/raycast_bonus.c ./bonus/minimap.c ./raycast/keys.c ./raycast/textures.c ./raycast/rays.c\
./bonus/minimap_utils.c ./raycast/draw_column.c ./raycast/ray_init.c\
./raycast/raycast_init.c ./raycast/rays_textures.c ./raycast/rays_utils.c\

OBJS = ${SRC:%.c=objects/%.o}

OBJS_BONUS = ${SRC_BONUS:%.c=objects/%.o}

CFLAGS = -Wall -Wextra -Werror -g3 -I. -I/usr/include -I$(MLX_PATH) -I./libft -fsanitize=address
all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) -L$(MLX_PATH) -lX11 -lXext -lm -o $(NAME)

bonus: $(OBJS_BONUS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX) $(LIBFT) -L$(MLX_PATH) -lX11 -lXext -lm -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	@make all -sC ./libft

objects/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objects
	@make clean -sC ./libft
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make fclean -sC ./libft

re: fclean all

.PHONY: all clean fclean re bonus
