#include "checker.h"

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = stack_last(*lst);
		(last)->next = new;
	}
}

void	stack_add_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	first = new;
	first->next = *lst;
	*lst = first;
}

t_stack	*stack_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*stack_new(long long content)
{
	t_stack		*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->index = 1;
	new->actions = 0;
	new->next = NULL;
	return (new);
}

int	stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
