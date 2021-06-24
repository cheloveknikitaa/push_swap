/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/24 04:26:24 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fun()
{
	write(1, "Error\n", 7);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = pars(argv);
	// make_index(stack_a);
}

// void	make_index(t_list *stack_a)
// {
// 	t_list	*keep;
// 	t_list	*tmp;

// 	keep = stack_a;
// 	while(stack_a)
// 	{
// 		tmp = keep;
// 		while (tmp)
// 		{
// 			if (*(int *)(stack_a->content) > *(int *)(tmp->content))
// 				stack_a->index =
// 			tmp = tmp->next;
// 		}
// 		stack_a = stack_a->next;
// 	}
// }
