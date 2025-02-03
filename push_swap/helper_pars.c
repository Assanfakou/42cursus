/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:04:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/03 19:07:14 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;

    return (i);
}
int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
int is_valid_in(char *input)
{
    int i;

    i = 0;
    if (!str || !ft_strlen(input))
        return (0);
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!is_digit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
long ft_atol(const char *str)
{
    long res;
    int signe;
    int i;

    i = 0;
    res = 0;
    signe = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * signe);
}
