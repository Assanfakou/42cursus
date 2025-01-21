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
            if (av[1][i] != ' ')
            {
                i--;
            }
            if (av[1][j] == ' ')
            {
                write()
            }
            j--;
        }
    }
}



























// int main(int ac, char **av)
// {
//     int i = 0;
//     int j = 0;

//     while (av[1][j])
//         j++;
//     j -= 1;
//     if (ac == 2)
//     {
//         while (j >= 0)
//         {
//             while (av[1][j] != ' ' && j >= 0)
//                 j--;
//             i = j + 1;
//             j--;
//             while (av[1][i] != ' ' && av[1][i])
//             {
//                 write (1, &av[1][i], 1);
//                 i++;
//             }
//             if (j > 0)
//                 write (1, " ", 1);
//         }
//     }
//     write (1, " ", 1);
// }