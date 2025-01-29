#include <unistd.h>
#include "push.h"

void pb(s_stack **stack_a, s_stack **stack_b)
{
    s_stack *temp;

    temp = *stack_b;
    *stack_b = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_b)->next = temp;
}

void pa(s_stack **stack_a, s_stack **stack_b)
{
    s_stack *temp;

    temp = *stack_a;
    *stack_a = *stack_b;
    *stack_b = (*stack_b)->next;
    (*stack_a)->next = temp;
}

void sb(s_stack **stack_b)
{
    s_stack *temp;

    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    (*stack_b)->next = temp;
}

void sa(s_stack **stack_a)
{
    s_stack *temp;

    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_a)->next = temp;
}

void ss(s_stack **stack_a, s_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
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
	*stack = walk;
	prev->next = NULL;
}
