#include <unistd.h>
#include <stdio.h>

void print_bits(unsigned char c)
{
    int i = 7;
    char bit;

    while (i >= 0)
    {
        bit = ((c >> i) & 1) + '0';
        write(1, &bit, 1);
        i--;
    }
}