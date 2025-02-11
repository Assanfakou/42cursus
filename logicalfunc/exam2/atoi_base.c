#include <unistd.h>
#include <stdio.h>


// int    ft_check(char *str, char c)
// {
//     int    i;

//     i = 0;
//     while (str[i] != '\0')
//     {
//         if (str[i] == c)
//             return (1);
//         i++;
//     }
//     return (0);
// }

// int    ft_strlen(char *str)
// {
//     int    ln;

//     ln = 0;
//     while (str[ln] != '\0')
//         ln++;
//     return (ln);
// }

// int    ft_invalid(char *check)
// {
//     int    tol;
//     int    i;

//     tol = ft_strlen(check);
//     i = 0;
//     if (tol < 2)
//         return (0);
//     while (i < tol)
//     {
//         if (check[i] == '+' || check[i] == '-')
//             return (0);
//         if (ft_check(check + i + 1, check[i]))
//             return (0);
//         i++;
//     }
//     return (1);
// }

// int    ft_get_index(char *base, char c)
// {
//     int    i;

//     i = 0;
//     while (base[i] != '\0')
//     {
//         if (base[i] == c)
//             return (i);
//         i++;
//     }
//     return (-1);
// }

// int    ft_atoi_base(char *str, char *base)
// {
//     int    i;
//     int    sign;
//     int    res;
//     int    tol;
//     int    digit;

//     tol = ft_strlen(base);
//     if (!ft_invalid(base))
//         return (0);
//     i = 0;
//     res = 0;
//     sign = 1;
//     while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
//         i++;
//     while (str[i] == '-' || str[i] == '+')
//         if (str[i++] == '-')
//             sign *= -1;
//     while (str[i] != '\0')
//     {
//         digit = ft_get_index(base, str[i++]);
//         if (digit == -1)
//             break ;
//         res = res * tol + digit;
//     }
//     return (sign * res);
// }

#include <stdio.h>










int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
int get_index(char *str, char c)
{
    int index;

    index = 0;
    while (index < ft_strlen(str))
    {
        if (str[index] == c)
            return (index);
        index++;
    }
    return (-1);
}

int check(char *str, char c)
{
    int i;

    i = 0;
    while (i < ft_strlen(str))
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int atoi_base(char *str, char *base)
{
    int i;
    int tol;
    int signe;
    int res;
    int digit;

    i = 0;
    signe = 0;
    res = 0;
    tol = ft_strlen(base);
    while ((str[i] >= 9 && str[i] <= 13) || str[i == ' '])
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe *= -1;
        i++;
    }
    while (str[i])
    {
        digit = get_index(base, str[i++]);
        if (digit == -1)
            break ;
        res = res * tol + digit;
    }
    return (signe * res);
}



int    main()
{
    printf("%d", atoi_base("15", "0123456789abcdef"));
}






































// int is_digut(int a)
// {
//     return ((a >= '0') && (a <= '9'));
// }
// int is_upper(int a)
// {
//     return ((a >= 'A') && (a <= 'Z'));
// }
// int is_lower(int a)
// {
//     return ((a >= 'a') && (a <= 'z'));
// }
// int atoi_base(char *str, int base)
// {
//     int signe;
//     int res;
//     int i;

//     i = 0;
//     res = 0;
//     signe = 1;
//     if (str[i] == '-')
//     {
//         signe *= -1;
//         i++;
//     }
//     while (str[i])
//     {
//         res *= base;
//         if (is_digut(str[i]))
//             res += (str[i] - '0');
//         else if (is_lower(str[i]))
//             res += (str[i] + 10);
//         else if (is_lower(str[i]))
//             res += (str[i] + 10);
//         i++;    
//     }
//     return (signe * res);
// }
// #include <stdio.h>

// int main ()
// {
//     printf("%d", atoi_base("-FF", 16));
// }