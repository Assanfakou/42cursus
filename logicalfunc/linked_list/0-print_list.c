#include "header.h"
#include <string.h>
size_t print_list(const list_t *h)
{
	size_t i;

	i = 0;;
	while (h)
	{
		if (h->str != NULL)
			printf("[%ld] %s\n",strlen(h->str) , h->str);
		else
			printf("[0] nil\n");
		h = h->next;	
		i++;
	
	}
	return (i);
}
// #include <stdlib.h>
// #include <stdio.h>

// /**
//  * main - check the code
//  *
//  * Return: Always 0.
//  */
// int main(void)
// {
//     list_t *head;
//     list_t *new;
//     list_t hello = {"World", 5, NULL};
//     size_t n;

//     head = &hello;
//     new = malloc(sizeof(list_t));
//     if (new == NULL)
//     {
//         printf("Error\n");
//         return (1);
//     }
//     new->str = strdup("Hello");
//     new->len = 5;
//     new->next = head;
//     head = new;
//     n = print_list(head);
//     printf("-> %lu elements\n", n);

//     printf("\n");
//     free(new->str);
//     new->str = NULL;
//     n = print_list(head);
//     printf("-> %lu elements\n", n);

//     free(new);
//     return (0);
// }
