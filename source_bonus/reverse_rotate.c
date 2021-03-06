#include "checker.h"

void	rra(t_stack **stack)
{
	t_stack	*prelast;

	if (*stack == NULL)
		return ;
	prelast = *stack;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	stack_add_front(stack, stack_last(*stack));
	prelast->next = NULL;
}

void	rrb(t_stack **stack)
{
	t_stack	*prelast;

	if (*stack == NULL)
		return ;
	prelast = *stack;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	stack_add_front(stack, stack_last(*stack));
	prelast->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*prelast_a;
	t_stack	*prelast_b;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	prelast_a = *stack_a;
	while (prelast_a->next->next != NULL)
		prelast_a = prelast_a->next;
	stack_add_front(stack_a, stack_last(*stack_a));
	prelast_a->next = NULL;
	prelast_b = *stack_b;
	while (prelast_b->next->next != NULL)
		prelast_b = prelast_b->next;
	stack_add_front(stack_b, stack_last(*stack_b));
	prelast_b->next = NULL;
}
