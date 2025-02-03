/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:07:57 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/03 18:08:01 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void pb(s_stack **stack_a, s_stack **stack_b)
{
    s_stack *temp;

    temp = *stack_b;
    *stack_b = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_b)->next = temp;
    if (I != 0)
        printf("pb\n");
}

void pa(s_stack **stack_a, s_stack **stack_b)
{
    s_stack *temp;

    temp = *stack_a;
    *stack_a = *stack_b;
    *stack_b = (*stack_b)->next;
    (*stack_a)->next = temp;
    if (I != 0)
        printf("pa\n");
}

void sb(s_stack **stack_b)
{
    s_stack *temp;

    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = (*stack_b)->next;
    (*stack_b)->next = temp;
    if (I != 0)
        printf("sb\n");
}

void sa(s_stack **stack_a)
{
    s_stack *temp;

    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = (*stack_a)->next;
    (*stack_a)->next = temp;
    if (I != 0)
        printf("sa\n");
}

void ss(s_stack **stack_a, s_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    if (I != 0)
        printf("ss\n");
}

void ra(s_stack **stack_a)
{
    s_stack *temp;
    s_stack *walk;

    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    walk = *stack_a;
    while ((walk->next) != NULL)
        walk = walk->next;
    walk->next = temp;
    temp->next = NULL;
    if (I != 0)
        printf("ra\n");
}

void rb(s_stack **stack_b)
{
    s_stack *temp;
    s_stack *walk;

    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    walk = *stack_b;
    while ((walk->next) != NULL)
        walk = walk->next;
    walk->next = temp;
    temp->next = NULL;
    if (I != 0)
        printf("rb\n");
}

void rra(s_stack **stack)
{
	s_stack *prev;
	s_stack *walk;

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
	if (I != 0)
        printf("rra\n");
}
void rrb(s_stack **stack)
{
	s_stack *prev;
	s_stack *walk;

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
	if (I != 0)
        printf("rrb\n");
}
