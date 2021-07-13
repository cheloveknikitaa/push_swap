#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

void	pars(char **argv, t_stack **stack_a);
int		check_valid(char **argv);
void	create_stack(char **a, t_stack **stack_a);
int		check_list(t_stack *stack_a);
int		check_sort(t_stack *stack);
void	cs_2d_arr(char **s, int count);
void	exit_fun(void);

void	stack_add_back(t_stack **lst, t_stack *new);
void	stack_add_front(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *lst);
t_stack	*stack_new(long long content);
t_stack	*stack_copy(t_stack *copy, t_stack *original);
int		stack_size(t_stack *lst);
void	print_stack(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b, t_stack *target);

void	sort_3numbers(t_stack **stack_a);
void	sort_4numbers(t_stack **stack_a, t_stack **stack_b);
void	sort_5numbers(t_stack **stack_a, t_stack **stack_b);
void	sort_numbers(t_stack **stack_a, t_stack **stack_b);
void	do_action(t_stack **stack_a, t_stack **stack_b, t_stack *guide);
void	moves_in_ab(t_stack **stack_a, t_stack **stack_b, t_stack *guide);
void	moves_in_b(t_stack **stack_b, t_stack *guide);
void	moves_in_a(t_stack **stack_a, t_stack *guide);
void	free_all_action(t_stack *a, t_stack *b, t_stack *target);

t_stack	*find_value_in_b(t_stack *a, t_stack *b);
void	find_value_in_a(t_stack *a, t_stack *b, int i);
void	check_value(t_stack *a, t_stack *b, int i, int j);
void	check_value2(t_stack *a, t_stack *b, int i, int j);
int		find_need_index(t_stack *stack, int i);
void	final(t_stack **stack_a, int max_index);
int		now_sort(t_stack *a);
int		ft_abs(int	i);

#endif