/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:40:39 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/14 01:17:16 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(s_stack **a, s_stack **b, int big_idx)
{
	int	ops;

	ops = calcul_ops(b, big_idx);
	while (ops > 0)
	{
		ops--;
		rb(b);
	}
	while (ops < 0)
	{
		ops++;
		rrb(b);
	}
	pa(a, b);
}

void	sort_stack_by_size(s_stack **a, s_stack **b, int *arr)
{
	if (listint_len(*a) > 10)
		sort_stack(a, b, arr, listint_len(*a));
	else if (listint_len(*a) <= 10)
		small_sort(a, b);
	free(arr);
}

int	main(int ac, char **av)
{
	int		j;
	int		*arr;
	s_stack	*stack_a;
	s_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	j = ac - 1;
	stack_a = pars_args(&av[1], j);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	arr = fill_arr(stack_a);
	if (!check_duplicat(arr, listint_len(stack_a)))
	{
		write(2, "Error\n", 6);
		free(arr);
		clear_stack(&stack_a);
		return (0);
	}
	sort_stack_by_size(&stack_a, &stack_b, arr);
	// print_listint(stack_a);
	clear_stack(&stack_a);
}
