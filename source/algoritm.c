#include "../includes/push_swap.h"

void	sort_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	int		i;

	i = 1;
	while ((*stack_a)->actions != 1 && stack_size(*stack_a) > 5)
	{
		if ((*stack_a)->index >= 50 && (*stack_a)->index <= 55)
		{
			ra(stack_a);
			(*stack_a)->actions = i;
			i++;
		}
		else
			pb(stack_a, stack_b);
	}
	if (i < 5)
		sort_5numbers(stack_a, stack_b);
	while (stack_size(*stack_b))
	{
		find_better_b(*stack_a, *stack_b);
		target = check_finding_b(*stack_a, *stack_b);
		do_action(stack_a, stack_b, target);
		// print_stacks(*stack_a, *stack_b, target);
		free_all_action(*stack_a, *stack_b);
	}
	print_stacks(*stack_a, *stack_b, target);
	// while ((*stack_a)->index != 1)
	// 	ra(stack_a);
	exit (0);
}

void	do_action(t_stack **stack_a, t_stack **stack_b, t_stack *guide)
{
	int			i;
	static int	j;
	t_stack		*target;

	i = 0;
	moves_in_a();
	moves_in_b();
	pa(stack_a, stack_b);
	if (guide->moves_in_a == 1 && (*stack_a)->index > (*stack_a)->next->index \
		&& (*stack_a)->index < (*stack_a)->next->next->index)
		sa(stack_a);
	else if (guide->moves_in_a > 0)
		ra(stack_a);
	lets_go_party();
	cum_back();
}

void	cum_back()
{
	if (i > 0)
	{
		while (i > 0)
		{
			ra(stack_a);
			i--;
		}
		if ((*stack_a)->index > (*stack_a)->next->index)
			ra(stack_a);
	}
	else
	{
		while (i < 0)
		{
			rra(stack_a);
			i++;
		}
	}
}

void	moves_in_b()
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

void	moves_in_a()
{
	if (guide->moves_in_a < 0)
	{
		guide->moves_in_a = -guide->moves_in_a;
		while (guide->moves_in_a - 1 > 0)
		{
			rra(stack_a);
			guide->moves_in_a--;
			i++;
		}
	}
	else
	{
		while (guide->moves_in_a - 1 > 0)
		{
			ra(stack_a);
			guide->moves_in_a--;
			i--;
		}
	}
}

void	lets_go_party()
{
		if (*stack_b)
	{
		j++;
		if (i < 0)
		{
			free_all_action(*stack_a, *stack_b);
			find_better_b(*stack_a, *stack_b);
			target = check_finding_b(*stack_a, *stack_b);
			if (target->moves_in_a < 0)
			{
				do_action(stack_a, stack_b, target);
				return ;
			// print_stacks(*stack_a, *stack_b, target);
		}
		else if (i > 0)
		{
			free_all_action(*stack_a, *stack_b);
			find_better_b(*stack_a, *stack_b);
			target = check_finding_b(*stack_a, *stack_b);
			if (target->moves_in_a <= 0 && i >= abs(target->moves_in_a))
				do_action(stack_a, stack_b, target);
		}
	}
}
