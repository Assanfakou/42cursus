CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

SRC = mandatory/check_erour.c mandatory/parse.c mandatory/player.c mandatory/utils.c mandatory/main.c mandatory/flood_fill.c 

SRC_BNS = bonus/check_erour_bonus.c bonus/parse_bonus.c bonus/player_bonus.c bonus/utils_bonus.c bonus/main_bonus.c bonus/flood_fill_bonus.c

OBG_SRC = $(SRC:%.c=%.o)

OBG_BNS = $(SRC_BNS:%.c=%.o)

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long

all: $(LIBFT) $(NAME)

$(LIBFT):
	${MAKE} -C $(LIBFT_DIR)

bonus: $(OBG_SRC) $(OBG_BNS)
	$(CC) $(CFLAGS) $(OBG_BNS) -L $(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

$(NAME): $(LIBFT) $(OBG_SRC)
	$(CC) $(CFLAGS) $(OBG_SRC) -L $(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

clean:
	rm $(OBG_SRC) $(OBG_BNS)
	rm $(LIBFT_DIR)/*.o

fclean: clean
	rm so_long
	rm $(LIBFT)
re: fclean all
