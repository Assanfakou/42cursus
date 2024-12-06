#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int     ft_putnbr(int n);
int     ft_putstr(char *st);
int     ft_putchar(char c);
int     ft_putnum_uhex(unsigned int nbr);
int     ft_putnum_lhex(unsigned int nb);
int     ft_uuputnb(unsigned int nbs);
int     ft_putaddre(unsigned long add);
int ft_checker(va_list arg, char s);
int ft_printf(const char *firstpar, ... );