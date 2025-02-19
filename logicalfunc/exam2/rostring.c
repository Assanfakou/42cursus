#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int ac, char **av)
{
    int i;
    char arr[100];

    if (ac == 2)
    {
        i = 0;
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i] && av[1][i] != ' ')
            i++;
        strncpy(arr, av[1], i);
        i++;
        while (av[1][i])
        {
            if (av[1][i] == ' ' || av[1][i] == '\t')
            {
                if (av[1][i + 1] > 32 && av[1][i + 1] != '\0')
                    write (1, " ", 1);
            }
            else if (av[1][i] != ' ' || av[1][i] != '\t')
                write (1, &av[1][i], 1);
            i++;
        }
        write (1, " ", 1);
        int j = 0;
        while (arr[j])
        {
            if (arr[j] != ' ')    
                write (1, &arr[j], 1);
            j++;
        }
    }
}