#include "checker.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*keep;

	keep = (*stack_b)->next;
	if (stack_b == NULL)
		return ;
	stack_add_front(stack_a, *stack_b);
	*stack_b = keep;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*keep;

	keep = (*stack_a)->next;
	if (stack_a == NULL)
		return ;
	stack_add_front(stack_b, *stack_a);
	*stack_a = keep;
}

void	sa(t_stack **stack)
{
	t_stack	*keeper;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	keeper = *stack;
	*stack = (*stack)->next;
	keeper->next = (*stack)->next;
	(*stack)->next = keeper;
}

void	sb(t_stack **stack)
{
	t_stack	*keeper;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	keeper = *stack;
	*stack = (*stack)->next;
	keeper->next = (*stack)->next;
	(*stack)->next = keeper;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*keeper_a;
	t_stack	*keeper_b;

	if (stack_a != NULL || (*stack_a)->next != NULL)
	{
		keeper_a = *stack_a;
		*stack_a = (*stack_a)->next;
		keeper_a->next = (*stack_a)->next;
		(*stack_a)->next = keeper_a;
	}
	if (stack_b != NULL || (*stack_b)->next != NULL)
	{
		keeper_b = *stack_b;
		*stack_b = (*stack_b)->next;
		keeper_b->next = (*stack_b)->next;
		(*stack_b)->next = keeper_b;
	}
}
