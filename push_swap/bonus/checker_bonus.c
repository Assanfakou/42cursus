/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:23:42 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/12 20:36:45 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
void statements(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strcmp(line, "rra\n") == 0)
            rra(stack_a);
        else if (ft_strcmp(line, "rrb\n") == 0)
            rrb(stack_b);
        else if (ft_strcmp(line, "pa\n") == 0)
            pa(stack_a, stack_b);
        else if (ft_strcmp(line, "pb\n") == 0)
            pb(stack_a, stack_b);
        else if (ft_strcmp(line, "sa\n") == 0)
            sa(stack_a);
        else if (ft_strcmp(line, "sb\n") == 0)
            sb(stack_b);
        else if (ft_strcmp(line, "ra\n") == 0)
            ra(stack_a);
        else if (ft_strcmp(line, "rb\n") == 0)
            rb(stack_b);
        else if (ft_strcmp(line, "ss\n") == 0)
            ss(stack_a, stack_b);
        else
        {
            write(2, "Error\n", 6);
            free(line);
            exit(EXIT_FAILURE);
        }
}

void checker_bns(t_stack **stack_a, t_stack **stack_b)
{
    char *line;

    line = get_next_line(0);
    while (line != NULL)
    {
        statements(line, stack_a, stack_b);
        free(line);
        line = get_next_line(0);
    }
    if (already_sorted(*stack_a) == 1)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}
