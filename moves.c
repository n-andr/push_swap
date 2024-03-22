#include "push_swap.h"

// moves
//
void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return;
	tmp = *a;
	*a = (*a)->next;
	if ((*a)->next != NULL)
		(*a)->next->previous = tmp;
	(*a)->previous = NULL;
	tmp->previous = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return;
	tmp = *b;
	*b = (*b)->next;
	if ((*b)->next != NULL)
		(*b)->next->previous = tmp;
	(*b)->previous = NULL;
	tmp->previous = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
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
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return;
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
		return;
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

void	ra(t_stack **a)
{
	t_stack	*last;
	t_stack *first;

	if (*a == NULL || (*a)->next == NULL)
		return;
	last = *a;
	while (last->next)
		last = last->next;
	first = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*last;
	t_stack *first;

	if (*b == NULL || (*b)->next == NULL)
		return;
	last = *b;
	while (last->next)
		last = last->next;
	first = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack *first;

	if (*a == NULL || (*a)->next == NULL)
	{
		rb(b);
		return;
	}
	if (*b == NULL || (*b)->next == NULL)
	{
		ra(a);
		return;
	}
	last = *a;
	while (last->next)
		last = last->next;
	first = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;

	last = *b;
	while (last->next)
		last = last->next;
	first = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	write(1, "rr\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*last;
	if (*a == NULL || (*a)->next == NULL)
		return;
	last = *a;
	while (last->next)
		last = last->next;
	last->previous->next = NULL;
	(*a)->previous = last;
	last->next = (*a);
	last->previous = NULL;
	*a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return;
	last = *b;
	while (last->next)
		last = last->next;
	last->previous->next = NULL;
	(*b)->previous = last;
	last->next = (*b);
	last->previous = NULL;
	*b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		{
			rrb(b);
			return;
		}
	if (*b == NULL || (*b)->next == NULL)
		{
			rra(a);
			return;
		}
	last = *a;
	while (last->next)
		last = last->next;
	last->previous->next = NULL;
	(*a)->previous = last;
	last->next = (*a);
	last->previous = NULL;
	*a = last;

	last = *b;
	while (last->next)
		last = last->next;
	last->previous->next = NULL;
	(*b)->previous = last;
	last->next = (*b);
	last->previous = NULL;
	*b = last;
	write(1, "rrr\n", 4);
}
//
// end moves