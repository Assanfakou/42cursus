#include <stdio.h>
#include <unistd.h>
#include "../../libft/libft.h"

int main (int ac, char **av)
{
    int j;
    int i;

    j = 0;
    while (av[1][j])
        j++;
    j--;
    if (ac == 2)
    {
        while (j >= 0)
        {
            while (av[1][j] != ' ' &&  j >= 0)
                j--;
            i = j + 1;
            j--;
            while (av[1][i] != ' ' && av[1][i])
            {
                write(1, &av[1][i], 1);
                i++;
            }
            if(j > 0)
                write(1, " ", 1);
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