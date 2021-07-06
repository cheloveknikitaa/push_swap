/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:15:27 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 01:21:56 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_stack *prelast;

	prelast = stack;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	stack_add_front(&stack, stack_last(stack));
	prelast->next = NULL;
}

void	rrb(t_stack *stack)
{
	rra(stack);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}