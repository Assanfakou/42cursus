/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:02 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/07 14:44:04 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *firstpar, ...)
{
	int		i;
	int		vas;
	va_list	arg;

	va_start(arg, firstpar);
	i = 0;
	vas = 0;
	while (firstpar[i] != '\0')
	{
		if (firstpar[i] == '%')
		{
			if (firstpar[i + 1] != '\0')
			{
				if (firstpar[i + 1] == 'p' && firstpar[i + 1] != 0)
					vas += write(1, "0x", 2);
				vas += ft_checker(arg, firstpar[i + 1]);
				i++;
			}
		}
		else
			vas += ft_putchar(firstpar[i]);
		i++;
		va_end(arg);
	}
	return (vas);
}
