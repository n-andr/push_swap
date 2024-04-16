#include "push_swap.h"

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
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

void	rb(t_stack **b)
{
	t_stack	*last;
	t_stack	*first;

	if (*b == NULL || (*b)->next == NULL)
		return ;
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

void	rrb(t_stack **b)
{
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
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
