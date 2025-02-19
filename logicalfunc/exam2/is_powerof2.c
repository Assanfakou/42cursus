#include <stdio.h>

int powerof2(int i)
{
   while (i % 2 != 0)
        i /= 2;
    if (i == 1)
        return (1);
    else
        return (0);
}
int main ()
{
    printf("%d", powerof2(10));
}