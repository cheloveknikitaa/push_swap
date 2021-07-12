#include "../includes/push_swap.h"

void	find_better_b(t_stack *a, t_stack *b)
{
	int		i;
	int		size;

	i = 0;
	size = stack_size(b);
	while (b)
	{
		if (i > size / 2)
			i = -i;
		find_better_a(a, b, i);
		b = b->next;
		i++;
	}
}

void	find_better_a(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	size;

	j = 1;
	size = stack_size(a);
	while (a)
	{
		if (j > size / 2)
			j = -j;
		if (a->index < b->index && a->next)
		{
			if (a->next->index > b->index)
			{
				b->moves_in_b = i;
				b->moves_in_a = j;
				return ;
			}
		}
		else if (a->index < b->index && !a->next)
		{
			b->moves_in_b = i;
			b->moves_in_a = -1;
			return ;
		}
		j++;
		a = a->next;
	}
}

t_stack	*check_finding_b(t_stack *a, t_stack *b)
{
	int		i;
	int		size;
	int		min_actions;
	t_stack	*min_actions_elem;

	i = 0;
	min_actions = 999999;
	min_actions_elem = stack_copy(NULL, b);
	size = stack_size(b);
	while (b)
	{
		if (i > size / 2)
			i = -i;
		check_finding_a(a, b, i);
		b->actions = abs(b->moves_in_a) + abs(b->moves_in_b);
		if (b->actions < min_actions)
		{
			min_actions = b->actions;
			min_actions_elem = stack_copy(min_actions_elem, b);
		}
		b = b->next;
		i++;
	}
	return (min_actions_elem);
}

void	check_finding_a(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	size;

	j = 0;
	size = stack_size(a);
	while (a)
	{
		if (j > size / 2)
			j = -j;
		if (a->index > b->index && a->next && b->moves_in_b == 0 && \
			b->moves_in_a == 0)
		{
			if (a->next->index > b->index)
			{
				b->moves_in_b = i;
				b->moves_in_a = j;
				return ;
			}
		}
		j++;
		a = a->next;
	}
}
