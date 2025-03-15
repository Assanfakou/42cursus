CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FIL = main.c small_sort.c operations_part1.c operations_part2.c fsplit.c parssing.c link_lst_utils.c helper_pars.c sort_arr.c sort_help.c 

BNS_SRC = bonus/checker_bonus.c bonus/operations_part1_bonus.c bonus/operations_part2_bonus.c bonus/p_swap_bonus.c bonus/link_lst_utils_bonus.c \
		bonus/helper_pars_bonus.c bonus/fsplit_bonus.c bonus/parssing_bonus.c bonus/sort_arr_bonus.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c

OBJ_FILE = $(SRC_FIL:%.c=%.o)

OBJ_BNS = $(BNS_SRC:%.c=%.o)

NAME = push_swap

CHECK_NAME = checker

all : $(NAME)

bonus: $(CHECK_NAME)

$(CHECK_NAME): $(OBJ_BNS)
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $(CHECK_NAME)

$(NAME): $(OBJ_FILE)
	$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)

clean :
	$(RM) $(OBJ_FILE) $(OBJ_BNS)

fclean : clean
	$(RM) $(NAME) $(CHECK_NAME)
	
re: fclean all

.SECONDARY: $(OBJ_BNS) $(OBJ_FILE)
.PHONY: all clean fclean
