#include <stdio.h>
#include <unistd.h>
void _make_upper(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}
int main (int ac, char **av)
{
    int i;
    int j;
    if (ac == 2)
    {
    _make_upper(av[1]);
        i = 0;
        while (av[1][i])
        {
            if ((av[1][i] >= 'a' && av[1][i] <= 'z') && (av[1][i + 1] == ' ' || av[1][i + 1] == '\0'))
                av[1][i] -= 32;
            write (1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}