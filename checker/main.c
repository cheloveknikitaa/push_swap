#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	line = NULL;
	if (argc < 2)
		return (0);
	pars(argv, &stack_a);
	while (1)
	{
		i = get_next_line(0, &line);
		if (i == -1)
			exit_fun();
		else if (i == 0)
			break ;
		all_command(line, &stack_a, &stack_b);
		free(line);
		line = NULL;
	}
	check_sort(stack_a);
	return (0);
}

void	all_command(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "pa", 5))
		pa(a, b);
	else if (ft_strncmp(line, "pb", 5))
		pb(a, b);
	else if (ft_strncmp(line, "rra", 5))
		rra(a);
	else if (ft_strncmp(line, "rrb", 5))
		rrb(b);
	else if (ft_strncmp(line, "rrr", 5))
		rrr(a, b);
	else if (ft_strncmp(line, "ra", 5))
		ra(a);
	else if (ft_strncmp(line, "rb", 5))
		rb(b);
	else if (ft_strncmp(line, "rr", 5))
		rr(a, b);
	else if (ft_strncmp(line, "sa", 5))
		sa(a);
	else if (ft_strncmp(line, "sb", 5))
		sb(b);
	else if (ft_strncmp(line, "ss", 5))
		ss(a, b);
	else
		exit_fun();
}

int	check_sort(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
		{
			if (stack->index < stack->next->index)
				stack = stack->next;
			else
			{
				write(1, "KO\n", 3);
				return (1);
			}
		}
		else
		{
			write(1, "OK\n", 3);
			return (0);
		}
	}
	write(1, "OK\n", 3);
	return (0);
}

void	exit_fun(void)
{
	write(1, "Error\n", 7);
	exit (1);
}
