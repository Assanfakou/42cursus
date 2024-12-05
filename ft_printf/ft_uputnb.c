#include "printf.h"

int ft_uputnb(unsigned int n)
{
    int i;

    i = 0;
    if (n > 9)
        i += ft_uputnb(n / 10);
    i += ft_putchar((n % 10) + '0');
    return (i);
}