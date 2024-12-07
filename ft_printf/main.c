/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:42:44 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/07 14:43:01 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	main(void)
{
	char *st = "hello Assan you are legend!";
	int s = 1211225;
	void *ptr = &s;
	char e = 'a';

	ft_printf("str : %s, \n digit = %d,\n address :%p,\n char :
		%c,\n {%%} the hex lower :%x and upper %X", st, s, (unsigned long)ptr,
		e, s, s);
	printf("str : %s, \ns = %d,m\n address :%p,\n char :
		%c,\n {%%} the hex lower :%x and upper %X", st, s, ptr, e, s, s);
}