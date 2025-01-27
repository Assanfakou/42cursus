#include "header.h"
#include <stdlib.h>

#include <string.h>

list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *walk;

    if (new == NULL)
        return (NULL);
    new->str = strdup(str);
    if (new->str == NULL)
    {
        free(new);
        return (NULL);
    }
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        walk = *head;
        while (walk->next != NULL)
            walk = walk->next;
        walk->next = new;
    }
    return (new);
}
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    list_t *head;

    head = NULL;
    add_node_end(&head, "Anne");
    add_node_end(&head, "Colton");
    add_node_end(&head, "Corbin");
    add_node_end(&head, "Daniel");
    add_node_end(&head, "Danton");
    add_node_end(&head, "David");
    add_node_end(&head, "Gary");
    add_node_end(&head, "Holden");
    add_node_end(&head, "Ian");
    add_node_end(&head, "Ian");
    add_node_end(&head, "Jay");
    add_node_end(&head, "Jennie");
    add_node_end(&head, "Jimmy");
    add_node_end(&head, "Justin");
    add_node_end(&head, "Kalson");
    add_node_end(&head, "Kina");
    add_node_end(&head, "Matthew");
    add_node_end(&head, "Max");
    add_node_end(&head, "Michael");
    add_node_end(&head, "Ntuj");
    add_node_end(&head, "Philip");
    add_node_end(&head, "Richard");
    add_node_end(&head, "Samantha");
    add_node_end(&head, "Stuart");
    add_node_end(&head, "Swati");
    add_node_end(&head, "Timothy");
    add_node_end(&head, "Victor");
    add_node_end(&head, "Walton");
    print_list(head);
    return (0);
}
