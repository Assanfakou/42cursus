#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ptnbr(int i)
{
    if (i > 9)
        ptnbr(i / 10);
    ft_putchar((i % 10) + '0');
}
int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int signe = 1;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * signe);
}


#include <stdio.h>

int main (int ac, char **av)
{
    int i;
    int atoi = 0;
    int total = 0;

    i = 1;
    while (i <= 9)
    {
        atoi = ft_atoi(av[1]);
        ptnbr(i);
        write(1, " ", 1);
        write(1, "x", 1);
        write(1, " ", 1);
        ptnbr(atoi);
        write(1, " ", 1);
        write(1, "=", 1);
        write(1, " ", 1);
        total = atoi * i;
        ptnbr(total);
        write(1, "\n", 1);
        i++;
    }
}