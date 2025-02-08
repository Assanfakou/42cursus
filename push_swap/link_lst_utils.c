/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:48:30 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/08 10:53:51 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_stack *add_nodeint_end(s_stack **head, int n)
{
    s_stack *last;
    s_stack *walk;

    if (!head)
        return (NULL);
    last = malloc(sizeof(s_stack));
    last->next= NULL;
    last->num=n;
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
size_t print_listint(s_stack *h)
{
    size_t i;

    i = 0;
    while (h)
    {
        i++;
        ft_printf("%d -> ", h->num);
        h = h->next;
    }
    ft_printf("\n");
    return (i);
}
s_stack *add_nodeint(s_stack **head, s_stack *new)
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
void clear_stack(s_stack **stack)
{
    s_stack *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
    free(*stack);
}