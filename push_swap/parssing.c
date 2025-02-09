/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:49:31 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/09 17:50:18 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pars_arr(char **arr, s_stack **stack)
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
        add_nodeint_end(stack, (int)num);
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
s_stack *pars_args(char **arg, int size)
{
    int i;
    s_stack *stackd;

    stackd = NULL;        
    i = 0;
    while (i < size)
    {
        if (!pars_str(arg[i], &stackd))
        {
            clear_stack(&stackd);
            return (NULL);
        }
        i++;
    }
    return (stackd);
}
int check_duplicat(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size - 1)
    {
        if (arr[i] == arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}
