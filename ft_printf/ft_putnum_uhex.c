#include "printf.h"

int ft_putnum_uhex(unsigned int nbr)
{
    int r;
    char *bas;

    bas = "0123456789ABCDEF";
    r = 0;
    if (nbr >= 16)
    {
        r = ft_putnum_uhex(nbr / 16);
        r = ft_putnum_uhex(nbr % 16);
    }
    else
        r += ft_putchar(bas[nbr]);
    return (r);
}
int main ()
{
    printf("printed dig %d", ft_putnum_uhex(1312));
}