#include "../includes/push_swap.h"

void	sort_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	int		max_index;

	max_index = stack_size(*stack_a);
	while (stack_size(*stack_a) > 5)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == max_index || \
			(*stack_a)->index == max_index / 2)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	sort_5numbers(stack_a, stack_b);
	while (stack_size(*stack_b))
	{
		target = find_value_in_b(*stack_a, *stack_b);
		// print_stacks(*stack_a, *stack_b, target);
		do_action(stack_a, stack_b, target);
		// print_stacks(*stack_a, *stack_b, target);
		free_all_action(*stack_a, *stack_b);
	}
	if (now_sort(*stack_a) > max_index / 2)
	{
		while ((*stack_a)->index != 1)
			rra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != 1)
			ra(stack_a);
	}
	print_stacks(*stack_a, *stack_b, target);
}

void	do_action(t_stack **stack_a, t_stack **stack_b, t_stack *guide)
{
	moves_in_a(stack_a, guide);
	moves_in_b(stack_b, guide);
	pa(stack_a, stack_b);
	if (guide->moves_in_a == 1 && (*stack_a)->index > (*stack_a)->next->index \
		&& (*stack_a)->index < (*stack_a)->next->next->index)
		sa(stack_a);
	else if (guide->moves_in_a > 0)
		ra(stack_a);
}

void	moves_in_b(t_stack **stack_b, t_stack *guide)
{
	if (guide->moves_in_b < 0)
	{
		guide->moves_in_b = -guide->moves_in_b;
		while (guide->moves_in_b > 0 && guide->index != (*stack_b)->content)
		{
			rrb(stack_b);
			guide->moves_in_b--;
		}
	}
	else
	{
		while (guide->moves_in_b > 0)
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

void	free_all_action(t_stack *a, t_stack *b)
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
}
