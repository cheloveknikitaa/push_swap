/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 18:08:53 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_fun()
{
	write(1, "Error\n", 7);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	pars(argv, &stack_a);
	if (stack_size(stack_a) <= 3)
		sort_3numbers(&stack_a);
	else if (stack_size(stack_a) == 5)
		sort_5numbers(&stack_a, &stack_b);
	else
		sort_numbers(&stack_a, &stack_b);
	printf("---stack_a\n");
	print_stack(stack_a);
	printf("---stack_b\n");
	print_stack(stack_b);
}

void	sort_3numbers(t_stack **stack)
{
	t_stack	*last;

	if (stack_size(*stack) == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
		return;
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
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index <= 2)
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
	int	mid_i;
	int	max_i;

	max_i = max_index(*stack_a);
	mid_i = max_i / 2;
	while (min_in_a(*stack_a, mid_i))
	{
		if ((*stack_a)->index <= mid_i)
		{
			pb(stack_a, stack_b);
			if((*stack_a)->index > mid_i && (*stack_b)->index > mid_i / 2 + 1)
				rr(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
	mid_i = max_index(*stack_b) / 2 + 1;
	max_i = (*stack_a)->index;
	while ((*stack_b))
		magic(stack_a, stack_b, mid_i);
	printf("---stack_a\n");
	print_stack(*stack_a);
	printf("---stack_b\n");
	print_stack(*stack_b);
	exit (0);
	while ((*stack_a)->index != max_i)
		ra(stack_a);
	if (check_sort(*stack_a) == 0)
		return ;
	another_magic(stack_a, stack_b);
}

int		find_max_i(t_stack *stack)
{
	int	max;
	int	i;

	i = 0;
	max = max_index(stack);
	while (stack)
	{
		if (stack->index == max)
		{
			if (i == stack_size(stack))
				i--;
			return (i);
		}
		i++;
		stack = stack->next;
	}
	return (0);
}

int		find_min_i(t_stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = min_index(stack);
	while (stack)
	{
		if (stack->index == min)
		{
			if (i == stack_size(stack))
				i--;
			return (i);
		}
		i++;
		stack = stack->next;
	}
	return (0);
}

int		max_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

int		min_index(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (stack->index < i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	magic(t_stack **a, t_stack **b, int mid_i)
{
	int	len;
	int	i;

	len = stack_size(*b);
	if (len - find_min_i(*b) <= len - find_max_i(*b))
	{
		if (find_min_i(*b) <= len / 2)
		{
			i = find_min_i(*b);
			while (i--)
				rb(b);
			pa(a, b);
			ra(a);
		}
		else
		{
			i = len - find_min_i(*b);
			while (i--)
				rrb_or_sb(b);
			pa(a, b);
			ra(a);
		}
	}
	else
		magic2(a, b, mid_i);
}

void	magic2(t_stack **a, t_stack **b, int mid_i)
{
	int	i;
	int	len;

	len = stack_size(*b);
	if (len == 2)
	{
		if ((*b)->index < (*b)->next->index)
			sb(b);
		pa(a, b);
	}
	if (find_max_i(*b) < len / 2)
	{
		i = find_max_i(*b);
		while (i--)
			rb(b);
		pa(a, b);
	}
	else
	{
		i = len - find_max_i(*b);
		while (i--)
			rrb_or_sb(b);
		pa(a, b);
	}
}

void	rrb_or_sb(t_stack **b)
{
	if (stack_size(*b) <= 2)
		sb(b);
	else
		rrb(b);
}

void	another_magic(t_stack **stack_a, t_stack **stack_b)
{
	int	mid_i;
	int	max_i;
	int	len;

	max_i = max_index(*stack_a);
	mid_i = max_i / 2 + 1;
	while (stack_size(*stack_a) >= mid_i)
	{
		if ((*stack_a)->index >= mid_i)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	mid_i = max_index(*stack_b) / 2 + 1;
	max_i = (*stack_a)->index;
	while ((*stack_b))
		magic2(stack_a, stack_b, mid_i);
	while ((*stack_a)->index != max_i)
		ra(stack_a);
	if (check_sort(*stack_a) == 0)
		return ;
}

int	min_in_a(t_stack *a, int mid_i)
{
	while (a)
	{
		if (a->index <= mid_i)
			return (1);
		a = a->next;
	}
	return (0);
}

// void	what_better(t_stack **a, t_stack **b, int mid_i)
// {
// 	int	len;
// 	int	i;
// 	int	j;
// 	int	k;
// 	t_stack *tmp;

// 	len = stack_size(*a);
// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	while (i < len / 2 + 1)
// 	{
// 		if ((*a)->index <= mid_i)
// 			j++;
// 	}
// 	if ((*a)->index <= mid_i)
// 	{
// 		pb(a, b);
// 		if((*a)->index > mid_i && (*b)->index > mid_i / 2 + 1)
// 			rr(a, b);
// 	}
// 	else
// 		ra(a);
// }