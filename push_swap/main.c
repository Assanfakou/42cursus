#include "push.h"
// #include <complex.h>
int listint_len(s_stack *h)
{
    int i;

    i = 0;
    while (h)
    {
        i++;
        h = h->next;
    }
    return (i);
}
int find_min(s_stack *a) {
    int min = a->num;
    while (a) {
        if (a->num < min) min = a->num;
        a = a->next;
    }
    return min;
}

void normalize_numbers(s_stack **a) {
    int offset = abs(find_min(*a));
    s_stack *current = *a;
    while (current) {
        current->num += offset;
        current = current->next;
    }
}
int find_max(s_stack *a) {
    int max = a->num;
    while (a) {
        if (a->num > max) max = a->num;
        a = a->next;
    }
    return max;
}

int get_max_bits(s_stack *a) {
    int max = find_max(a);
    int bits = 0;
    while (max >> bits) bits++;
    return bits;
}
void radix_sort(s_stack **a, s_stack **b) {
    int max_bits = get_max_bits(*a);

    for (int bit = 0; bit < max_bits; bit++) {
        int size = listint_len(*a);
        for (int i = 0; i < size; i++) {
            int num = (*a)->num;
            if ((num >> bit) & 1) // Bit is 1: keep in A
                ra(a);
            else // Bit is 0: push to B
                pb(a, b);
        }
        // Move all elements from B back to A
        while (*b)
            pa(a, b);
    }
}

int main(int ac, char **av)
{
    int i;
    s_stack *stack_a = NULL;
    s_stack *stack_b = NULL;

    i = 1;
    int j = 0;
    while (av[i])
    {
        add_nodeint_end(&stack_a,ft_atoi(av[i]));
        i++;
    }
    // print_listint(stack_a);
    // printf("defference\n");
    // while (stack_a)
    //     pb(&stack_a, &stack_b);
    // rra(&stack_a);
    // print_listint(stack_b);
   radix_sort(&stack_a, &stack_b);
    // rra(&stack_a, i);
    // sa(&stack_a);

    // // insertion_sort(&stack_b);
    // while (stack_b)
    //     pa(&stack_a, &stack_b, i);
    // print_listint(stack_a);

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
