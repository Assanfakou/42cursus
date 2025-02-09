/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:40:39 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/09 18:01:06 by hfakou           ###   ########.fr       */
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

    i = 0;
    walk = *a;
    min = walk->num;
    min_idx = 0;
    // printf("im here");
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
void sort_three(s_stack **s)
{
    int no1;
    int no2;
    int no3;

    no1 = (*s)->num;
    no2 = (*s)->next->num;
    no3 = (*s)->next->next->num;

    if (no1 > no2 && no1 > no3)
        ra(s);
    if (no2 > no1 && no2 > no3)
        rra(s);
    if ((*s)->num > (*s)->next->num)
        sa(s);
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
        // printf("min pos ..%d", min_pos);
        if (min_pos <= listint_len(*a) / 2)
        {
            while (min_pos-- > 0)
                ra(a);
        }
        else
            while (min_pos++ < listint_len(*a))
                rra(a);
        pb(a, b);
    }
    sort_three(a);
    while (listint_len(*b) > 0)
        pa(a, b);
}
void sort_every(s_stack **a, s_stack **b, int *arr)
{
        // ft_printf("[%d]", listint_len(*a));
    if (listint_len(*a) >= 10)
        sort_stack(a, b, arr, listint_len(*a));
    else if (listint_len(*a) < 10)
        small_sort(a, b);
    free(arr);
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
    {
        write(2, "Error\n", 7);    
        return (0);
    }
    arr = fill_arr(stack_a);
    // for (int i = 0; i < listint_len(stack_a);  i++)
    //     printf("[%d]\n", arr[i]);
    if (!check_duplicat(arr, listint_len(stack_a)))
    {
        write(2, "Error\n", 6);
        free(arr);
        clear_stack(&stack_a);
        return (0);
    }
    sort_every(&stack_a, &stack_b, arr);
    // print_listint(stack_b);
    // sort_stack(&stack_a, &stack_b, arr, listint_len(stack_a));
    clear_stack(&stack_b);
    // print_listint(stack_a);
    clear_stack(&stack_a);
}
