#include <unistd.h>
#include <stdio.h>

int is_digut(int a)
{
    return ((a >= '0') && (a <= '9'));
}
int is_upper(int a)
{
    return ((a >= 'A') && (a <= 'Z'));
}
int is_lower(int a)
{
    return ((a >= 'a') && (a <= 'z'));
}
int atoi_base (char *str, int base)
{
    int signe;
    int res;
    int i;

    i = 0;
    res = 0;
    signe = 1;
    if (str[i] == '-')
    {
        signe *= -1;
        i++;
    }
    while (str[i])
    {
        res *= base;
        if (is_digut(str[i]))
            res += (str[i] - 0);
        else if (is_lower(str[i]))
            res += (str[i] - '7');
        else if (is_lower(str[i]))
            res += (str[i] - 'W');
        i++;    
    }
    return (signe * res);
}