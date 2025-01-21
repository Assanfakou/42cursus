#include <unistd.h>
#include <stdio.h>

int ft_check(char *str, char c, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (str[i] == c)
        {
            return (1);
        }
        i++;
    }
    return (0);
}
int main (int ac, char **av)
{
    int i;
    int j;

    if (ac == 3)
    {
        i = 0;
        while (av[1][i])
        {
            if (ft_check(av[1], av[1][i], i) == 0)
            {
                write(1, &av[1][i], 1);
            }
            i++;
        }
        j = 0;
        while (av[2][j])
        {
            if(ft_check(av[1], av[2][j], i) == 0 && ft_check(av[2], av[2][j], j) == 0)
            {
                write(1, &av[2][j], 1);
            }
            j++;
        }
    }
    write(1, "\n", 1);
}