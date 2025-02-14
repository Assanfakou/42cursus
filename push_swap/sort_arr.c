/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:43:01 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/14 01:16:00 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_arr(s_stack *stack_h)
{
	int	*arr;
	int	size_lis;
	int	i;

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

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	int	sorted;

	i = 0;
	while (i < size - 1)
	{
		sorted = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sorted = 1;
			}
			j++;
		}
		if (sorted == 0)
			break ;
		i++;
	}
}
