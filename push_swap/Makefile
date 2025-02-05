CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FIL = operations.c fsplit.c parssing.c link_lst_utils.c helper_pars.c \

OBJ_FILE = $(SRC_FIL:%.c=%.o)


NAME = push_swap.a

all : $(NAME)

$(NAME): $(OBG_FILE)
	ar rcs $(NAME) $(OBJ_FILE)

$(OBJ_FILE): $(SRC_FIL)
	gcc $(CFLAGS) -c $^ -o $@

clean :
	rm *.o
fclean : clean
	rm *.a