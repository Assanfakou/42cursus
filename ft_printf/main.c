#include "ft_printf.h"

int main ()
{
    char *st = "hello Assan you are legend!";
    int s = 1211225;
    void *ptr = &s;
    char e = 'a';

    ft_printf("str : %s, \n digit = %d,\n address :%p,\n char : %c,\n {%%} the hex lower :%x and upper %X", st, s, (unsigned long)ptr, e, s, s);
    printf("str : %s, \ns = %d,m\n address :%p,\n char : %c,\n {%%} the hex lower :%x and upper %X", st, s, ptr, e, s, s);
}