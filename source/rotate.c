/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:07:47 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/20 16:13:44 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *stack)
{
	t_list *last;

	last = ft_lstlast(stack);
	last->next = stack;
	last = last->next;
	stack = stack->next;
	last->next = NULL;
}

void	rb(t_list *stack)
{
	t_list *last;

	last = ft_lstlast(stack);
	last->next = stack;
	last = last->next;
	stack = stack->next;
	last->next = NULL;
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
