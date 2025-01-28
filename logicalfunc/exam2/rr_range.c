#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
    int total;
    int *aa;

    if (end >= start)
        total = end - start + 1;
    else
        total = start - end + 1;

    aa = malloc(sizeof(int) * total);
    if (!aa)
        return (NULL);

    int i = 0;
    if (end >= start)
    {
        while (start <= end)
        {
            aa[i] = start;
            start = start + 1;
            i = i + 1;
        }
    }
    else
    {
        while (start >= end)
        {
            aa[i] = start;
            start = start - 1;
            i = i + 1;
        }
    }
    return (aa);
}

int main()
{
    int *ft = ft_range(-2, 3);
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
