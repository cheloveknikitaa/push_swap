#include "checker.h"

void	ra(t_stack **stack)
{
	t_stack	*last;

	last = stack_last(*stack);
	last->next = *stack;
	last = last->next;
	*stack = (*stack)->next;
	last->next = NULL;
}

void	rb(t_stack **stack)
{
	t_stack	*last;

	last = stack_last(*stack);
	last->next = *stack;
	last = last->next;
	*stack = (*stack)->next;
	last->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_a;
	t_stack	*last_b;

	last_a = stack_last(*stack_a);
	last_a->next = *stack_a;
	last_a = last_a->next;
	*stack_a = (*stack_a)->next;
	last_a->next = NULL;
	last_b = stack_last(*stack_b);
	last_b->next = *stack_b;
	last_b = last_b->next;
	*stack_b = (*stack_b)->next;
	last_b->next = NULL;
}
