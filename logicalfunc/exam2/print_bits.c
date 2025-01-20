#include <unistd.h>
#include <stdio.h>

void print_bits(char c)
{
    int i = 0;

    while (i <= 7)
    {
        printf("%d", (c >> i) & 1);
        i++;
    }
}
int main ()
{
    print_bits(0b11110000);
}