#include "ft_printf.h"

int ft_uuputnb(unsigned int n)
{
    int i;

    i = 0;
    if (n > 9)
        i = ft_uuputnb(n / 10);
    i += ft_putchar((n % 10) + '0');
    return (i);
}