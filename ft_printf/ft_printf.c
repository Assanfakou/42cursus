/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:02 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/08 14:26:54 by codespace        ###   ########.fr       */
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
