/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:01:24 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 05:03:00 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *keep;

	keep = (*stack_b)->next;
	if (stack_b == NULL)
		return ;
	stack_add_front(stack_a, *stack_b);
	*stack_b = keep;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *keep;

	keep = (*stack_a)->next;
	if (stack_a == NULL)
		return ;
	stack_add_front(stack_b, *stack_a);
	*stack_a = keep;
	write(1, "pb\n", 3);
}

void	sa(t_stack **stack)
{
	t_stack	*keeper;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	keeper = *stack;
	*stack = (*stack)->next;
	keeper->next = (*stack)->next;
	(*stack)->next = keeper;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	t_stack	*keeper;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	keeper = *stack;
	*stack = (*stack)->next;
	keeper->next = (*stack)->next;
	(*stack)->next = keeper;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
