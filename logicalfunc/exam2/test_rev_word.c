#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i;
    int l;
    
    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
            i++;
        i--;
        while (i >= 0)
        {
            while (av[1][i] != ' ' && i >= 0)
                i--;
            l = i + 1;
            i--;
            while (av[1][l] != ' ' && av[1][l])
            {
                write (1, &av[1][l], 1);
                l++;
            }
            if (i > 0)
                write (1, " ", 1);
        }
    }
    write (1, "\n", 1);
}