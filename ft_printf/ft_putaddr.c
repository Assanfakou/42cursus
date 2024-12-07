#include "ft_printf.h"

int	ft_putaddre(unsigned long add)
{
	int re;
	char *base;

	base = "0123456789abcdef";
	re = 0;
	if (add >= 16)
		re = ft_putaddre(add / 16);
	re += ft_putchar(base[add % 16]);
	return (re);
}