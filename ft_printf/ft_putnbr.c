/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:57 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/07 14:44:59 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbs)
{
	unsigned int	s;
	int				se;

	se = 0;
	if (nbs < 0)
	{
		se += ft_putchar('-');
		s = nbs;
	}
	else
		s = nbs;
	if (s > 9)
		se += ft_putnbr(s / 10);
	se += ft_putchar((s % 10) + '0');
	return (se);
}
