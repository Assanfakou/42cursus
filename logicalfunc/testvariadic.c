#include <stdio.h>
#include <stdarg.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int sum_them_all(int i, ...)
{
    va_list arg;
    va_start(arg, i);
    
    int h = 0;
    int sum = 0;
    while (h < i)
    {
        sum += va_arg(arg, int);
        h++;
    }
    return (sum);
}
int main(void)
{
    int sum;

    sum = sum_them_all(2, 98, 1024);
    printf("%d\n", sum);
    sum = sum_them_all(4, 98, 1024, 402, -1024);
    printf("%d\n", sum);    
    return (0);
}