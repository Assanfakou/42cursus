/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_uhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:45:04 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/07 14:45:05 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum_uhex(unsigned int nbr)
{
	int		r;
	char	*bas;

	bas = "0123456789ABCDEF";
	r = 0;
	if (nbr >= 16)
		r = ft_putnum_uhex(nbr / 16);
	r += ft_putchar(bas[nbr % 16]);
	return (r);
}
