#include <stdio.h>
#include <unistd.h>
    // char s = 'z';
    // // int i = 0;
    // while (s >= 'a')
    // {
    //     write(1, &s, 1);
    //     s--;
    // }

int main (int ac, char **av)
{
    int j;
    int i;
    char *alpha = "abcdefghijklmnopqrstuvwxyz";
    char *alpha_rev = "zyxwvutsrqponmlkjihgfedcba";

    if (ac == 2)
    {
        j = 0;
        while (av[1][j])
        {
            if (av[1][j] >= 'a' && av[1][j] <= 'z')
            {
                i = 0;
                while (alpha[i])
                {
                    if (alpha[i] == av[1][j])
                    {
                        write(1, &alpha_rev[i], 1);
                    }
                    i++;
                }
            }
            else
                write(1, &av[1][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
}