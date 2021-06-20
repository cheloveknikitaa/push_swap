/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:16:24 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/20 21:05:07 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pars(char **argv)
{
	int		i;
	int		j;
	char	**a;
	t_list	*stack_a;

	// if (check_valid(argv) == 0)
	// 	exit_fun();
	i = 1;
	while (argv[i])
	{
		a = ft_split(argv[i], ' ');
		create_stack(a, &stack_a);
		i++;
	}
	// if (check_list(stack_a) == 0)
	// 	exit_fun();
	return (stack_a);
}

int		check_valid(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	create_stack(char **a, t_list **stack_a)
{
	int		j;
	t_list	*new;
	int		tmp;
	t_list	*last;
	t_list	*keep;

	*stack_a = keep;
	last = *stack_a;
	if (*stack_a != NULL)
		last = ft_lstlast(*stack_a);
	// write(1, "here\n", 5);
	j = 0;
	while (a[j] != NULL)
	{
		tmp = ft_atoi(a[j]);
		new = ft_lstnew(&tmp);
		if (new == NULL)
			exit_fun();
		write(1, "here\n", 5);
		if (*stack_a == NULL)
		{
			write(1, "aere\n", 5);
			*stack_a = new;
			keep = *stack_a;
		}
		else
		{
			//keep = *stack_a;
			(*stack_a)->next = new;
			*stack_a = (*stack_a)->next;
		}
		//printf("<%d\n", *(int *)(keep)->content);
		printf(">%d\n", *(int *)(*stack_a)->content);
		// ft_lstadd_back(&stack_a, new);
		j++;
	}
	*stack_a = last;
	while ((keep))
	{
		printf("%d\n", *(int *)(keep)->content);
		(keep) = (keep)->next;
	}
}

int	check_list(t_list *stack_a)
{
	t_list	*tmp;
	
	while (stack_a)
	{
		if (stack_a->next)
			tmp = stack_a->next;
		else
			return (1);
		while (tmp)
		{
			if (stack_a->content == tmp->content)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void	exit_fun()
{
	exit (1);
}
