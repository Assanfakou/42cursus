#include "lists.h"
#include <stdlib.h>

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *last;
    listint_t *walk;

    last = malloc(sizeof(listint_t));
    last->n=n;
    if (!*head)
    {
        *head = last;
        (*head)->next=NULL;
    }
    else {
        walk = *head;
        while (walk->next)
        {
            walk = walk->next;
        }
        walk->next = last;
        last->next= NULL;
    }
    return (last);
}
// #include <string.h>
// #include <stdio.h>
// // #include "lists.h"

// /**
//  * main - check the code
//  *
//  * Return: Always 0.
//  */
// int main(void)
// {
//     listint_t *head;

//     head = NULL;
//     add_nodeint_end(&head, 0);
//     add_nodeint_end(&head, 1);
//     add_nodeint_end(&head, 2);
//     add_nodeint_end(&head, 3);
//     add_nodeint_end(&head, 4);
//     add_nodeint_end(&head, 98);
//     add_nodeint_end(&head, 402);
//     add_nodeint_end(&head, 1024);
//     print_listint(head);
//     return (0);
// }

// // int main(int ac, char **arg)
// // {
// //     int i;
// //     int j;

// //     if (ac == 3)
// //     {
// //         j = 0;
// //         i = 0;
// //         while (av[1][i] && av[2][j])
// //     }
// }
