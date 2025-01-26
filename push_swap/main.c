#include "push.h"

int main ()
{
    s_stack *stack = malloc(sizeof(s_stack));
    s_stack *b = malloc(sizeof(s_stack));

    stack->num = 10;
    stack->next = b;
    b->num = 69;
    b->next = NULL;

    sa(&stack);
    s_stack *head = stack;
    while (head)
    {
        printf("%d->", head->num);
        head = head->next;
    }
    free(stack);
    free(b);
}