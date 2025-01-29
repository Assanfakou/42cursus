#include "lists.h"

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;
    if (!head)
        return(NULL);

    i = 0;
    while (head)
    {
        if (index == i)
            return (head);
        head = head->next;
        i++;
    }
    return (NULL);
}
// #include <stdlib.h>
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
//     listint_t *node;

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
//     node = get_nodeint_at_index(head, 8);
//     printf("->%d\n", node->n);
//     print_listint(head);
//     free_listint2(&head);
//     return (0);
// }
