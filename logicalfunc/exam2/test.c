#include <unistd.h>

int is_digit(int a)
{
    return (a >= '0' && a <= '9');
}
int is_lower(int a)
{
    return (a >= 'a' && a <= 'z');
}
int is_uppper(int a)
{
    return (a >= 'A' && a <= 'Z');
}
int atoi_base(char *str, int base)
{
    int signe;
    int res;
    int i;

    i = 0;
    res = 0;
    signe = 1;

    if (str[i] == '-')
    {
        signe = -1;
        i++;
    }
    while (str[i])
    {
        res *= base;
        if (is_digit(str[i]))
            res += (str[i] - '0');
        else if (is_lower(str[i]))
            res += (str[i] - 'W');
        else if (is_uppper(str[i]))
            res += (str[i] - '7');
        i++;
    }
    return (res * signe);
}
