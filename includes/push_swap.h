#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	pa(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_a, t_list *stack_b);
void	rra(t_list *stack);
void	rrb(t_list *stack);
void	rrr(t_list *stack_a, t_list *stack_b);
void	ra(t_list *stack);
void	rb(t_list *stack);
void	rr(t_list *stack_a, t_list *stack_b);
void	sa(t_list *stack);
void	sb(t_list *stack);
void	ss(t_list *stack_a, t_list *stack_b);

t_list	*pars(char **argv);
int		check_valid(char **argv);
void	create_stack(char **a, t_list **stack_a);
int		check_list(t_list *stack_a);
void	exit_fun();
void	cs_2d_arr(char **s, int count);

#endif