/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:58:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/12 07:10:21 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*walk;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	walk = *stack_a;
	while ((walk->next) != NULL)
		walk = walk->next;
	walk->next = temp;
	temp->next = NULL;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*walk;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	walk = *stack_b;
	while ((walk->next) != NULL)
		walk = walk->next;
	walk->next = temp;
	temp->next = NULL;
}

void	rra(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*walk;

	if (!*stack || !((*stack)->next))
		return ;
	prev = NULL;
	walk = *stack;
	while ((walk->next) != NULL)
	{
		prev = walk;
		walk = walk->next;
	}
	add_nodeint(stack, walk);
	*stack = walk;
	prev->next = NULL;
}

void	rrb(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*walk;

	if (!*stack || !((*stack)->next))
		return ;
	prev = NULL;
	walk = *stack;
	while ((walk->next) != NULL)
	{
		prev = walk;
		walk = walk->next;
	}
	add_nodeint(stack, walk);
	*stack = walk;
	prev->next = NULL;
}
