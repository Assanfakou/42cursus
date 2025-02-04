#include "push.h"

int main(int ac, char **av)
{
    int i;
    s_stack *stack_a = NULL;
    s_stack *stack_b = NULL;
    
   int j = ac - 1;
    i = 0;
    while (av[i])
    {
        stack_a = pars_args(&av[i], j);
        i++;
    }
    print_listint(stack_a);
}



































// int main (int ac, char **av)
// {
//     s_stack *stack = malloc(sizeof(s_stack));
//     s_stack *b = malloc(sizeof(s_stack));

//     stack->num = 10;
//     stack->next = b;
//     b->num = 69;
//     b->next = NULL;

//     sa(&stack);
//     s_stack *head = stack;
//     while (head)
//     {
//         printf("%d->", head->num);
//         head = head->next;
//     }
//     free(stack);
//     free(b);
// }
