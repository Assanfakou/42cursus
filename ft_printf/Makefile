cc = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_checker.c ft_printf.c ft_putaddr.c ft_putchar.c ft_putnbr.c ft_putnum_lhex.c ft_putnum_uhex.c\
	ft_putstr.c ft_uputnb.c 

OBJ = $(SRC:%.c=%.o)

NAME = ft_printf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?
%.o: %.c
	$(cc) $(CFLAGS) -c $^ -o $@
clean:
	rm -rf *.o

fclean : clean
	rm -rf *.a
re: fclean all
