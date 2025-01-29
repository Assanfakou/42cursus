#include "lists.h"
#include <stdlib.h>
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new;

    new = malloc(sizeof(listint_t));
    new->n = n;
    if (!*head)
    {
        *head = new;
        (*head)->next = NULL;
    }
    else {
        new->next = *head;
        *head = new;
    }
    return (new);
}
#include <string.h>
#include <stdio.h>
// #include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
// int main(void)
// {
//     listint_t *head;

//     head = NULL;
//     add_nodeint(&head, 0);
//     add_nodeint(&head, 1);
//     add_nodeint(&head, 2);
//     add_nodeint(&head, 3);
//     add_nodeint(&head, 4);
//     add_nodeint(&head, 98);
//     add_nodeint(&head, 402);
//     add_nodeint(&head, 1024);
//     print_listint(head);
//     return (0);
// }
