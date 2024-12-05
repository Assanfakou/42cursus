#include "printf.h"

int     ft_putaddre(void *ptr)
{
    int re;
    unsigned long pr;

    pr = (unsigned long) ptr;
    re = 0;
    re += ft_putchar('0');
    re += ft_putchar('x');
    re += ft_putnum_lhex((unsigned long)pr);
    return (re);
}
int main ()
{
    printf(" numprinted[%d]", ft_putaddre("e"));
}