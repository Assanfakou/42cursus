#include <stdio.h>
#include <unistd.h>

int main (int ac, char **av)
{
    int i;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if (av[1][i] == '_')
            {
                av[1][i + 1] -= 32;
                write(1, &av[1][i + 1], 1);
            }
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}