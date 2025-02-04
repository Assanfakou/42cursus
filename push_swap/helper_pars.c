/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:04:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/04 15:58:09 by assankou         ###   ########.fr       */
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
int is_valid_input(char *input)
{
    int i;

    i = 0;
    if (!input || !ft_strlen(input))
        return (0);
    if (input[0] == '-' || input[0] == '+')
        i++;
    if (!input[i])
        return (0);
    while (input[i])
    {
        if (!is_digit(input[i]))
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

void free_arr(char **arr)
{
    int i;

    if (!arr)
        return ;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}