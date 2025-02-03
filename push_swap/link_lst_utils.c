#include "push.h"

s_stack *add_nodeint_end(s_stack **head, int n)
{
    s_stack *last;
    s_stack *walk;

    if (!head)
        return (NULL);
    last = malloc(sizeof(s_stack));
    last->next= NULL;
    last->num=n;
    if (!*head)
        *head = last;
    else
    {
        walk = *head;
        while (walk->next)
            walk = walk->next;
        walk->next = last;
    }
    return (last);
}
size_t print_listint(s_stack *h)
{
    size_t i;

    i = 0;
    while (h)
    {
        i++;
        printf("%d -> ", h->num);
        h = h->next;
    }
    printf("\n");
    return (i);
}
s_stack *add_nodeint(s_stack **head, s_stack *new)
{
    if (!*head)
    {
        *head = new;
        (*head)->next = NULL;
    }
    else
    {
        new->next = *head;
        *head = new;
    }
    return (new);
}
int listint_len(s_stack *h)
{
    int i;

    i = 0;
    while (h)
    {
        i++;
        h = h->next;
    }
    return (i);
}
