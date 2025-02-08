/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:01:09 by hfakou            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/08 20:43:38 by assankou         ###   ########.fr       */
=======
/*   Updated: 2025/02/08 13:42:47 by hfakou           ###   ########.fr       */
>>>>>>> b016222b0d45d81a0627d89331b56e6bd0ea047b
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
int position_of_min(s_stack **a)
{
    int i;
    int min_idx;
    s_stack *walk;
    int min;

    min = walk->num;
    i = 0;
    walk = *a;
    min_idx = 0;
    while (walk)
    {
        if (walk->num < min)
        {
            min = walk->num;
            min_idx = i;
        }
        walk = walk->next;
        i++;
    }
    return (min_idx);
}
void small_sort(s_stack **a, s_stack **b)
{
    int min_pos;

    if (listint_len(*a) == 2)
    {
        if ((*a)->num > (*a)->next->num)
            sa(a);
    }
    while (listint_len(*a) > 3)
    {
        min_pos = position_of_min(a);
<<<<<<< HEAD
        printf("min pos ..%d", min_pos);
=======
>>>>>>> b016222b0d45d81a0627d89331b56e6bd0ea047b
        if (min_pos > listint_len(*a) / 2)
        {
            while (min_pos-- > 0)
                ra(a);
        }
        else
<<<<<<< HEAD
            while (min_pos++ < listint_len(*a))
=======
            while (min_pos++ < 0)
>>>>>>> b016222b0d45d81a0627d89331b56e6bd0ea047b
                rra(a);
        pb(a, b);
    }
    while (listint_len(*b) > 0)
        pa(a, b);
}
<<<<<<< HEAD
void sort_every(s_stack **a, s_stack **b, int *arr)
{
        // ft_printf("[%d]", listint_len(*a));
    if (listint_len(*a) >= 10)
    {
        sort_stack(a, b, arr, listint_len(*a));
    }
    else if (listint_len(*a) < 10)
        small_sort(a, b);
}
=======
>>>>>>> b016222b0d45d81a0627d89331b56e6bd0ea047b
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
    sort_every(&stack_a, &stack_b, arr); 
    // print_listint(stack_b);
    // sort_stack(&stack_a, &stack_b, arr, listint_len(stack_a));
    clear_stack(&stack_b);
    print_listint(stack_a);
    clear_stack(&stack_a);
}
