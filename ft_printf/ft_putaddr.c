/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:49 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/07 14:44:50 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
