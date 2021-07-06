/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:07:47 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 01:21:56 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_stack *last;

	last = stack_last(stack);
	last->next = stack;
	last = last->next;
	stack = stack->next;
	last->next = NULL;
}

void	rb(t_stack *stack)
{
	t_stack *last;

	last = stack_last(stack);
	last->next = stack;
	last = last->next;
	stack = stack->next;
	last->next = NULL;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
