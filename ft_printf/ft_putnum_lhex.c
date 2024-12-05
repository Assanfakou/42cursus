#include "printf.h"


int ft_putnum_lhex(unsigned int nb)
{
 int  re;
 char *base;

 re = 0;
 base = "0123456789abcdef";
 if (nb >= 16)
 {
    re += ft_putnum_lhex(nb / 16);
    re += ft_putnum_lhex(nb % 16);
 }
 else
    re += ft_putchar(base[nb]);
 return (re);
}