/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:40:39 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/12 08:03:51 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	main(int ac, char **av)
{
	int (*arr);
	t_stack	(*stack_a), (*stack_b);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = pars_args(&av[1], ac - 1);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (already_sorted(stack_a))
	{
		clear_stack(&stack_a);
		return (1);
	}
	checker_bns(&stack_a, &stack_b);
	clear_stack(&stack_a);
}
