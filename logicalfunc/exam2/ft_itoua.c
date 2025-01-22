#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int count_num(int num)
{
    int i;

    i = 0;
    if (num <= 0)
        i += 1;
    while (num)
    {
        num /= 10;
        i++;
    }
    // printf("%d", i);
    return (i);
}
void ft_strcopy(char *dest, long num, int len)
{
    int i;

    dest[len] = '\0';
    if (num == 0)
    {
        dest[0] = '0';
        return ;
    }
    while(num)
    {
        dest[--len] = (num % 10) + '0';
        num /= 10; 
    }
}
char *ft_itoa2(int a)
{
    int size;
    char *str;
    long che;

    che = a;
    if (a < 0)
        che *= -1;
    else
        che = a;
    size = count_num(a);
    str = malloc(sizeof(char) * size + 1);
    if(!str)
        return (NULL);
    if (a < 0)
        str[0] = '-';
    ft_strcopy(str, che, size);

    return (str);
}
// #include "../../libft/libft.h"
int main ()
{
    char *str;
    str = ft_itoa2(0);
    printf("%s", str);
    // free(str);
}