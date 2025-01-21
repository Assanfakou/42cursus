#include <stdio.h>
#include <unistd.h>


// unsigned char reves_bits(unsigned char oc)
// {
//     int c = 0;
//     unsigned char bite = 0x0;

//     while (c < 8)
//     {
//         bite = bite << 1;
//         bite = bite | (oc & 1);
//         oc = oc >> 1;
//         c++;
//     }
//     return (bite);
// }
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
unsigned char	reverse_bits(unsigned char octet)
{
	// return ((octet >> 4) | (octet << 4));
    int pocket;
    int i = 0;
    int n;

    while (i >= 7)
    {
        pocket = (octet >> i) & 1;
        n = (n << 1) | pocket;
        i--;
    }
    return(n);

}
int main ()
{
    unsigned char st = reverse_bits(0b11110000);
    print_bits(st);
}