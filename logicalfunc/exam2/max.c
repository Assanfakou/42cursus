#include <unistd.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int i;
    int temp;

    i = 0;
    while (i < len - 1)
    {
        if (tab[i] < tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = -1;
        }
        i++;
    }
    return (tab[0]);
}
int main ()
{
    int te[] = {1 ,0, 8, 4, 17};

    printf("%d", max(te, 6));
}
