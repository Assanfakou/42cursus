#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int size;
    int *arr;
    int i;

    if (start > end)
        size = start - end;
    else
        size = end - start;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    if (start > end)
    {
        while (i < size)
            arr[i++] = end++;
    }
    else
    {
        while (i < size)
            arr[i++] = end--;
    }
    return (arr);

}
int main ()
{
    int *e = ft_rrange(0, -200);
    // printf("%ld"  , (sizeof(e)));
    for (int i = 0; i <= 200; i++)
        printf("%d>", e[i]);
        // printf("%d>", e[1]);
        // printf("%d>", e[2]);
        // printf("%d>", e[3]);
}