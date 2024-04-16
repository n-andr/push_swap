#include "push_swap.h"

void	zeroing_moves(t_stack *b)
{
	while (b)
	{
		b->moves = 0;
		b->moves_in_a = 0;
		b->moves_in_b = 0;
		b = b->next;
	}
}

t_stack *find_least_moves(t_stack *stack)
{
	t_stack *b_tmp;

	b_tmp = stack;
	while (stack)
	{
		if (stack->moves < b_tmp->moves)
			b_tmp = stack;
		stack = stack->next;
	}
	return(b_tmp);
}

void	do_rr(t_stack **a, t_stack **b, int moves_in_a, int moves_in_b)
{
	while (moves_in_a > 0 && moves_in_b > 0)
	{
		rr(a,b);
		moves_in_a --;
		moves_in_b --;
	}
	while (moves_in_a > 0)
	{
		ra(a);
		moves_in_a --;
	}
	while (moves_in_b > 0)
	{
		rb(b);
		moves_in_b --;
	}
}
void	do_rrr(t_stack **a, t_stack **b, int moves_in_a, int moves_in_b)
{
	moves_in_a = ft_lstsize(*a) - moves_in_a;
	moves_in_b = ft_lstsize(*b) - moves_in_b;
	while (moves_in_a > 0 && moves_in_b > 0)
	{
		rrr(a,b);
		moves_in_a --;
		moves_in_b --;
	}
	while (moves_in_a > 0)
	{
		rra(a);
		moves_in_a --;
	}
	while (moves_in_b > 0)
	{
		rrb(b);
		moves_in_b --;
	}
}

void	rotate_a(t_stack **a, int moves_in_a)
{
	if (moves_in_a > 0 && ft_lstsize(*a) / 2 < moves_in_a)
	{
		moves_in_a = ft_lstsize(*a) - moves_in_a;
		while (moves_in_a > 0)
		{
			rra(a);
			moves_in_a --;
		}
	}
	else
	{
		while (moves_in_a > 0)
		{
			ra(a);
			moves_in_a --;
		}
	}
}

void	rotate_b(t_stack **b, int moves_in_b)
{
	if (moves_in_b > 0 && ft_lstsize(*b) / 2 < moves_in_b)
	{
		moves_in_b = ft_lstsize(*b) - moves_in_b;
		while (moves_in_b > 0)
		{
			rrb(b);
			moves_in_b --;
		}
	}
	else
	{
		while (moves_in_b > 0)
		{
			rb(b);
			moves_in_b --;
		}
	}
}

void	move_least_moves(t_stack **a, t_stack **b)
{
	t_stack	*b_tmp;
	int	moves_in_a;
	int	moves_in_b;

	b_tmp = find_least_moves(*b);
	moves_in_a = b_tmp->moves_in_a;
	moves_in_b = b_tmp->moves_in_b;
	if (ft_lstsize(*a) / 2 >= moves_in_a && ft_lstsize(*b) / 2 >= moves_in_b)
		do_rr(a, b, moves_in_a, moves_in_b);
	else if (ft_lstsize(*a) / 2 < moves_in_a && ft_lstsize(*b) / 2 < moves_in_b)
		do_rrr(a, b, moves_in_a, moves_in_b);
	else
	{
		if (moves_in_a > 0)
			rotate_a(a, moves_in_a);
		if (moves_in_b > 0)
			rotate_b(b, moves_in_b);
	}
}



