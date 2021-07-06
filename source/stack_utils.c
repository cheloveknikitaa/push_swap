/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 01:16:08 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/07 00:55:58 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = stack_last(*lst);
		(last)->next = new;
	}
}

void	stack_add_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	first = new;
	first->next = *lst;
	*lst = first;
}

t_stack	*stack_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*stack_new(int content)
{
	t_stack		*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->index = 1;
	new->actions = 0;
	new->next = NULL;
	return (new);
}

int	stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("chislo %d ego index %d ego actions %d\n", stack->content, stack->index, stack->actions);
		stack = stack->next;
	}
}

	// printf("---stack_a\n");
	// print_stack(stack_a);
	// printf("---stack_b\n");
	// print_stack(stack_b);