#include <unistd.h>

int main (int ac, char **av)
{
    int i;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i] == ' ' || av[1][i] == '\t')
                i++;
        while (av[1][i])
        {
            if (av[1][i] == ' ' || av[1][i] == '\t')
			{
			    if (av[1][i + 1] != ' ' && av[1][i + 1] != '\0')
					write(1, " ", 1);
			}
			else if (av[1][i] != ' ' && av[1][i] != '\t')
				write(1, &av[1][i], 1);
			i++;
            // while ((av[1][i] == '\t' || av[1][i] == ' ') && av[1][i])
            //     i++;
            // if (av[1][i] == '\0')
            //     return (0);
            // if (av[1][i] != ' ' || av[1][i] != '\t')
            //     write (1, &av[1][i], 1);
            // if ((av[1][i + 1] == ' ' || av[1][i + 1] == '\t') && av[1][i + 2] != '\0')
            //     write (1, "8", 1);
            // i++;
        }
    }
    write (1, "\n", 1);
}