
#include "printf.h"

int ft_checker(va_list arg, char s)
{
    int i;

    if (s == 'd' || s == 'i')
        i = ft_putnbr(va_arg(arg, int));
    else if (s == 'x')
        i = ft_putnum_lhex(va_arg(arg, unsigned int));
    else if (s == 'X')
        i = ft_putnum_uhex(va_arg(arg, unsigned int));
    else if (s == 's')
        i = ft_putstr(va_arg(arg, char *));
    else if (s == 'c')
        i = ft_putchar(va_arg(arg, int));
    else if (s == 'u')
        i = ft_uuputnb(va_arg(arg, unsigned int));
/*    else if (s == 'p')
        i = ft_putaddre(va_arg(arg, unsigned long));*/
    return (i);
}

int ft_printf(const char *firstpar, ... )
{
    int i;
    int vas;
    va_list arg;

    va_start(arg, firstpar);
    i = 0;
    while (firstpar[i] != '\0')
    {
        if (firstpar[i] == '%')
        {
            if (firstpar[i + 1] != '\0')
            {
                vas += ft_checker(arg, firstpar[i + 1]);
                i++;
            }
        }
        else 
            vas += ft_putchar(firstpar[i]);
        i++;
    }
    return (vas);
}
int main ()
{
    int num = 12;
    char *str = "hello dear";
    printf("[%d]", ft_printf("hello %s", str));
}