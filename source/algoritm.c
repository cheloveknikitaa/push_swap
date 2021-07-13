#include "../includes/push_swap.h"

void	do_action(t_stack **stack_a, t_stack **stack_b, t_stack *guide)
{
	moves_in_ab(stack_a, stack_b, guide);
	moves_in_a(stack_a, guide);
	moves_in_b(stack_b, guide);
	pa(stack_a, stack_b);
	if (guide->moves_in_a == 1 && (*stack_a)->index > (*stack_a)->next->index \
		&& (*stack_a)->index < (*stack_a)->next->next->index)
		sa(stack_a);
	else if (guide->moves_in_a > 0)
		ra(stack_a);
}

void	moves_in_ab(t_stack **stack_a, t_stack **stack_b, t_stack *guide)
{
	if (guide->moves_in_b < 0 && guide->moves_in_a < 0)
	{
		guide->moves_in_b = -guide->moves_in_b;
		guide->moves_in_a = -guide->moves_in_a;
		while (guide->moves_in_b > 0 && guide->index != (*stack_b)->index && \
			guide->moves_in_a - 1 > 0)
		{
			rrr(stack_a, stack_b);
			guide->moves_in_b--;
			guide->moves_in_a--;
		}
		guide->moves_in_b = -guide->moves_in_b;
		guide->moves_in_a = -guide->moves_in_a;
	}
	else if (guide->moves_in_b > 0 && guide->moves_in_a > 0)
	{
		while (guide->moves_in_b > 0 && guide->index != (*stack_b)->index && \
			guide->moves_in_a - 1 > 0)
		{
			rr(stack_a, stack_b);
			guide->moves_in_b--;
			guide->moves_in_a--;
		}
	}
}

void	moves_in_b(t_stack **stack_b, t_stack *guide)
{
	if (guide->moves_in_b < 0)
	{
		guide->moves_in_b = -guide->moves_in_b;
		while (guide->moves_in_b > 0 && guide->index != (*stack_b)->index)
		{
			rrb(stack_b);
			guide->moves_in_b--;
		}
	}
	else
	{
		while (guide->moves_in_b > 0 && guide->index != (*stack_b)->index)
		{
			rb(stack_b);
			guide->moves_in_b--;
		}
	}
}

void	moves_in_a(t_stack **stack_a, t_stack *guide)
{
	if (guide->moves_in_a < 0)
	{
		guide->moves_in_a = -guide->moves_in_a;
		while (guide->moves_in_a - 1 > 0)
		{
			rra(stack_a);
			guide->moves_in_a--;
		}
	}
	else
	{
		while (guide->moves_in_a - 1 > 0)
		{
			ra(stack_a);
			guide->moves_in_a--;
		}
	}
}

void	free_all_action(t_stack *a, t_stack *b, t_stack *target)
{
	while (a)
	{
		a->actions = 0;
		a->moves_in_a = 0;
		a->moves_in_b = 0;
		a = a->next;
	}
	while (b)
	{
		b->actions = 0;
		b->moves_in_a = 0;
		b->moves_in_b = 0;
		b = b->next;
	}
	free(target);
	target = NULL;
}
