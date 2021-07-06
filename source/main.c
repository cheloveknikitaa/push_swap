/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 11:15:45 by caugusta         ###   ########.fr       */
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
	int	i;
	t_stack *last;

	max_i = max_index(*stack_a);
	mid_i = max_i / 2;
	i = 0;
	while (stack_size(*stack_a) > mid_i)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_b)->content < (*stack_b)->next->content)
			ss(stack_a, stack_b);
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
	printf("---stack_a\n");
	print_stack(*stack_a);
	printf("---stack_b\n");
	print_stack(*stack_b);
	// while (stack_size(*stack_a) != max_i)
	// {
	// 	last = stack_last(*stack_a);
	// 	if (last->content > (*stack_b)->content)
			
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
