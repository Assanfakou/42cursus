#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ft_ptnbr(int nbr)
{
    unsigned int n;
    char c;
    if (nbr < 0)
    {
        write (1, "-", 1);
        nbr *= -1;
    }
    n = nbr;
    if (n > 9)
        ft_ptnbr(n / 10);
    c = (n % 10) + '0';
    write (1, &c, 1);
}
int main (int ac, const char **av)
{
    int i;
    int j;

    if (ac == 4)
    {
        i = 0;
        if (*av[2] == '*')
           ft_ptnbr(atoi(av[1]) * atoi(av[3]));
        else if (*av[2] == '-')
            ft_ptnbr(atoi(av[1]) - atoi(av[3]));
        else if (*av[2] == '+')
            ft_ptnbr(atoi(av[1]) + atoi(av[3]));
        else if (*av[2] == '/')
            ft_ptnbr(atoi(av[1]) / atoi(av[3]));
    }
}