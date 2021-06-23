/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:16:24 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/24 01:43:11 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pars(char **argv)
{
	int		i;
	int		j;
	char	**a;
	t_list	*stack_a;

	if (check_valid(argv) == 0)
		exit_fun();
	i = 1;
	while (argv[i])
	{
		a = ft_split(argv[i], ' ');
		create_stack(a, &stack_a);
		i++;
	}
	if (check_list(stack_a) == 0)
		exit_fun();
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
	int		*tmp;

	j = 0;
	while (a[j] != NULL)
	{
		tmp = malloc(sizeof(int));
		*tmp = ft_atoi(a[j]);
		new = ft_lstnew(tmp);
		if (new == NULL)
			exit_fun();
		ft_lstadd_back(stack_a, new);
		j++;
	}
	cs_2d_arr(a, j);
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
