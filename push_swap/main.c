/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:01:09 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/06 23:32:01 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
void push_to_b(s_stack **a, s_stack **b, int small, int big)
{
    int size_of_b;

    while (1)
    {
        size_of_b = listint_len(*b);
        if ((*a)->num <= small)
        {
            pb(a, b);
            rb(b);
            return ;
        }
        else if ((*a)->num <= big)
        {
            pb(a, b);
            if (size_of_b > 1 && (*b)->num < (*b)->next->num)
                sb(b);
            return ;
        }
        else
            ra(a);
    }
}
void sort_stack(s_stack **stack_a, s_stack **stack_b, int *arr, int size_ofstack)
{
    int big;
    int i;
    if (size_ofstack >= 100)
        big = size_ofstack / 13;
    else
        big = size_ofstack / 6;
    i = 0;
    while (listint_len(*stack_a) > 0)
    {
        print_listint(*stack_b);
        ft_printf("^ b\n");
        print_listint(*stack_a);
        push_to_b(stack_a, stack_b, arr[i], arr[big]);
        if (i < big)
            i++;
        if (big < listint_len(*stack_a))
            big++;
    }
}
int main(int ac, char **av)
{
    int i;
    int *arr;
    s_stack *stack_a = NULL;
    s_stack *stack_b = NULL;
    
   int j = ac - 1;

    stack_a = pars_args(&av[1], j);
    if (!stack_a)
        write(2, "Erour\n", 6);
    arr = fill_arr(stack_a);
//    i = 0;
//    while (i < listint_len(stack_a)){
//         ft_printf("%d\n", arr[i]);
//         i++;
//     }
    sort_stack(&stack_a, &stack_b, arr, listint_len(stack_a));
    // print_listint(stack_b);

}


