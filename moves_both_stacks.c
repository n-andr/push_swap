#include "push_swap.h"

/*
Functions:

pb (push b): 
	Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
pa (push a): 
	Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
rr : 
	ra and rb at the same time.
null_check_rr :
	helper function to rr (cuz norminette)
rrr : 
	rra and rrb at the same time.
ss :
	sa and sb at the same time. 
	(is not used)
*/

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->previous = NULL;
	temp->next = *b;
	if ((*b) != NULL)
		(*b)->previous = temp;
	*b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->previous = NULL;
	temp->next = *a;
	if ((*a) != NULL)
		(*a)->previous = temp;
	*a = temp;
	write(1, "pa\n", 3);
}

void	null_check_rr(t_stack **a, t_stack **b)
{
	if (*a == NULL || (*a)->next == NULL)
	{
		rb(b);
		return ;
	}
	if (*b == NULL || (*b)->next == NULL)
	{
		ra(a);
		return ;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*first;

	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
	{
		null_check_rr(a, b);
		return ;
	}
	last = ft_lstlast(*a);
	first = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	last = ft_lstlast(*b);
	first = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
	{
		rrb(b);
		return ;
	}
	if (*b == NULL || (*b)->next == NULL)
	{
		rra(a);
		return ;
	}
	last = ft_lstlast(*a);
	last->previous->next = NULL;
	(*a)->previous = last;
	last->next = (*a);
	last->previous = NULL;
	*a = last;
	last = ft_lstlast(*b);
	last->previous->next = NULL;
	(*b)->previous = last;
	last->next = (*b);
	last->previous = NULL;
	*b = last;
	write(1, "rrr\n", 4);
}

/*void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		{
			sb(b);
			return;
		}
	if (*b == NULL || (*b)->next == NULL)
		{
			sa(a);
			return;
		}
	tmp = *a;
	*a = (*a)->next;
	(*a)->next->previous = tmp;
	(*a)->previous = NULL;
	tmp->previous = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;

	tmp = *b;
	*b = (*b)->next;
	(*b)->next->previous = tmp;
	(*b)->previous = NULL;
	tmp->previous = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "ss\n", 3);
}*/