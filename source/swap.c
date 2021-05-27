/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:51:04 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/27 21:27:16 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(t_list *stack)
{
	t_list	*keeper;

	if (stack == NULL || stack->next == NULL)
		return ;
	keeper = stack;
	stack = stack->next;
	keeper->next = stack->next;
	stack->next = keeper;
}

void	sb(t_list *stack)
{
	t_list	*keeper;

	if (stack == NULL || stack->next == NULL)
		return ;
	keeper = stack;
	stack = stack->next;
	keeper->next = stack->next;
	stack->next = keeper;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
