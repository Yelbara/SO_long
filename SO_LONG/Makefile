NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc

MLX_DIR = /usr/include/minilibx-linux/
MLX = $(MLX_DIR)/libmlx_Linux.a

LINKS = -L $(MLX_DIR) -lmlx -lX11 -lXext -lm

SRCS = src/main.c src/move.c src/read_map.c src/initialize_map.c \
       src/valid_v1_map.c src/valid_v2_map.c src/destroy_and_clean.c \
       src/helper_move.c src/libft.c  src/libft_v2.c

SRCBS = src_bonus/main_bonus.c src_bonus/move_bonus.c src_bonus/read_map_bonus.c src_bonus/initialize_map_bonus.c \
       src_bonus/valid_v1_map_bonus.c src_bonus/valid_v2_map_bonus.c src_bonus/destroy_and_clean_bonus.c \
       src_bonus/helper_move_bonus.c src_bonus/libft_bonus.c src_bonus/libft_v2_bonus.c src_bonus/setting_map.c

OBJS = $(SRCS:.c=.o)

OBJBS = $(SRCBS:.c=.o)

INCLUDE = -I ./includes -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) $(LINKS)


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MLX) $(OBJBS)
	$(CC) $(CFLAGS) $(OBJBS) $(MLX) -o $(NAME_BONUS) $(LINKS)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus