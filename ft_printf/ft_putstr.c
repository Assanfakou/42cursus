#include "printf.h"

i r *st)
{
    int i;
    int re;

    re = 0;
    i = 0;
    while (st[i])
    {
        re += ft_putchar(st[i]);
        i++;
    }
    return (re);
}