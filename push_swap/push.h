/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:08:05 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/03 18:08:18 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef I
# define I 1
# endif
typedef struct s_stack
{
    int num;
    struct s_stack *next;
}   s_stack;

void sa(s_stack **stack_a);
void sb(s_stack **stack_b);
void ss(s_stack **stack_a, s_stack **stack_b);

void pa(s_stack **stack_a, s_stack **stack_b);

void pb(s_stack **stack_a, s_stack **stack_b);

void ra(s_stack **stack_a);
void rb(s_stack **stack_b);

void rra(s_stack **stack);
void rrb(s_stack **stack);

s_stack *add_nodeint_end(s_stack **head, int n);
size_t print_listint(s_stack *h);
s_stack *add_nodeint(s_stack **head, s_stack *ne);
int listint_len(s_stack *h);

long ft_atol(const char *str);
char **fsplit(char *str, char c);
