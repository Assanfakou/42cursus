#include <stdio.h>

char *ft_strrev(char *str)
{
    int i;
    int temp;
    int end;

    if (!str || !*str)
        return (str);
    end = 0;
    while (str[end])
        end++;
    end--;
    i = 0;
    while (i < end)
    {
        temp = str[i];
        str[i] = str[end];
        str[end] = temp;
        end--, i++;
    }
    return (str);
}
int main ()
{

    char *st = "", *s;
    s = st;
    printf("%s\n", ft_strrev(st) == s ? "yes": "ni");
}