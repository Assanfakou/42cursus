/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:40:39 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/14 06:53:15 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack **a, t_stack **b, int big_idx)
{
	int	ops;

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

int	already_sorted(t_stack *stack_a)
{
	t_stack	*walk;

	walk = stack_a;
	if (!stack_a)
		return (0);
	while (walk->next)
	{
		if (walk->num > walk->next->num)
			return (0);
		walk = walk->next;
	}
	return (1);
}

void	sort_stack_by_size(t_stack **a, t_stack **b, int *arr)
{
	if (listint_len(*a) > 10)
		sort_stack(a, b, arr, listint_len(*a));
	else if (listint_len(*a) <= 10)
		small_sort(a, b);
	free(arr);
}

void ft_exit(t_stack **stack, int *arr)
{
	write(2, "Error\n", 6);
	clear_stack(stack);
	free(arr);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int		*arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		exit(EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = pars_args(&av[1], ac - 1);
	if (!stack_a)
	{
		write(2, "Error\n", 6);			
		exit(EXIT_FAILURE);
	}
	arr = fill_arr(stack_a);
	if (check_duplicat(arr, listint_len(stack_a)) == 0)
		ft_exit(&stack_a, arr);
	if (already_sorted(stack_a))
	{
		free(arr);
		clear_stack(&stack_a);
		return (1);
	}
	sort_stack_by_size(&stack_a, &stack_b, arr);
	clear_stack(&stack_a);
}
