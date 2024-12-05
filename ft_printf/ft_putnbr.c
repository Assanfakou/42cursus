#include "printf.h"

int ft_putnbr(int n)
{
    unsigned int s;
    int se;

    se = 0;
    if (n < 0)
    {
        se += ft_putchar('-');
        s = -n;
    }
    else
        s = n;
    if (s > 9)
         se += ft_putnbr(s / 10);
    se += ft_putchar((s % 10) + '0');
    return (se);
}