/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/24 01:42:22 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fun()
{
	exit (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_a_save;
	t_list	*stack_b;

	stack_a = pars(argv);
	stack_a_save = stack_a;
	while (stack_a)
	{
		printf("%d\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	while (1);
}
