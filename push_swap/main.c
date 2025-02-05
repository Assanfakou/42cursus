/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:01:09 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/05 22:58:44 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
int *fill_arr(s_stack *stack_h)
{
    int *arr;
    int size_lis;
    int i;

    size_lis = listint_len(stack_h);
    
    arr = malloc(sizeof(int) * (size_lis));
    if (!arr)
        return (NULL);
    i = 0;
    while (i < size_lis && stack_h)
    {
        arr[i] = stack_h->num;
        i++;
        stack_h = stack_h->next;
    }
    return (arr);
} 
void sort_arr(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        int sorted = 0;
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                sorted = 1;
            }
            j++;
        }
        i++;
        if (sorted == 0)
            break;
    }
}
int main(int ac, char **av)
{
    int i;
    int *arr;
    s_stack *stack_a = NULL;
    s_stack *stack_b = NULL;
    
   int j = ac - 1;

    stack_a = pars_args(&av[1], j);
    if (!stack_a)
        write(2, "Erour\n", 6);
    // print_listint(stack_a);
    arr = fill_arr(stack_a);
    // for(int i = 0; i < 14; i++)
    //     ft_printf("%d\n", arr[i]);
    sort_arr(arr, listint_len(stack_a));
   i = 0;
   while (i < 9){
        ft_printf("%d\n", arr[i]);
        i++;
    }

}


