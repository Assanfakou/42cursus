#include "lists.h"
#include <stdlib.h>

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *walk;
    listint_t *tmp;

    if (idx == 0)
        return (add_nodeint(head, n));
    if (!head || !*head)
        return (NULL);
    tmp = malloc(sizeof(listint_t));
    tmp->n =n;
    walk = get_nodeint_at_index(*head, (idx - 1));
    listint_t *next_of_walk = walk->next;
    walk->next = tmp;
    tmp->next = next_of_walk;
    return (tmp);
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
    printf("-----------------\n");
    insert_nodeint_at_index(&head, 9, 69);
    print_listint(head);
    free_listint2(&head);
    return (0);
}
