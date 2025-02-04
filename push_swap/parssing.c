/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:53:14 by assankou          #+#    #+#             */
/*   Updated: 2025/02/04 11:42:56 by assankou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int pase_arr(char **arr, s_stack **stack)
{
    int i;
    long num;

    if (!arr || !*arr)
        return (0);
    i = 0;
    while (arr[i])
    {
        if (!is_valid_input(arr[i]))
            return (0);
        num = ft_atol(arr[i]);
        if (num > INT_MAX || num < INT_MIN)
            return (0);
        add_nodeint_end(*stack, (int)num);
        i++;
    }
    return (1);
}
int pars_str(char *input, s_stack **stack_s)
{
    char **arr;

    arr = fsplit(input, ' ');
    if (!arr || !arr[0])
    {
        free_arr(arr);
        return (0);
    }
    if (!pars_arr(arr, stack_s))
    {
        free(arr);
        return (0);
    }
    free_arr(arr);
    return (1);
}
s_stack pars_args(char **arg, int size)
{
    int i;
    s_stack *stack;

    while (i < size)
    {
        if (!pars_str(arg[i], &stack))
        {
            fr
        }
    }
}