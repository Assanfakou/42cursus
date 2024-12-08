/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:44:42 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/07 14:44:45 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h> //it has to be remeved
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putstr(char *st);
int	ft_putchar(char c);
int	ft_putnum_uhex(unsigned int nbr);
int	ft_putnum_lhex(unsigned int nb);
int	ft_uuputnb(unsigned int nbs);
int	ft_putaddre(unsigned long add);
int	ft_checker(va_list arg, char s);
int	ft_printf(const char *firstpar, ...);

#endif