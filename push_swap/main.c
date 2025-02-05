/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:01:09 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/05 11:30:16 by assankou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
// int *fill_arr(s_stack *stack_h)
// {
//     int *arr;
//     int size_lis;
//     int i;

//     size_lis = listint_len(stack_h);
    
//     arr = malloc(sizeof(int) * (size_lis));
//     if (!arr)
//         return (NULL);
//     i = 0;
//     while (i < size_lis && stack_h)
//     {
//         arr[i] = stack_h->num;
//         i++;
//         stack_h = stack_h->next;
//     }
//     return (arr);
// }
void *sort_arr(int *arr)
{
    int i;
    int j;
    int sorted;
    int temp;
    int size;

    size = 0;
    while (arr[size])
        size++;
    i = 0;
    while (i < (size - 1))
    {
        sorted = 0;
        j = 0;
        while (j < (size - i - 1))
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 1;
            }
            j++;
        }
        i++;
        if (sorted == 0)
            break;
    }
}
// int main(int ac, char **av)
// {
//     int i;
//     int *arr;
//     s_stack *stack_a = NULL;
//     s_stack *stack_b = NULL;
    
//    int j = ac - 1;

//     stack_a = pars_args(&av[1], j);
//     if (!stack_a)
//         write(2, "Erour\n", 6);
//     // print_listint(stack_a);
//     arr = fill_arr(stack_a);
//     // for(int i = 0; i < 14; i++)
//     //     ft_printf("%d\n", arr[i]);
//     sort_arr(arr);
//    i = 0;
//    while (i < 9){
//         ft_printf("%d\n", arr[i]);
//         i++;
//     }

// }
int main ()
{
    int a[] = {18, 2, 6};

    sort_arr(a);
    int i = 0;
    // while (i < 5)
    // {  
        printf("%d\n efr", 4);
        // i++;
    // }
}

