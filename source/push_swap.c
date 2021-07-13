#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*keep;

	if (*stack_b == NULL)
		return ;
	keep = (*stack_b)->next;
	stack_add_front(stack_a, *stack_b);
	*stack_b = keep;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*keep;

	if (*stack_a == NULL)
		return ;
	keep = (*stack_a)->next;
	stack_add_front(stack_b, *stack_a);
	*stack_a = keep;
	write(1, "pb\n", 3);
}

void	sa(t_stack **stack)
{
	t_stack	*keeper;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	keeper = *stack;
	*stack = (*stack)->next;
	keeper->next = (*stack)->next;
	(*stack)->next = keeper;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	t_stack	*keeper;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	keeper = *stack;
	*stack = (*stack)->next;
	keeper->next = (*stack)->next;
	(*stack)->next = keeper;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*keeper_a;
	t_stack	*keeper_b;

	if (*stack_a != NULL || (*stack_a)->next != NULL)
	{
		keeper_a = *stack_a;
		*stack_a = (*stack_a)->next;
		keeper_a->next = (*stack_a)->next;
		(*stack_a)->next = keeper_a;
	}
	if (*stack_b != NULL || (*stack_b)->next != NULL)
	{
		keeper_b = *stack_b;
		*stack_b = (*stack_b)->next;
		keeper_b->next = (*stack_b)->next;
		(*stack_b)->next = keeper_b;
	}
	write(1, "ss\n", 3);
}
