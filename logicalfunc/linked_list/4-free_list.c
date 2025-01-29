#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void free_list(list_t *head)
{
    list_t *temp;
	// list_t *walk;

	if (!head)
		return ;
	// walk = head;
	while (head)
	{
		free(head->str);
        temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    list_t *head;

    head = NULL;
    add_node_end(&head, "Bob");
    add_node_end(&head, "&");
    add_node_end(&head, "Kris");
    add_node_end(&head, "love");
    add_node_end(&head, "asm");
    print_list(head);
    free_list(head);
    head = NULL;
    return (0);
}
