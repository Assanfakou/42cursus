/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:08:05 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/15 14:16:14 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);

void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack_a, t_stack **stack_b);

t_stack				*add_nodeint_end(t_stack **head, int n);
size_t				print_listint(t_stack *h);
t_stack				*add_nodeint(t_stack **head, t_stack *ne);
int					listint_len(t_stack *h);
void				clear_stack(t_stack **stack);

long				ft_atol(const char *str);
char				**fsplit(char *str, char c);
int					is_valid_input(char *input);
int					pars_arr(char **arr, t_stack **stack);
t_stack				*pars_args(char **arg, int size);

void				free_arr(char **arr);
int					*fill_arr(t_stack *stack_h);
void				sort_arr(int *arr, int size);
int					check_duplicat(int *arr, int size);

int					already_sorted(t_stack *stack_a);

int					checker_bns(t_stack **stack_a, t_stack **stack_b);
int					statements(char *line, t_stack **stack_a,
						t_stack **stack_b);
void				ft_exit(void);
int					ft_strcmp(char *s1, char *s2);

void				ft_print_er(char **line);

#endif