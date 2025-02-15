/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:43:40 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/15 17:41:30 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_ops(t_stack **b, int ind_big)
{
	int	size_of_b;

	size_of_b = listint_len(*b);
	if (ind_big > size_of_b / 2)
		return (ind_big - size_of_b);
	else
		return (ind_big);
}

int	get_big_idx(t_stack **b)
{
	int		i;
	int		big_idx;
	int		big;
	t_stack	*walk;

	walk = *b;
	i = 0;
	big = walk->num;
	big_idx = 0;
	while (walk)
	{
		if (walk->num > big)
		{
			big = walk->num;
			big_idx = i;
		}
		i++;
		walk = walk->next;
	}
	return (big_idx);
}

void	push_to_b(t_stack **a, t_stack **b, int small, int big)
{
	int	size_of_b;

	while (1)
	{
		size_of_b = listint_len(*b);
		if ((*a)->num <= small)
		{
			pb(a, b);
			rb(b);
			return ;
		}
		else if ((*a)->num <= big)
		{
			pb(a, b);
			if (size_of_b > 1 && (*b)->num < (*b)->next->num)
				sb(b);
			return ;
		}
		else
			ra(a);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int *arr,
		int size_ofstack)
{
	int	big;
	int	i;
	int	sizeof_a;

	if (size_ofstack > 100)
		big = size_ofstack / 13;
	else
		big = size_ofstack / 6;
	i = 0;
	sizeof_a = listint_len(*stack_a);
	while (listint_len(*stack_a) > 0)
	{
		push_to_b(stack_a, stack_b, arr[i], arr[big]);
		if (i < big)
			i++;
		if (big < sizeof_a - 1)
			big++;
	}
	loop_in_b(stack_b, stack_a);
}

void	loop_in_b(t_stack **b, t_stack **a)
{
	while (listint_len(*b) > 0)
		push_to_a(a, b, get_big_idx(b));
}
