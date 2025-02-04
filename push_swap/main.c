#include "push.h"
int *fill_arr(s_stack *stack_h)
{
    int *arr;
    int size_lis;
    int i;

    size_lis = listint_len(stack_h);
    
    arr = malloc(sizeof(int) * (size_lis + 1));
    if (!arr)
        return (NULL);
    i = 0;
    while (i < size_lis && stack_h)
    {
        arr[i] = stack_h->num;
        i++;
        stack_h = stack_h->next;
    }
    arr[i] = 0;
    return (arr);
}
int *sort_arr(int *arr)
{
    int i;
    int j;
    int sorted;
    int temp;
    int size;

    size = 0;
    while (arr[size])
        size++;
    i = 0;
    while (i < (size - 1))
    {
        sorted = 0;
        j = 0;
        while (j < (size - i - 1))
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 1;
            }
            j++;
        }
        i++;
        if (sorted == 0)
            break;
    }
    return (arr);
}
int main(int ac, char **av)
{
    int i;
    int *arr;
    s_stack *stack_a = NULL;
    s_stack *stack_b = NULL;
    
   int j = ac - 1;
<<<<<<< HEAD

    stack_a = pars_args(&av[1], j);
    if (!stack_a)
        write(2, "Erour\n", 6);
    // print_listint(stack_a);
    arr = fill_arr(stack_a);
    // for(int i = 0; i < 14; i++)
    //     ft_printf("%d\n", arr[i]);
    sort_arr(arr);
    for(int i = 0; i < 14; i++)
        ft_printf("%d\n", arr[i]);

=======
    stack_a = pars_args(&av[1], j);
    print_listint(stack_a);
>>>>>>> 10c836b2be074488db224bf6831c11d723aaf8f0
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
