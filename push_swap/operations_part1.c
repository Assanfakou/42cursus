/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:07:57 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/08 11:08:02 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(s_stack **stack_a, s_stack **stack_b)
{
	s_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	if (I != 0)
		ft_printf("pb\n");
}

void	pa(s_stack **stack_a, s_stack **stack_b)
{
	s_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = temp;
	if (I != 0)
		ft_printf("pa\n");
}

void	sb(s_stack **stack_b)
{
	s_stack	*temp;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (I != 0)
		ft_printf("sb\n");
}

void	sa(s_stack **stack_a)
{
	s_stack	*temp;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (I != 0)
		ft_printf("sa\n");
}

void	ss(s_stack **stack_a, s_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	if (I != 0)
		ft_printf("ss\n");
}
