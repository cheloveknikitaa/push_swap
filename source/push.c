/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:01:24 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 03:18:26 by caugusta         ###   ########.fr       */
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
