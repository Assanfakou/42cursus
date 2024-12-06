#include "ft_printf.h"

int     ft_putaddre(unsigned long add)
{
    int re;
    int d;
    char *base;

    base = "0123456789abcdef";
    re = 0;
    if (add >= 16)
    {
        re = ft_putaddre(add / 16);
    }
    else
        re += ft_putchar(base[add % 16]);
    return (re);
}
int main ()
{
    int jd = 3;
    void *pr = &jd;

    ft_printf()
}