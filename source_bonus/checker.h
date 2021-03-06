#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

typedef struct s_stack
{
	long long		content;
	int				index;
	struct s_stack	*next;
	int				moves_in_a;
	int				moves_in_b;
	int				actions;

}					t_stack;

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	all_command(char *line, t_stack **a, t_stack **b);

void	pars(char **argv, t_stack **stack_a);
int		check_valid(char **argv);
void	create_stack(char **a, t_stack **stack_a);
int		check_list(t_stack *stack_a);
int		check_sort(t_stack *stack, t_stack *stack_b);
void	cs_2d_arr(char **s, int count);
void	exit_fun(void);

void	stack_add_back(t_stack **lst, t_stack *new);
void	stack_add_front(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *lst);
t_stack	*stack_new(long long content);
int		stack_size(t_stack *lst);

#endif