/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:49 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/08 14:22:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_putaddre(unsigned long add)
{
	int		re;
	char	*base;

	if (add == 0)
		return (write (1, "(nil)", 5));
	base = "0123456789abcdef";
	re = 0;
	if (add >= 16)
		re = ft_putaddre(add / 16);
	re += ft_putchar(base[add % 16]);
	return (re);
}