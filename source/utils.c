#include "push_swap.h"

int	check_sort(t_stack *stack)
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

void	exit_fun(void)
{
	write(1, "Error\n", 7);
	exit (1);
}

int	ft_abs(int	i)
{
	if (i < 0)
		i = -i;
	return (i);
}
