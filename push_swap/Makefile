CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FIL = main.c small_sort.c operations_part1.c operations_part2.c fsplit.c parssing.c link_lst_utils.c helper_pars.c sort_arr.c sort_help.c 

OBJ_FILE = $(SRC_FIL:%.c=%.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJ_FILE)
	$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)

clean :
	rm *.o
fclean : clean
	rm push_swap

re: fclean all