/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:15:27 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/20 16:13:44 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *stack)
{
	t_list *prelast;

	prelast = stack;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	ft_lstadd_front(&stack, ft_lstlast(stack));
	prelast->next = NULL;
}

void	rrb(t_list *stack)
{
	rra(stack);
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}