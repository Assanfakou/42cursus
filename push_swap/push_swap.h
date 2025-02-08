/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:08:05 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/08 10:50:18 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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
void clear_stack(s_stack **stack);

long ft_atol(const char *str);
char **fsplit(char *str, char c);
int is_valid_input(char *input);
int pars_arr(char **arr, s_stack **stack);
s_stack *pars_args(char **arg, int size);

void free_arr(char **arr);
int *fill_arr(s_stack *stack_h);
void sort_arr(int *arr, int size);
int check_duplicat(int *arr, int size);

int calcul_ops(s_stack **b, int ind_big);
int get_big_idx(s_stack **b);
void push_to_b(s_stack **a, s_stack **b, int small, int big);
void sort_stack(s_stack **stack_a, s_stack **stack_b, int *arr, int size_ofstack);
void push_to_a(s_stack **a, s_stack **b, int big_idx);
void loop_in_b(s_stack **b, s_stack **a);

#endif