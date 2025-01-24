#include <unistd.h>
#include "push.h"

void addfront(s_stack **stack_a, s_stack *new_node)
{
    new_node->next = *stack_a;
    *stack_a = new_node;

}
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