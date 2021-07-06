/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 06:22:04 by caugusta         ###   ########.fr       */
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
	if (stack_size(stack_a) == 3)
		sort_3numbers(&stack_a, &stack_b);
	// if (stack_size(stack_a) == 5)
	// 	sort_5numbers(&stack_a, &stack_b);
	// else
	// 	sort_number(&stack_a, &stack_b)
	printf("---stack_a\n");
	print_stack(stack_a);
	printf("---stack_b\n");
	print_stack(stack_b);
}

void	sort_3numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;

	last = stack_last(*stack_a);
	if ((*stack_a)->content > last->content)
		ra(stack_a);
	last = stack_last(*stack_a);
	if ((*stack_a)->content > last->content)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
	else if((*stack_a)->next->content > last->content)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (check_sort(*stack_a) == 0)
	{
		printf("---stack_a\n");
		print_stack(*stack_a);
		printf("---stack_b\n");
		print_stack(*stack_b);
		exit (0);
	}
	sort_3numbers(stack_a, stack_b);
}
