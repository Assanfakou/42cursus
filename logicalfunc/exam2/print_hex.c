#include <unistd.h>
#include <stdio.h>
int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i])
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}
void print_hex(int n)
{
    char *hex = "0123456789abcdef";

    if (n >= 16)
        print_hex(n / 16);
    write(1, &hex[n % 16], 1);
}

int main (int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
       i = ft_atoi(av[1]);
       print_hex(i);
    }
    write(1, "\n", 1);
}