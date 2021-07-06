/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:15:27 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 04:56:11 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack)
{
	t_stack *prelast;

	prelast = *stack;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	stack_add_front(stack, stack_last(*stack));
	prelast->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	rra(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}