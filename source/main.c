#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	pars(argv, &stack_a);
	if (stack_size(stack_a) <= 3)
		sort_3numbers(&stack_a);
	else if (stack_size(stack_a) == 4)
		sort_4numbers(&stack_a, &stack_b);
	else if (stack_size(stack_a) == 5)
		sort_5numbers(&stack_a, &stack_b);
	else
		sort_numbers(&stack_a, &stack_b);
	if (check_sort(stack_a) == 0)
		exit (0);
	print_stacks(stack_a, stack_b, NULL);
	return (0);
}

void	sort_3numbers(t_stack **stack)
{
	t_stack	*last;

	if (stack_size(*stack) == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
		return ;
	}
	last = stack_last(*stack);
	if ((*stack)->content > (*stack)->next->content && \
		(*stack)->content > last->content)
		ra(stack);
	last = stack_last(*stack);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
	if ((*stack)->content > last->content)
		rra(stack);
	else if ((*stack)->next->content > last->content)
	{
		rra(stack);
		sa(stack);
	}
	if (check_sort(*stack) == 0)
		return ;
	sort_3numbers(stack);
}

void	sort_4numbers(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_3numbers(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5numbers(t_stack **stack_a, t_stack **stack_b)
{
	int	min1;
	int	min2;

	min1 = find_need_index(*stack_a, 0);
	min2 = find_need_index(*stack_a, min1);
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == min1 || (*stack_a)->index == min2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		if (check_sort(*stack_a) == 0 && stack_size(*stack_b) == 0)
			return ;
	}
	if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_b)->content < (*stack_b)->next->content)
		ss(stack_a, stack_b);
	else if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	sort_3numbers(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

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
		do_action(stack_a, stack_b, target);
		free_all_action(*stack_a, *stack_b, target);
	}
	final(stack_a, max_index);
}
