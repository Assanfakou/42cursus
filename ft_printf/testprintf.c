
#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void *printstr(char *st)
{
    int i;

    i = 0;
    while (st[i])
    {
        ft_putchar(i);
        i++;
    }
}
int testft_print(const char *str, ...)
{
    va_list arg;
    va_start(arg, str);
    
}
int main ()
{
    ft
}