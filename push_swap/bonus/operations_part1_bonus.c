/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:07:57 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/12 07:09:59 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = temp;
}

void	sb(t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
}

void	sa(t_stack **stack_a)
{
	t_stack	*temp;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
