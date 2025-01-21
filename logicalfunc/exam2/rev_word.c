#include <stdio.h>
#include <unistd.h>
#include "../../libft/libft.h"

int main (int ac, char **av)
{
    int j;
    char *str;

    if (ac == 2)
    {
        j = 0;
        while (av[1][j])
            j++;
        str = malloc(sizeof(char) * j);
        j--;
        while (j >= 0)
        {
            int i = j;
            if (av[1][j] != ' ')
            {
                
            }
            j--;
        }
    }
}