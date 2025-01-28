#include <stdio.h>
#include <unistd.h>

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
unsigned char   reverse_bits(unsigned char octet)
{
	// return ((octet >> 4) | (octet << 4));
    unsigned char pocket = 0x0;
    int i = 0;

    while (i <= 7)
    {
        pocket = pocket << 1;
        pocket = pocket | (octet & 1);
        octet = octet >> 1;
        i++;
    }
    return(pocket);
}

int main ()
{
    unsigned char st = reverse_bits(0b01000001);
    print_bits(st);
}
