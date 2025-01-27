#include "lists.h"
#include <stdlib.h>

void free_listint2(listint_t **head)
{
    listint_t *temp;
    listint_t *walk;

    if (!*head)
        return;
    walk = *head;
    while (walk->next)
    {
        temp = walk;
        walk = walk->next;
        free(walk);
    }
    *head = NULL;
}
#include <string.h>
#include <stdio.h>
// #include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    free_listint2(&head);
    printf("%p\n", (void *)head);
    return (0);
}
