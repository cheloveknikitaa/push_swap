/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/09 23:47:41 by nikita           ###   ########.fr       */
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
	while (stack_size(*stack_a) > 5)
		pb(stack_a, stack_b);
	sort_5numbers(stack_a, stack_b);
		printf("============\n");
		printf("---stack_a\n");
		print_stack(*stack_a);
		printf("---stack_b\n");
		print_stack(*stack_b);
		printf("============\n");
	while (stack_size(*stack_b) >= 2)
	{
		magic(*stack_a, *stack_b);
		printf("============\n");
		printf("---stack_a\n");
		print_stack(*stack_a);
		printf("---stack_b\n");
		print_stack(*stack_b);
		printf("============\n");
		do_action(stack_a, stack_b);
		free_all_action(*stack_a, *stack_b);
	}
	
}

void	do_action(t_stack **stack_a, t_stack **stack_b)
{
	int	code;
	int	action;

	action = find_min_action(*stack_b, &code);
	if (code == 0)
	{
		while ((*stack_b)->actions != action)
			rb(stack_b);
	}
	if (code == 1)
	{
		while ((*stack_b)->actions != action)
			rrb(stack_b);
	}
	action = find_min_action(*stack_a, &code);
	// check_dubl(*stack_a, *stack_b);
	do_action_part2(stack_a, stack_b, code, action);
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
		a = a->next;
	}
	while (b)
	{
		b->actions = 0;
		b = b->next;
	}
}

void	magic(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (b)
	{
		if (b->actions == 0)
			angel_dust(a, b, i);
		i += j;
		b = b->next;
		if (i > stack_size(b) / 2)
		{
			i = stack_size(b) - i;
			j = -j;
		}
	}
}

void	angel_dust(t_stack *a, t_stack *b, int i)
{
	while(a)
	{
		if (a->index == b->index - 1 && a->next)
		{
			if (a->next->index == b->index + 1)
				b->actions = i;
		}
		else if (a->index == b->index - 1 && !a->next)
			b->actions = i;
		if (b->actions != 0)
		{
			a->actions = 1;
			return	;
		}
		i++;
		a = a->next;
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

