/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/12 05:53:01 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_fun(void)
{
	write(1, "Error\n", 7);
	exit (1);
}

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
	else if (stack_size(stack_a) == 5)
		sort_5numbers(&stack_a, &stack_b);
	else
		sort_numbers(&stack_a, &stack_b);
	ft_printf("---stack_a\n");
	print_stack(stack_a);
	ft_printf("---stack_b\n");
	print_stack(stack_b);
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

int	find_need_index(t_stack *stack, int i)
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

void	sort_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	int		i;

	i = 1;
	while ((*stack_a)->actions != 1 && stack_size(*stack_a) > 5)
	{
		if ((*stack_a)->index == i)
		{
			ra(stack_a);
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
		print_stacks(*stack_a, *stack_b, target);
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
	pa(stack_a, stack_b);
	if (guide->moves_in_a == 1 && (*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index < (*stack_a)->next->next->index)
		sa(stack_a);
	else if (guide->moves_in_a > 0)
		ra(stack_a);
	if (stack_b)
	{
		j++;
		if (i < 0)
		{
			free_all_action(*stack_a, *stack_b);
			find_better_b(*stack_a, *stack_b);
			target = check_finding_b(*stack_a, *stack_b);
			if (target->moves_in_a > 0 && abs(i) >= target->moves_in_a)
				do_action(stack_a, stack_b, target);
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
	else
		j = 0;
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

void	do_action_part2(t_stack **stack_a, t_stack **stack_b, int code, int action)
{
	int	i;

	i = 0;
	if (code == 0)
	{
		while ((*stack_a)->actions != action)
		{
			ra(stack_a);
			i++;
		}
		pa(stack_a, stack_b);
		while (i--)
			rra(stack_a);
	}
	if (code == 1)
	{
		while ((*stack_a)->actions != action && (*stack_a)->next)
		{
			rra(stack_a);
			i++;
		}
		pa(stack_a, stack_b);
		i++;
		while (i--)
			ra(stack_a);
	}
}

int	find_min_action(t_stack *b, int	*code)
{
	int	i;
	int	j;
	int	size;

	i = 999999;
	size = stack_size(b);
	while (b)
	{
		if (b->actions < i && b->actions != 0)
			i = b->actions;
		b = b->next;
		j++;
	}
	if (j <= size / 2)
		*code = 0;
	else
		*code = 1;
	return (i);
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

void	check_dubl(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	k;
	t_stack	*tmp;

	j = 0;
	k = 0;
	i = find_min_action(b, &k);
	while (a)
	{
		if (a->actions == 1)
		{
			k++;
			if (k > 1)
				a->actions = 10000;
			else
				tmp = a;
		}
		a = a->next;
	}
	while (b)
	{
		if (b->actions == i)
		{
			j++;
			if (b->index - tmp->index != 1)
				b->actions = 10000;
		}
		b = b->next;
	}
}

