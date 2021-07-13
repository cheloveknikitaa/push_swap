#include "push_swap.h"

t_stack	*stack_copy(t_stack *copy, t_stack *original)
{
	free(copy);
	copy = NULL;
	copy = malloc(sizeof(t_stack));
	if (copy == NULL)
		exit_fun();
	copy->content = original->content;
	copy->index = original->index;
	copy->actions = original->actions;
	copy->moves_in_a = original->moves_in_a;
	copy->moves_in_b = original->moves_in_b;
	copy->next = NULL;
	return (copy);
}

int	now_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index == 1)
			return (i);
		i++;
		a = a->next;
	}
	return (i);
}

void	final(t_stack **stack_a, int max_index)
{
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
}
