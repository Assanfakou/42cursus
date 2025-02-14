CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FIL = main.c small_sort.c operations_part1.c operations_part2.c fsplit.c parssing.c link_lst_utils.c helper_pars.c sort_arr.c sort_help.c 

OBJ_FILE = $(SRC_FIL:%.c=%.o)	

PRINTF_DIR = print

PRINTF_RULE = $(PRINTF_DIR)/libftprintf.a

NAME = push_swap

all : $(PRINTF_RULE) $(NAME)

$(PRINTF_RULE):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJ_FILE) $(PRINTF_RULE)
	$(CC) $(CFLAGS) $(OBJ_FILE) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

clean :
	rm *.o
	make fclean -C $(PRINTF_DIR)
fclean : clean
	rm push_swap


re: fclean all