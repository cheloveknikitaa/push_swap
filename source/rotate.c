/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:07:47 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 07:28:25 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack)
{
	t_stack *last;

	last = stack_last(*stack);
	last->next = *stack;
	last = last->next;
	*stack = (*stack)->next;
	last->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	t_stack *last;

	last = stack_last(*stack);
	last->next = *stack;
	last = last->next;
	*stack = (*stack)->next;
	last->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *last_a;
	t_stack *last_b;

	last_a = stack_last(*stack_a);
	last_a->next = *stack_a;
	last_a = last_a->next;
	*stack_a = (*stack_a)->next;
	last_a->next = NULL;
	last_b = stack_last(*stack_b);
	last_b->next = *stack_b;
	last_b = last_b->next;
	*stack_b = (*stack_b)->next;
	last_b->next = NULL;
	write(1, "rr\n", 3);
}
