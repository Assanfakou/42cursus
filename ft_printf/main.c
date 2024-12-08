#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>

void sum(int i, ...)
{
    va_list arg;
    va_start(arg, i);
    printf("%u\n", arg->fp_offset);
    // va_arg(arg, double);
    printf("%d\n", *(int*)(arg->reg_save_area + 8));
    printf("%d\n", *(int*)(arg->reg_save_area + 16));
    printf("%d\n", *(int*)(arg->reg_save_area + 24));
    printf("%d\n", *(int*)(arg->reg_save_area + 32));
    printf("%d\n", *(int*)(arg->reg_save_area + 40));
    printf("%d\n", *(int*)(arg->overflow_arg_area));
    printf("%d\n", *(int*)(arg->overflow_arg_area+8));
    printf("%f\n", *(double*)(arg->reg_save_area + 48));


}
int main()
{
    sum(2, 1,2,3,4,5,6,7,1.3);
}