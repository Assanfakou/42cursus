/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:01:09 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/08 11:22:55 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_a(s_stack **a, s_stack **b, int big_idx)
{
    int ops;

    ops = calcul_ops(b, big_idx);
    while (ops > 0)
    {
        ops--;
        rb(b);
    }
    while (ops < 0)
    {
        ops++;
        rrb(b);
    }
    pa(a, b);
}
void loop_in_b(s_stack **b, s_stack **a)
{
    while (listint_len(*b) > 0)
        push_to_a(a, b, get_big_idx(b));
}
int main(int ac, char **av)
{
    int j;
    int *arr;
    s_stack *stack_a;
    s_stack *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    j = ac - 1;

    stack_a = pars_args(&av[1], j);
    if (!stack_a)
        write(2, "Erour\n", 6);
    arr = fill_arr(stack_a);
    if (!check_duplicat(arr, listint_len(stack_a)))
    {
        write(2, "Erour\n", 6);
        free(arr);
        clear_stack(&stack_a);
        return (0);
    }
    sort_stack(&stack_a, &stack_b, arr, listint_len(stack_a));
    // print_listint(stack_b);
    clear_stack(&stack_b);
    print_listint(stack_a);
    clear_stack(&stack_a);
}


