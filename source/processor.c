#include "../includes/push_swap.h"

t_stack	*find_value_in_b(t_stack *a, t_stack *b)
{
	int		i;
	int		size;
	int		min_actions;
	t_stack	*min_actions_elem;

	i = 0;
	min_actions = 999999;
	min_actions_elem = stack_copy(NULL, b);
	i = 0;
	size = stack_size(b);
	while (b)
	{
		if (i > size / 2)
			i = -i;
		find_value_in_a(a, b, i);
		b->actions = abs(b->moves_in_a) + abs(b->moves_in_b);
		if (b->actions < min_actions && b->actions != 0)
		{
			min_actions = b->actions;
			min_actions_elem = stack_copy(min_actions_elem, b);
		}
		b = b->next;
		i++;
	}
	return (min_actions_elem);
}

void	find_value_in_a(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	size;

	j = 1;
	size = stack_size(a);
	while (a)
	{
		if (j > size / 2)
			j = -j;
		check_value(a, b, i, j);
		j++;
		a = a->next;
	}
}

void	check_value(t_stack *a, t_stack *b, int i, int j)
{
	if (a->index > b->index && a->next && b->moves_in_a == 0 && b->moves_in_a == 0)
	{
		if (a->next->index < b->index)
		{
			b->moves_in_b = i;
			b->moves_in_a = j;
			return ;
		}
	}
	if (a->index < b->index && a->next)
	{
		if (a->next->index > b->index)
		{
			b->moves_in_b = i;
			b->moves_in_a = j;
			return ;
		}
	}
	if (a->index < b->index && !a->next && b->moves_in_a == 0 && b->moves_in_a == 0)
	{
		b->moves_in_b = i;
		b->moves_in_a = -1;
		return ;
	}
	if (a->index > b->index && j == 1 && b->moves_in_a == 0 && b->moves_in_a == 0)
	{
		a = stack_last(a);
		if (a->index < b->index)
		{
			b->moves_in_b = i;
			b->moves_in_a = j;
			return ;
		}
	}
}

int		find_need_index(t_stack *stack, int i)
{
	int	min;

	min = 9999999;
	while (stack)
	{
		if (stack->index < min && stack->index != i)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
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
