/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:01:24 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 03:24:37 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == null)
		return ;
	stack_add_front(&stack_a, stack_b);
	stack_b = stack_b->next;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == null)
		return ;
	stack_add_front(&stack_b, stack_a);
	stack_a = stack_a->next;
}

void	sa(t_stack *stack)
{
	t_stack	*keeper;

	if (stack == NULL || stack->next == NULL)
		return ;
	keeper = stack;
	stack = stack->next;
	keeper->next = stack->next;
	stack->next = keeper;
}

void	sb(t_stack *stack)
{
	t_stack	*keeper;

	if (stack == NULL || stack->next == NULL)
		return ;
	keeper = stack;
	stack = stack->next;
	keeper->next = stack->next;
	stack->next = keeper;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
