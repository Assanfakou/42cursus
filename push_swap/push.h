
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <unistd.h>

typedef struct s_stack
{
    int num;
    // int id_nim;
    struct s_stack *next;
}   s_stack;

void sa(s_stack **stack_a);
void sb(s_stack **stack_b);
void ss(s_stack **stack_a, s_stack **stack_b);

void pa(s_stack **stack_a, s_stack **stack_b);
void pb(s_stack **stack_a, s_stack **stack_b);

void ra(s_stack **stack_a);
void rb(s_stack **stack_b);

void rra(s_stack **stack);
