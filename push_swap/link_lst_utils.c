/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:48:30 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/14 17:54:09 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_nodeint_end(t_stack **head, int n)
{
	t_stack	*last;
	t_stack	*walk;

	if (!head)
		return (NULL);
	last = malloc(sizeof(t_stack));
	last->next = NULL;
	last->num = n;
	if (!*head)
		*head = last;
	else
	{
		walk = *head;
		while (walk->next)
			walk = walk->next;
		walk->next = last;
	}
	return (last);
}

size_t	print_listint(t_stack *h)
{
	size_t	i;

	i = 0;
	while (h)
	{
		i++;
		printf("%d -> ", h->num);
		h = h->next;
	}
	printf("\n");
	return (i);
}

t_stack	*add_nodeint(t_stack **head, t_stack *new)
{
	if (!*head)
	{
		*head = new;
		(*head)->next = NULL;
	}
	else
	{
		new->next = *head;
		*head = new;
	}
	return (new);
}

int	listint_len(t_stack *h)
{
	int	i;

	i = 0;
	while (h)
	{
		i++;
		h = h->next;
	}
	return (i);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(*stack);
}
