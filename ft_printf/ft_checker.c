/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:43:45 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/07 14:43:50 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(va_list arg, char s)
{
	int i;

	if (s == 'd' || s == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else if (s == 'x')
		i = ft_putnum_lhex(va_arg(arg, unsigned int));
	else if (s == 'X')
		i = ft_putnum_uhex(va_arg(arg, unsigned int));
	else if (s == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (s == 'c')
		i = ft_putchar(va_arg(arg, int));
	else if (s == 'u')
		i = ft_uuputnb(va_arg(arg, unsigned int));
	else if (s == 'p')
		i = ft_putaddre(va_arg(arg, unsigned long));
	else if (s == '%')
		i = ft_putchar('%');
	return (i);
}