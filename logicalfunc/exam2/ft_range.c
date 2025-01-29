#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
    int total;
    int *aa;

    if (end >= start)
    {
        total = end - start;
        aa = malloc(sizeof(int) * (total + 1));
        if (!aa)
            return (NULL);
    }
    else
    {
        total = start - end;
        aa = malloc(sizeof(int) * (total + 1));
        if (!aa)
            return (NULL);
    }
    int i = 0;
    if (end >= start)
    {
        while (start <= end)
        {
            aa[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while(end <= start)
        {
            aa[i] = start;
            start--;
            i++;
        }
    }
    // aa[i] = 0;
    return (aa);
}

int main()
{
    int *ft = ft_range(-3, 3);
    if (!ft)
        return (1);

    int i = 0;
    while (i < 6)
    {
        printf("%d\n", ft[i]);
        i++;
    }
    
    free(ft);
    return (0);
}
