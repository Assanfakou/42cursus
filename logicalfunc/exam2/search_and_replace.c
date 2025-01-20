#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
    int i;
    int j;

    j = 0;   
    if (ac == 4)
    {
        i = 0;
        while (av[1][i])
        {
            if (av[1][i] == *av[2])
            {
                write(1, &av[3][j], 1);
                // i++;
            }
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}