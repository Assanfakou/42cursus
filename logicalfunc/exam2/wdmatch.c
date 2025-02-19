#include <unistd.h>

int main (int ac, char **av)
{
    int i;
    int j;

    if (ac == 3)
    {
        i = 0;
        j = 0;
        char c;
        while (av[1][i] && av[2][j])
        {
            if (av[1][i] == av[2][j])
            {
                i++;
                c = av[2][j];
            }
            j++;
        }
        if (av[1][i] == '\0')
        {
            int l;

            l = 0;
            while (av[1][l])
            {
                write(1, &av[1][l], 1);
                l++;
            }
        }
    }
}