/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:43:01 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/06 22:12:23 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int *fill_arr(s_stack *stack_h)
{
    int *arr;
    int size_lis;
    int i;

    size_lis = listint_len(stack_h);
    
    arr = malloc(sizeof(int) * (size_lis));
    if (!arr)
        return (NULL);
    i = 0;
    while (i < size_lis && stack_h)
    {
        arr[i] = stack_h->num;
        i++;
        stack_h = stack_h->next;
    }
    sort_arr(arr, size_lis);
    return (arr);
}
void sort_arr(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        int sorted = 0;
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                sorted = 1;
            }
            j++;
        }
        i++;
        if (sorted == 0)
            break;
    }
}