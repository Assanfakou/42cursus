#include "ft_printf.h"

int	ft_putnbr(int nbs)
{
	unsigned int	s;
	int				se;

	se = 0;
	if (nbs < 0)
	{
		se += ft_putchar('-');
		s = -nbs;
	}
	else
		s = nbs;
	if (s > 9)
		se += ft_putnbr(s / 10);
	se += ft_putchar((s % 10) + '0');
	return (se);
}
