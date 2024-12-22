#include "ft_printf.h"
#include <stdio.h>  

int main ()
{
    int i = 42;
    void    *ptr = &i;
    ft_printf("%p\n", ptr);
    printf("%p", &i);
}