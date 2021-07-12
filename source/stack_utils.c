/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 01:16:08 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/12 04:04:23 by nikita           ###   ########.fr       */
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
	while (lst->next != NULL)
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

t_stack	*stack_copy(t_stack *copy, t_stack *original)
{
	free(copy);
	copy = NULL;
	copy = malloc(sizeof(t_stack));
	if (copy == NULL)
		exit_fun();
	copy->content = original->content;
	copy->index = original->index;
	copy->actions = original->actions;
	copy->moves_in_a = original->moves_in_a;
	copy->moves_in_b = original->moves_in_b;
	copy->next = NULL;
	return (copy);
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
		ft_printf("|| index %3d | actions %3d | move_a %3d | move_b %3d ||\n", \
			stack->index, stack->actions, stack->moves_in_a, stack->moves_in_b);
		stack = stack->next;
	}
}

void	print_stacks(t_stack *a, t_stack *b, t_stack *target)
{
	ft_printf("=======================================================\n");
	ft_printf("||%19.0s---stack_a---%19.0s||\n", NULL, NULL);
	ft_printf("=======================================================\n");
	print_stack(a);
	ft_printf("=======================================================\n");
	ft_printf("||%19.0s---target---%20.0s||\n", NULL, NULL);
	ft_printf("=======================================================\n");
	print_stack(target);
	ft_printf("=======================================================\n");
	ft_printf("||%19.0s---stack_b---%19.0s||\n", NULL, NULL);
	ft_printf("=======================================================\n");
	print_stack(b);
	ft_printf("=======================================================\n");
}

	// printf("---stack_a\n");
	// print_stack(stack_a);
	// printf("---stack_b\n");
	// print_stack(stack_b);