/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:15:27 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/14 01:15:04 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_of_min(s_stack **a)
{
	int		i;
	int		min_idx;
	s_stack	*walk;
	int		min;

	i = 0;
	walk = *a;
	min = walk->num;
	min_idx = 0;
	while (walk)
	{
		if (walk->num < min)
		{
			min = walk->num;
			min_idx = i;
		}
		walk = walk->next;
		i++;
	}
	return (min_idx);
}

void	sort_three(s_stack **s)
{
	int	no1;
	int	no2;
	int	no3;

	no1 = (*s)->num;
	no2 = (*s)->next->num;
	no3 = (*s)->next->next->num;
	if (no1 > no2 && no1 > no3)
		ra(s);
	if (no2 > no1 && no2 > no3)
		rra(s);
	if ((*s)->num > (*s)->next->num)
		sa(s);
}

void	small_sort(s_stack **a, s_stack **b)
{
	int	min_pos;

	if (listint_len(*a) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
		return ;
	}
	while (listint_len(*a) > 3)
	{
		min_pos = position_of_min(a);
		if (min_pos <= listint_len(*a) / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
			while (min_pos++ < listint_len(*a))
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (listint_len(*b) > 0)
		pa(a, b);
}
