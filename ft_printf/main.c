#include "ft_printf.h"
void ft_chhfjf(int i, ...)
{
    va_list asa;

    va_start(asa, i);
    printf("%d", (int *)asa->reg_save_area + 8);
}
int main ()
{
    ft_chhfjf(2, 35,27,23,24);
}