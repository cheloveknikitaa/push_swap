/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:01:24 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/18 20:06:50 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pa(t_list *stack_a, t_list *stack_b)
{
	if (stack_b == NULL)
		return ;
	ft_lstadd_front(&stack_a, stack_b);
	stack_b = stack_b->next;
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	if (stack_a == NULL)
		return ;
	ft_lstadd_front(&stack_b, stack_a);
	stack_a = stack_a->next;
}s