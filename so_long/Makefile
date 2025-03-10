CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/check_erour.c mandatory/parse.c mandatory/player.c mandatory/utils.c mandatory/main.c mandatory/flood_fill.c 

SRC_BNS = bonus/check_erour.c bonus/parse.c bonus/player.c bonus/utils.c bonus/main.c bonus/flood_fill.c

OBG_SRC = $(SRC:%.c=%.o)

OBG_BNS_SRC = $(SRC_BNS:%.c=%.o)

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long

all: $(LIBFT) $(NAME)


$(LIBFT):
	${MAKE} -C LIBFT_DIR

$(NAME): $(LIBFT) $(OBG_SRC)
	$(CC) $(OBG_SRC) -L $(LIBFT_DIR) -lft -lmlx -lXext -lX11 -o $(NAME)

clean:
	rm *.o


