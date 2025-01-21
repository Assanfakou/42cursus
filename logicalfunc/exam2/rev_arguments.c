#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
    int i;

    if (ac >= 2)
    {
         ac -= 1;
        while (ac > 0)
        {
            i = 0;
            while (av[ac][i])
            {
                write(1, &av[ac][i], 1);
                i++;
            }
            write(1, "\n", 1);
            ac--;
        }
    }
}