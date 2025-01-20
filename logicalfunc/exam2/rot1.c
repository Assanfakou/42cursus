#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
    int i;
    int j;
    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Y')
            {
                av[1][i] = av[1][i] + 1;
                write(1, &av[1][i], 1);
            }
            else if (av[1][i] == 'Z')
            {
                write(1, "A", 1);
            }
            else
                write(1, &av[1][i], 1);
            i++;
        }        
    }
                write(1, "\n", 1);
}


                // j = 0;
                // while (upper_buffer[j])
                // {
                //     if (upper_buffer[j] == av[1][i])
                //     {
                //         write(1, &upper_buffer[j + 1], 1);
                //     }
                //     j++;
                // }