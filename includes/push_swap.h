#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
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
void	make_index(t_stack *stack_a);

void	exit_fun();
void	cs_2d_arr(char **s, int count);
void	stack_add_back(t_stack **lst, t_stack *new);
void	stack_add_front(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *lst);
t_stack	*stack_new(int content);
int		stack_size(t_stack *lst);
void	print_stack(t_stack *stck);

void	sort_3numbers(t_stack **stack_a);
void	sort_5numbers(t_stack **stack_a, t_stack **stack_b);
void	sort_numbers(t_stack **stack_a, t_stack **stack_b);
void	do_action(t_stack **stack_a, t_stack **stack_b);
void	do_action_part2(t_stack **stack_a, t_stack **stack_b, int code, int action);
int	find_min_action(t_stack *b, int	*code);
void	free_all_action(t_stack *a, t_stack *b);
void	magic(t_stack *a, t_stack *b);
void	angel_dust(t_stack *a, t_stack *b, int i);
void	check_dubl(t_stack *a, t_stack *b);


#endif