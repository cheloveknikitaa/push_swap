/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:16:24 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/06 14:17:44 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pars(char **argv, t_stack **stack_a)
{
	int		i;
	int		j;
	char	**a;

	if (check_valid(argv) == 0)
		exit_fun();
	i = 1;
	while (argv[i])
	{
		a = ft_split(argv[i], ' ');
		if (a == NULL)
			exit_fun();
		create_stack(a, stack_a);
		i++;
	}
	if (stack_size(*stack_a) < 2)
		exit_fun();
	if (check_list(*stack_a) == 0)
		exit_fun();
	if (check_sort(*stack_a) == 0)
		exit (0);
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

void	create_stack(char **a, t_stack **stack_a)
{
	int		j;
	t_stack	*new;

	j = 0;
	while (a[j] != NULL)
	{
		new = stack_new(ft_atoi(a[j]));
		if (new == NULL)
			exit_fun();
		stack_add_back(stack_a, new);
		j++;
	}
	cs_2d_arr(a, j);
}

int		check_list(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*keep;
	int		repeat;

	keep = stack_a;
	while (stack_a)
	{
		repeat = 0;
		tmp = keep;
		while (tmp)
		{
			if (stack_a->content >= tmp->content)
			{
				if (stack_a->content == tmp->content)
					repeat++;
				else
					stack_a->index++;
				if (repeat > 1)
					return (0);
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void	cs_2d_arr(char **s, int count)
{
	while (count >= 0)
	{
		free(s[count]);
		s[count] = NULL;
		count--;
	}
	free (s);
	s = NULL;
}

int		check_sort(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
		{
			if (stack->index < stack->next->index)
				stack = stack->next;
			else
				return (1);
		}
		else
			return (0);
	}
	return (0);
}
